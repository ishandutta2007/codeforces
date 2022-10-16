#include<iostream>
using namespace std;
int main()
{
	int x[26]={0},tt=0;
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
		x[s[i]-97]=1;
	for(int i=0;i<26;i++)
		tt+=x[i];
	if(tt%2==1)
		cout<<"IGNORE HIM!";
	else
		cout<<"CHAT WITH HER!"; 
}