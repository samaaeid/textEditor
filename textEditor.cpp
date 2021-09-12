#include <iostream>
#include <string>
#include <fstream>
#include <stack>
using namespace std;

stack <string> arr[5];

void insert_line(){
cout<<"enter the number of line :";
int num;
string text;
cin>>num;
cout<<"enter the text :";
cin>>text;
arr[num-1].push(text);

}

void delete_line(){
cout<<"enter the number of line you wanted to delete it :";
int num_d;
cin>>num_d;
while(arr[num_d-1].size()){
    arr[num_d-1].pop();
}
}
void delete_fromline(){
    cout<<"enter the number of line you wanted to delete it :";
int num_d;
cin>>num_d;
arr[num_d-1].pop();
}

void PrintStack(stack<string> s)
{
    if (s.empty())
        return;

    string x = s.top();
    s.pop();
    PrintStack(s);
    cout << x << " ";
    s.push(x);
}

void copy_stack(stack<string> &s1, stack<string> &s2)
{
    stack<string>tmp;



    while(!s1.empty()){

        tmp.push(s1.top());  //s1--->tmp
        s1.pop();
    }

    while(!tmp.empty()){

        s1.push(tmp.top());  //tmp -->s1,s2
        s2.push(tmp.top());
        tmp.pop();

    }

}


void print_arr(){
for(int i=0 ; i<5 ; i++){
        PrintStack(arr[i]);
        cout<<"\n";
}}

void move_text(){
cout<<"move from :";
int num1,num2;
cin>>num1;
cout<<"move to :";
cin>>num2;
copy_stack(arr[num1-1],arr[num2-1]);

while(arr[num1-1].size()){
    arr[num1-1].pop();
}
}

void replace_text(){
cout<<"replace text from line :";
int num1; string text;
cin>>num1;
cout<<"please enter the text :";
cin>>text;
while(arr[num1-1].size()){
    arr[num1-1].pop();
}
arr[num1-1].push(text);

}
void copy_text(){
cout<<"copy from :";
int num1,num2;
cin>>num1;
cout<<"paste to :";
cin>>num2;
copy_stack(arr[num1-1],arr[num2-1]);

}





int main()
{
    stack<char> s1;
     while(1){
            cout<<"====TEXT EDITOR===="<<endl;

    cout<<"\nPlease choose what you want to do";

    cout<<"\n1.Insert text into Line N";
    cout<<"\n2.Delete from line N";
    cout<<"\n3.Move line N into line M"; // from num to num
    cout<<"\n4.Replace text in Line N";  // num line + text
    cout<<"\n5.copy line n to line m";  //copy paste
    cout<<"\n6.Print all";
    cout<<"\n7.Delete line N";
    cout<<"\n8.exit";


        cout<<"\n\nEnter your choice..";

        int choice;
        cin>>choice;
        switch(choice){
      case 1:
          insert_line();
        break;
      case 2:
          delete_fromline();
        break;
      case 3:
          move_text();
        break;
      case 4:
         replace_text();
         break;

      case 5:
          copy_text();
        break;
      case 6:
          print_arr();
        break;
      case 7:
          delete_line();
        break;
      case 8:
        exit(0);

    }


}
	return 0;

}
