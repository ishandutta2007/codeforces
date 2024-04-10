#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
using namespace std;
string st,st1,st2;
int n,m,i,j,s,l,r,mid,a[200005],b[200005];
bool ch(int x)
{
	int i,s=0;
	for (i=1;i<=n;i++) b[i]=0;
	for (i=1;i<=x;i++) b[a[i]]=1;
	for (i=1;i<=n;i++)
	if((!b[i])&&st1[i]==st2[s])
	{
	    s++;
	    if (s==st2.length()) return 1;
	}
	return 0; 
}
int main()
{
	cin>>st1>>st2;
	st1=" "+st1;
	n=st1.length()-1;
	for (i=1;i<=n;i++) scanf("%d",&a[i]);
	l=0;r=n;
	while (l<r)
	{
		mid=(l+r+1)>>1;
		if (ch(mid))
		l=mid; 
		else r=mid-1;
	}
	cout<<l;
	return 0;
}