#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
int main()
{
	string str;
	cin>>str;
	string ret;
	int last=0;
	for(char i='z';i>='a';i--)
	{
		for(int j=last;j<str.size();j++)
		{
			if(str[j]==i)
			{
				ret+=str[j];
				last=j+1;
			}
		}
	}
	cout<<ret<<endl;
}