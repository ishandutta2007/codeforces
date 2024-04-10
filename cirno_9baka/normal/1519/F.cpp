#include<bits/stdc++.h>
using namespace std;
int n,m,a[7],b[7],c[7][7],i,p[7],j;
int f[7][15625];
struct str{
	int p[7],c;
};
vector<str> g[7];
void dfs(int x,int i,int s,int w)
{
	if(i>m)
	{
		if(s)
			return;
		str tmp;
		memset(tmp.p,0,sizeof(tmp.p));
		int i;
		for(i=1;i<=m;++i)
			tmp.p[i]=p[i];
		tmp.c=w;
		g[x].push_back(tmp);
		return;
	}
	int j;
	p[i]=0;
	dfs(x,i+1,s,w);
	for(j=1;j<=s;++j)
	{
		p[i]=j;
		dfs(x,i+1,s-j,w+c[x][i]);
	}
}
int DP(int i,int e)
{
	if(i>n)
		return 0;
	if(f[i][e]!=-1)
		return f[i][e];
	f[i][e]=1<<30;
	int j,p[7],tp=e;
	for(j=m;j>=1;--j)
	{
		p[j]=tp%5;
		tp/=5;
	}
	for(auto it:g[i])
	{
		int ss=0;
		for(j=1;j<=m;++j)
		{
			if(p[j]+it.p[j]>b[j])
				break;
			ss=ss*5+p[j]+it.p[j];
		}
		if(j>m)
			f[i][e]=min(f[i][e],DP(i+1,ss)+it.c);
	}
	return f[i][e];
}
int main()
{
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for(i=1;i<=m;++i)
		scanf("%d",&b[i]);
	for(i=1;i<=n;++i)
		for(j=1;j<=m;++j)
			scanf("%d",&c[i][j]);
	for(i=1;i<=n;++i)
		dfs(i,1,a[i],0);
	memset(f,-1,sizeof(f));
	cout<<(DP(1,0)<(1<<30)?DP(1,0):-1);
}