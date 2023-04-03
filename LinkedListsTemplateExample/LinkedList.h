#include <iostream> 
using namespace std;

template <class T>
class LinkedList
{
protected:
    // Declare a class for the list node
    class ListNode
    {
    public:
       T value;
       ListNode *next;
       ListNode(T value1, ListNode *next1 = nullptr)
       {
          this->value = value1;
          this->next = next1;
       }
    };
    ListNode *head;                   // List head pointer
public:
    LinkedList() { this->head = nullptr;  }    //Constructor
    ~LinkedList();                    // Destructor
    void add(T value);
    void remove(T value);
    void displayList() const;
};

//*****************************************************
// add adds a new element to the end of the list.     *
//*****************************************************
template <class T4>
void LinkedList<T4>::add(T4 value)
{
   if (this->head == nullptr)
       this->head = new ListNode(value);
   else
     {
       // The list is not empty
       // Use nodePtr to traverse the list
       ListNode *nodePtr = this->head;
       while (nodePtr->next != nullptr)
          nodePtr = nodePtr->next;

       // nodePtr->next is nullptr so nodePtr points to the last node
       // Create a new node and put it after the last node
       nodePtr->next = new ListNode(value);
     }
}

//**********************************************
// Removes a number from a list. The function  *
// does not assume that the list is sorted.    *
//**********************************************
template <class T3>
void LinkedList<T3>::remove(T3 value)
{
  ListNode *nodePtr=nullptr, *previousNodePtr=nullptr;

   // If the list is empty, do nothing
   if (!this->head)  return;

   // Determine if the first node is the one to delete
   if (this->head->value == value)
   {
     nodePtr = this->head;
     this->head = this->head->next;
     delete nodePtr;
   }
   else
   {
     // Initialize nodePtr to the head of the list
     nodePtr = this->head;

     // Skip nodes whose value member is not num
     while (nodePtr != nullptr && nodePtr->value != value)
     {
        previousNodePtr = nodePtr;
        nodePtr = nodePtr->next;
     }
     // Link the previous node to the node after
     // nodePtr, then delete nodePtr
     if (nodePtr)
     {
        previousNodePtr->next = nodePtr->next;
        delete nodePtr;
        nodePtr->next = nullptr;
        nodePtr = nullptr;
     }
   }
}

//***************************************************
// displayList outputs a sequence of all values     *
// currently stored in the list.                    *
//***************************************************
template <class T2>
void LinkedList<T2>::displayList() const
{
   ListNode *nodePtr = this->head;   // Start at head of list
   while (nodePtr)
   {
      // Print the value in the current node
      cout << nodePtr->value << "    ";
      // Move on to the next node
      nodePtr = nodePtr->next;
   }
}

//******************************************************
// Destructor deallocates the memory used by the list. *
//******************************************************
template <class T1>
LinkedList<T1>::~LinkedList()
{
  ListNode *nodePtr = this->head;  // Start at head of list
  while (nodePtr != nullptr)
  {
      // garbage keeps track of node to be deleted
      ListNode *garbage = nodePtr;
      // Move on to the next node, if any
      nodePtr = nodePtr->next;
      // Delete the "garbage" node
      delete garbage;
  }
}
