//#include<bits/stdc++.h>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<map>
#include<queue>
#include<set>
#include<stack>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
/*
int read()
{
	int v = 0, f = 0;
	char c =getchar();
	while( c < 48 || 57 < c ){
		if(c=='-') f = -1;
		c = getchar();
	}
	while(48 <= c && c <= 57) 
		v = v*10+c-48, c = getchar();
	return v*f;
}
*/
ll n,m,a[100009],sum,ans;

int main()
{
	sum=0;
	ans=0;
	scanf("%I64d %I64d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%I64d",&a[i]);
		sum+=a[i];
	}
	int t;
	for(int i=0;i<m;i++)
	{
		scanf("%d",&t);
		sum-=a[t];
		ans=ans+a[t]*sum;
		a[t]=0;
	}
	a[n+1]=a[1];
	for(int i=2;i<=n+1;i++)
	{
		ans=ans+a[i]*a[i-1];
	}
	printf("%I64d\n",ans);
	return 0;
}