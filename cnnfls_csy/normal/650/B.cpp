#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#define sqr(x) (x)*(x)
using namespace std;
int n,m,i,j,x,y,t,l,r,ans;
char ph[1000005];
int main()
{
	cin>>n>>x>>y>>m;
	for (i=1;i<=n;i++)
	{
		cin>>ph[i];
	}
	l=1;r=1;t=1+y*(ph[1]=='w');
	if (t>m)
	{
		cout<<0;
		return 0;
	}
	while (t+x+1+y*(ph[r+1]=='w')<=m&&r<=n)
	{
		t+=x+1+y*(ph[r+1]=='w');
		r++;
	}
	ans=max(ans,r-l+1);
	t+=r*x+1+y*(ph[n]=='w');
	for (l=n;l;l--)
	{
		while (t>m&&r>1)
		{
			t-=1+2*x+y*(ph[r]=='w');
			r--;
		}
		if (t>m) break;
		ans=max(ans,n-l+1+r);
		t+=x+1+y*(ph[l-1]=='w');
	}
	l=n+1;r=1;t=1+y*(ph[1]=='w');
	if (t>m)
	{
		cout<<0;
		return 0;
	}
	while (t+x+1+y*(ph[l-1]=='w')<=m&&l>=0)
	{
		t+=x+1+y*(ph[l-1]=='w');
		l--;
	}
	ans=max(ans,r+n-l+1);
	t+=(n-l+2)*x+1+y*(ph[2]=='w');
	for (r=2;r<=n;r++)
	{
		while (t>m&&l<n)
		{
			t-=1+2*x+y*(ph[l]=='w');
			l++;
		}
		if (t>m) break;
		ans=max(ans,n-l+1+r);
		t+=x+1+y*(ph[r+1]=='w');
	}
	cout<<min(n,ans);
	return 0;
}