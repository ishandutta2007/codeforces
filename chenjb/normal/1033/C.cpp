#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <cmath>
#include <set>
#include <vector>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;++i)
int a[110000];
int f[110000];
int n;
bool dfs(int x)
{
	if (f[x]!=-1)return f[x];
	for(int i=x+a[x];i<=n;i+=a[x])
		if (a[i]>a[x])if(dfs(i)==0)return f[x]=1;
	for(int i=x-a[x];i>=1;i-=a[x])
		if (a[i]>a[x])if (dfs(i)==0)return f[x]=1;
	return f[x]=0;
}
int main()
{
	cin>>n;
	rep(i,n)f[i]=-1;
	rep(i,n)scanf("%d",&a[i]);
	rep(i,n)if (dfs(i)==1)putchar('A'); else putchar('B'); puts("");
}