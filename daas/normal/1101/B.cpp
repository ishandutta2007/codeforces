#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
using namespace std;
string s;
int len,l=-1,r=-1,bj;
int main()
{
	cin>>s;
	len=s.length();
	for(register int i=0;i<len;++i)
		if(s[i]=='[')
		{
			l=i;
			break;
		}
	if(l==-1)
	{
		puts("-1");
		return 0;
	}
	bj=l;
	for(register int i=l+1;i<len;++i)
		if(s[i]==':')
		{
			l=i;
			break;
		}
	if(l==bj)
	{
		puts("-1");
		return 0;
	}
	for(register int i=len-1;i>=0;--i)
		if(s[i]==']')
		{
			r=i;
			break;
		}
	if(r==-1)
	{
		puts("-1");
		return 0;
	}
	bj=r;
	for(register int i=r-1;i>=0;--i)
		if(s[i]==':')
		{
			r=i;
			break;
		}
	if(r==bj)
	{
		puts("-1");
		return 0;
	}
	if(l>=r)
	{
		puts("-1");
		return 0;
	}
	int ans=4;
	for(register int i=l+1;i<r;++i)
		if(s[i]=='|')
			++ans;
	printf("%d\n",ans);
	return 0;
}