#include<iostream>
using namespace std;
char a,b;
int main()
{
	cin>>a>>b;
	if((a=='h'||a=='a')&&(b=='1'||b=='8')) cout<<3;
	else if(a=='h'||a=='a'||b=='1'||b=='8') cout<<5;
	else cout<<8;
	return 0;
}