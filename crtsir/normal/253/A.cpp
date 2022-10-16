#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int a,b;
	cin>>a>>b;
	if(a==b)
		for(int i=0;i<a;++i)
			cout<<"GB";
	else if(a>b)
	{
		for(int i=0;i<b;++i)
			cout<<"BG";
		for(int i=0;i<a-b;++i)
			cout<<"B";
	}
	else
	{
		for(int i=0;i<a;++i)
			cout<<"GB";
		for(int i=0;i<b-a;++i)
			cout<<"G";
	}
}