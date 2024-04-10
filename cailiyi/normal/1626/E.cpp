#include<bits/stdc++.h>
#define N 300000
using namespace std;
int n,c[N+5],sum,cnt,f[N+5],ans[N+5],father[N+5],root;
vector<int> e[N+5];
inline void dfs(int x,int fa)
{
	father[x]=fa,cnt+=c[x];
	if(fa && c[x]) return f[x]=1,void();
	for(int y:e[x]) if(y!=fa)
	{
		dfs(y,x),f[x]+=f[y];
		if(f[x] && !fa) return;
	}
}
inline void dfs2(int x,int fa)
{
	if(ans[x]) return; 
	ans[x]=1;
	for(int y:e[x])
		if(y!=fa) dfs2(y,x);
}
inline void dfs3(int x,int fa)
{
	ans[x]=1;
	for(int y:e[x])
		if(y!=fa) dfs3(y,x);
}
inline bool find()
{
	for(int i=root+1;i<=n;++i) if(c[i] && f[father[i]]>1) return 1;
	return 0;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",c+i),sum+=c[i];
	for(int i=1,u,v;i<n;++i)
	{
		scanf("%d %d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for(int i=1;i<=n;++i)
		if(c[i]) {dfs(root=i,0);break;}
	if(cnt!=sum || find())
	{
		for(int i=1;i<=n;++i) printf("1 ");
		return 0;
	}
	for(int i=root+1;i<=n;++i)
		if(c[i]) dfs2(father[i],father[father[i]]);
	int c;
	for(int y:e[root]) if(f[y]) {c=y;break;}
	int cnt=0,p=0;
	for(int y:e[c]) if(y!=root && f[y]!=0) ++cnt,p=y;
	if(cnt>1)
	{
		for(int i=1;i<=n;++i) printf("1 ");
		return 0;
	}
	dfs3(c,p);
	for(int i=1;i<=n;++i) printf("%d ",ans[i]);
	return 0;
}