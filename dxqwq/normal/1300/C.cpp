#include<bits/stdc++.h>
using namespace std;
int a[100003];
int x[103];
void f(int n)
{
	int i=0;
	while(n)
	{
		if(n&1) x[i]++;
		n>>=1,i++;
	}
}
void ff(int n)
{
	int i=0;
	while(n)
	{
		if(n&1) x[i]--;
		n>>=1,i++;
	}
}
int getnum()
{
	int res=0,now=1;
	for(int i=0; i<32; i++) 
	{
		if(x[i]) res+=now;
		now<<=1;
	}
	return res;
}
int main()
{
	int n,x=0,ans=0,ansi=1;
	scanf("%d",&n);
	for(int i=1; i<=n; i++) scanf("%d",&a[i]),f(a[i]);
	for(int i=1; i<=n; i++) 
	{
		ff(a[i]);
		int t=getnum();
		if((a[i]|t)-t>ans) 
		{
			ans=(a[i]|t)-t;
			ansi=i;
		}
		f(a[i]);
	 } 
	 printf("%d ",a[ansi]);
	for(int i=1; i<=n; i++) if(i!=ansi) printf("%d ",a[i]);
	return 0;
}