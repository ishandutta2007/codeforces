#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
int rev(int a)
{
	int ret=0;
	for(int i=0;i<8;i++)
	{
		ret*=2;
		ret+=(a%2);
		a/=2;
	}
	return ret;
}
int main()
{
	string str;
	for(;;)
	{
		char zan;
		scanf("%c",&zan);
		if(zan=='\n')
		{
			break;
		}
		str.push_back(zan);
	}
	int now=0;
	for(int i=0;i<str.size();i++)
	{
		printf("%d\n",(now+256-rev(str[i]))%256);
		now=rev(str[i]);
	}
}