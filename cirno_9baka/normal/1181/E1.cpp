#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<stdlib.h>
#include<math.h>
#include<set>
#include<map>
#include<vector>
using namespace std;
const long long M=1000000007ll;
int n,k,i,s[200005];
struct str{
	int a,b,c,d;
}p[200005];
bool cmp1(str a,str b)
{
	return a.c<b.c;
}
bool cmp2(str a,str b)
{
	return a.d<b.d;
}
void dfs(str *x,int n)
{
	int i,j;
	if(n==1)
		return;
	sort(x+1,x+1+n,cmp1);
	s[n+1]=1<<30;
	for(i=n;i>=1;i--)
		s[i]=min(s[i+1],x[i].a);
	for(i=1;i<n;i++)
		if(x[i].c<=s[i+1])
			break;
	if(i<n)
	{
		str tmp[1005];
		for(j=1;j<=i;j++)
			tmp[j]=x[j];
		dfs(tmp,i);
		for(j=i+1;j<=n;j++)
			tmp[j-i]=x[j];
		dfs(tmp,n-i);
		return;
	}
	sort(x+1,x+1+n,cmp2);
	s[n+1]=1<<30;
	for(i=n;i>=1;i--)
		s[i]=min(s[i+1],x[i].b);
	for(i=1;i<n;i++)
		if(x[i].d<=s[i+1])
			break;
	if(i<n)
	{
		str tmp[1005];
		for(j=1;j<=i;j++)
			tmp[j]=x[j];
		dfs(tmp,i);
		for(j=i+1;j<=n;j++)
			tmp[j-i]=x[j];
		dfs(tmp,n-i);
		return;
	}
	printf("NO");
	exit(0);
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d %d %d %d",&p[i].a,&p[i].b,&p[i].c,&p[i].d);
	dfs(p,n);
	printf("YES");
}