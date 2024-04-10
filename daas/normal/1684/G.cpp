#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<vector>
#define ll long long
using namespace std;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int n,m,pre[1010],vis[1010],tim,st;
ll a[1010];
int dfs(int x)
{
	for(int i=1;i<st;++i) if(vis[i]!=tim && a[x]%a[i]==0 && a[i]+2*a[x]<=m)
	{
		vis[i]=tim;
		if(!pre[i] || dfs(pre[i]))
		{
			pre[i]=x;
			return 1;
		}
	}
	return 0;
}
int main()
{
	n=read(),m=read();
	for(int i=1;i<=n;++i) a[i]=read();
	sort(a+1,a+n+1);
	st=1; while(st<=n && 3*a[st]<=m) ++st;
	for(int i=st;i<=n;++i)
	{
		++tim;
		if(!dfs(i)) {puts("-1");return 0;}
	}
	printf("%d\n",st-1);
	for(int i=1;i<st;++i)
		if(pre[i]) printf("%lld %lld\n",2*a[pre[i]]+a[i],a[pre[i]]+a[i]);
		else printf("%lld %lld\n",3*a[i],2*a[i]);
	return 0;
}