#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int a;
	scanf("%d",&a);
	for(int i=0;i<s.size();i++)
	{
		if('A'<=s[i]&&s[i]<='Z')
		{
			s[i]+='a'-'A';
		}
		if(s[i]<'a'+a)
		{
			s[i]+='A'-'a';
		}
	}
	cout<<s<<endl;
}