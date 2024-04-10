#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;
string str;
int toint(string hoge)
{
	if(hoge[0]=='0'&&hoge.size()!=1)
	{
		return -100000000;
	}
	if(hoge=="0")
	{
		return 0;
	}
	if(hoge.size()>6&&hoge!="1000000")
	{
		return -100000000;
	}
	int ret=0;
	for(int i=0;i<hoge.size();i++)
	{
		ret*=10;
		ret+=hoge[i]-'0';
	}
	return ret;
}
string cut(int a,int b)
{
	string ret;
	for(int i=a;i<=b;i++)
	{
		ret+=str[i];
	}
	return ret;
}
int main()
{
	cin>>str;
	int max=-1;
	for(int i=0;i<str.size();i++)
	{
		for(int j=i+1;j<str.size()-1;j++)
		{
			int sum=toint(cut(0,i))+toint(cut(i+1,j))+toint(cut(j+1,str.size()-1));
			if(max<sum)
			{
				max=sum;
			}
		}
	}
	printf("%d\n",max);
}