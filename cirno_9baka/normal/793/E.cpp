#include<bits/stdc++.h>
using namespace std;
const int N=5005;
int n,m,a,b,c,d,fa[N],head[N],Next[N],adj[N],siz[N],i,vis[N],k,j;
int p[5];
vector<int> A,B,C;
bitset<N> f,g;
void Push(int u,int v)
{
	Next[++k]=head[u];
	head[u]=k;
	adj[k]=v;
}
void dfs(int i)
{
	siz[i]=(head[i]==0);
	int j;
	for(j=head[i];j;j=Next[j])
	{
		dfs(adj[j]);
		siz[i]+=siz[adj[j]];
	}
}
void Judge(int a,int b)
{
	if(a<=siz[1]/2-1&&b<=siz[1]/2-1)
		if(f[siz[1]/2-1-a]&&g[siz[1]/2-1-b])
		{
			puts("YES");
			exit(0);
		}
}
int main()
{
	scanf("%d",&n);
	scanf("%d %d %d %d",&a,&b,&c,&d);
	for(i=2;i<=n;++i)
	{
		scanf("%d",&fa[i]);
		Push(fa[i],i);
	}
	dfs(1);
	if(siz[1]%2!=0)
	{
		puts("NO");
		return 0;
	}
	int las=0,sa=0,sb=0;
	for(i=a;i!=1;i=fa[i])
	{
		vis[i]=1;
		for(j=head[i];j;j=Next[j])
			if(adj[j]!=fa[i]&&adj[j]!=las)
				A.push_back(siz[adj[j]]);
		las=i;
	}
	for(i=b;i!=1;i=fa[i])
	{
		vis[i]=2;
		for(j=head[i];j;j=Next[j])
			if(adj[j]!=fa[i]&&adj[j]!=las)
				A.push_back(siz[adj[j]]);
		las=i;
	}
	for(i=c;i!=1;i=fa[i])
	{
		vis[i]=3;
		for(j=head[i];j;j=Next[j])
			if(adj[j]!=fa[i]&&adj[j]!=las)
				B.push_back(siz[adj[j]]);
		las=i;
	}
	for(i=d;i!=1;i=fa[i])
	{
		vis[i]=4;
		for(j=head[i];j;j=Next[j])
			if(adj[j]!=fa[i]&&adj[j]!=las)
				B.push_back(siz[adj[j]]);
		las=i;
	}
	for(i=head[1];i;i=Next[i])
		if(vis[adj[i]]==0)
			C.push_back(siz[adj[i]]);
		else
			p[vis[adj[i]]]=siz[adj[i]];
	g[0]=f[0]=1;
	for(auto it:A)
		f=(f<<it)|f;
	for(auto it:C)
		f=(f<<it)|f;
	for(auto it:B)
		g=(g<<it)|g;
	for(auto it:C)
		g=(g<<it)|g;
	Judge(p[1],p[3]);
	Judge(p[2],p[3]);
	Judge(p[1],p[4]);
	Judge(p[2],p[4]);
	puts("NO");
}