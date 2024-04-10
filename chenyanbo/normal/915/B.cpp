#include<bits/stdc++.h>
using namespace std;

inline int read()
{
	int ret=0; char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	return ret;
}
int n,pos,l,r;
int main()
{
	n=read(); //_
	pos=read();
	l=read();
	r=read();
	
	if(l==1&&r==n)
	{
		puts("0");
		exit(0);
	}
	if(l==1)
	{
		printf("%d\n",abs(r-pos)+1);
		return 0;
	}
	
	if(r==n)
	{
		printf("%d\n",abs(pos-l)+1);
		return 0;//(x) ab (-(x))  //f  abs
	}
	
	if(pos<=l)
	{
		printf("%d\n",r-pos+2);
		return 0;
	}
	if(pos>=r)
	{
		printf("%d\n",pos-l+2);
		return 0;
	}
	printf("%d\n",min(pos-l,r-pos)+r-l+2);
	exit(0);
}