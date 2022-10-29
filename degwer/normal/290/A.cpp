#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;
string dat[40]=
{"Washington","Adams","Jefferson","Madison","Monroe","Adams","Jackson","Van Buren","Harrison","Tyler",
"Polk","Taylor","Fillmore","Pierce","Buchanan","Lincoln","Johnson","Grant","Hayes","Garfield",
"Arthur","Cleveland","Harrison","Cleveland","McKinley","Roosevelt","Taft","Wilson","Harding","Coolidge",
"Hoover","Roosevelt","Truman","Eisenhower","Kennedy","Johnson","Nixon","Ford","Carter","Reagan"};
int main()
{
	int a;
	scanf("%d",&a);
	cout<<dat[a-1]<<endl;
}