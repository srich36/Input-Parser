//Sean Rich V1 3-31-18
//Functionality: Write an input Parser to return a Linked List of tokens given a specified delimiter
//Classes Needed: Input Class
//                Linked List Class
//Structs Needed: Node
//Constraints: Linked list and Nodes only handle integers, to change this can just change the data type
//Process Flow:
//Create an input object and instantiate it with your character delimeter of choice
//Pass the input object the input string in the function call to parseTokens. This will return the head pointer
//To a linked list of all the tokens parsed from the input string
//
//TO DO
//
//Figure out when to implement UserInput Function to delete the token linked list

#include <iostream>
#include <string>
using namespace std;

struct Node{
    string token;
    Node *next;
    Node *prev;
};

class LinkedList{
    //Functions needed: Print, push, pop
private:
    Node *head;
public:
    LinkedList(){
        head = nullptr;
    }

    void print(){
        Node *tmpptr = head;                  //temp pointer to traverse the linked list
        cout << "Printing the linked list: \n";
        while(tmpptr != nullptr){                   //traversing the linked list with tmpptr
            cout << tmpptr->token << endl;
            tmpptr = tmpptr->next;
        }
    }

    void addBack(string data){
        Node *tmpptr = new Node();
        if(head == nullptr){
            head = tmpptr;
            tmpptr -> next = nullptr;
            tmpptr->prev = nullptr;
            tmpptr->token = data;
        }
        else{
            tmpptr = head;
            while(tmpptr->next != nullptr){
                tmpptr = tmpptr->next;
            }
            Node *tmpptr2 = new Node();
            tmpptr->next = tmpptr2;
            tmpptr2->prev = tmpptr;
            tmpptr2->token = data;
            tmpptr2->next = nullptr;
        }
    }

    Node* retHead(){
        return head;
    }

    void deleteLinkedList(){
        if(head == nullptr){                                                       //covers the case where the list is empty
            return;
        }
        if(head->next == nullptr){                                                 //covers the case where there is only one element
            delete head;
            head = nullptr;
            return;
        }

        else{                                                                      //covers the rest of the cases (n>1)
            Node *tmpptr = head;
            while(tmpptr->next->next != nullptr){
                tmpptr = tmpptr->next;
            }
            delete tmpptr->next;                                                   //free dynamically allocated memory
            tmpptr->next = nullptr;

        }
    }
};

class UserInput{

    //functions needed: printTokens, parseTokens, addToken, retTokenLinkedList;
private:

    LinkedList tokens;
    char delimiter;
    string unparsedInput;

public:

    UserInput(char delim = ','){
        delimiter = delim;
    }

    void setDelim(char delim){
        delimiter = delim;
    }

    Node* parseTokens(string input){
        int length = input.length();
        unparsedInput = input;
        string token = "";
        for(int i = 0; i < length; i++){
            if(input[i] == delimiter){
                tokens.addBack(token);
                token = "";
            }

            else{
                token += input[i];
            }
        }
        tokens.addBack(token); //add the final token
        printTokens();
        return tokens.retHead();
    }

    void printTokens(){
        tokens.print();
    }

    void addToken(string token){
        tokens.addBack(token);
    }

    void deleteTokens(){
        tokens.deleteLinkedList();
    }

    string retUnparsedInput(){
        return unparsedInput;
    }



};


int main() {
    UserInput input(',');
    string tempInput;
    cout << "Enter in the input string.\n";
    getline(cin, tempInput);
    Node* TokenList = input.parseTokens(tempInput);
    return 0;
}