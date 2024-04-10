#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
const int N=1100005,M=1000000007;
int n,m,p,t,i,a[N],b[N],j,head[N],Next[N*2],adj[N*2],num[N*2],d[N],vis[N*2],k;
int f[N],na[N*2],nb[N*2];
int ans[N],sta[N*2],top;
void Push(int u,int v,int w,int a,int b)
{
	Next[++k]=head[u];
	head[u]=k;
	adj[k]=v;
	num[k]=w;
	na[k]=a;
	nb[k]=b;
}
void dfs(int i)
{
	int j;
	for(j=head[i];j;j=head[i]=Next[head[i]])
		if(!vis[j])
		{
			vis[j]=vis[j^1]=1;
			dfs(adj[j]);
			ans[++k]=nb[j];
			ans[++k]=na[j];
			--top;
		}
}
int Find(int x)
{
	return (f[x]!=-1?f[x]=Find(f[x]):x);
}
void uniot(int x,int y)
{
	int u=Find(x),v=Find(y);
	if(u!=v)
		f[u]=v;
}
void Judge(int x)
{
	int i,s=0,pos=0;
	memset(d,0,sizeof(d));
	memset(f,-1,sizeof(f));
	for(i=1;i<=n;++i)
	{
		++d[a[i]&((1<<x)-1)];
		++d[b[i]&((1<<x)-1)];
		uniot(a[i]&((1<<x)-1),b[i]&((1<<x)-1));
	}
	for(i=0;i<(1<<x);++i)
		if(d[i]&&f[i]==-1)
		{
			pos=i;
			++s;
		}
	if(s>=2)
		return;
	s=0;
	for(i=0;i<(1<<x);++i)
		if(d[i]&1)
		{
			++s;
			pos=i;
		}
	if(s>0)
		return;
	k=1;
	for(i=1;i<=n;++i)
	{
		Push(a[i]&((1<<x)-1),b[i]&((1<<x)-1),i,i*2-1,i*2);
		Push(b[i]&((1<<x)-1),a[i]&((1<<x)-1),i,i*2,i*2-1);
	}
	printf("%d\n",x);
	k=0;
	dfs(pos);
	for(i=k;i>=1;--i)
		printf("%d ",ans[i]);
	exit(0);
}
int main()
{
#ifndef ONLINE_JUDGE 
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&n);
	for(i=1;i<=n;++i)
		scanf("%d %d",&a[i],&b[i]);
	for(i=20;i>=0;--i)
		Judge(i);
}