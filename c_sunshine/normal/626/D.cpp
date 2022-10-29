#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long LL;
int n,a[2005];
int f[10005];
LL g[10005],all,ans;
int main()
{
	scanf("%d",&n);
	all=n*(n-1)/2;all=all*all*all;
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++)
		for(int j=i+1;j<=n;j++)
			f[a[j]-a[i]]++;
	for(int i=1;i<5000;i++)
		for(int j=1;i+j<5000;j++)
			g[i+j]+=f[i]*f[j];
	for(int i=1;i<=5000;i++)
		g[i]+=g[i-1];
	for(int i=1;i<n;i++)
		for(int j=i+1;j<=n;j++)
			ans+=g[a[j]-a[i]-1];
	printf("%.14lf\n",(double)ans/all);
	return 0;
}