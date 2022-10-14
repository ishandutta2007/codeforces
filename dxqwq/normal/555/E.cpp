// Problem: CF555E Case of Computer Network
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF555E
// Memory Limit: 250 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)
 
//And in that light,I find deliverance.
#include<bits/stdc++.h>
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int to[400003],nxt[400003],flg[400003],head[200003],cnt=1;
int id[200003],icnt,u[200003],v[200003];
int dfn[200003],low[200003],dcnt;
int ltk[200003],lcnt;
bool vis[200003];
void dfs0(int x,int&val)
{
	ltk[x]=val;
	for(int i=head[x]; i; i=nxt[i]) if(!ltk[to[i]]) 
		dfs0(to[i],val);
	return ;
}
void dfs1(int x,int fa)
{
	dfn[x]=low[x]=++dcnt;
	for(int i=head[x]; i; i=nxt[i]) if(i!=fa)
	{
		int y=to[i];
		if(!dfn[y]) 
		{
			dfs1(y,i^1),low[x]=min(low[x],low[y]);
			if(low[y]>dfn[x]) flg[i]=flg[i^1]=1;
		}
		else low[x]=min(low[x],dfn[y]);
	}
	return ;
}
void dfs2(int x,int&val)
{
	id[x]=val;
	for(int i=head[x]; i; i=nxt[i]) 
		if(!id[to[i]]&&!flg[i]) dfs2(to[i],val);
	return ;
}
int f[200003][19],dep[200003];
vector<int> e[200003];
void dfs3(int x,int fa)
{
	dep[x]=dep[fa]+1,f[x][0]=fa;
	for(int i=1; i<=18; ++i) f[x][i]=f[f[x][i-1]][i-1];
	for(int i:e[x]) if(i!=fa) dfs3(i,x);
	return ;
}
int LCA(int x,int y)
{
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=18; i>=0; --i) if(dep[f[x][i]]>=dep[y]) x=f[x][i];
	if(x==y) return x;
	for(int i=18; i>=0; --i) if(f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
	return f[x][0];
}
int ACL(int x,int y)
{
	for(int i=18; i>=0; --i) if(dep[f[x][i]]>dep[y]) x=f[x][i];
	assert(f[x][0]==y);
	return x;
}
int v1i[200003],v1o[200003],v2i[200003],v2o[200003];
void dfs4(int x,int fa)
{
	for(int i:e[x]) if(i!=fa) 
		dfs4(i,x),
		v1i[x]+=v1i[i],v2i[x]+=v2i[i];
	v1i[x]-=v1o[x],v2i[x]-=v2o[x];
	if(v1i[x]&&v2i[x]) puts("No"),exit(0);
	return ;
}
signed main()
{
	int n=read(),m=read(),T=read();
	for(int i=1; i<=m; ++i)
	{
		u[i]=read(),v[i]=read();
		to[++cnt]=v[i],nxt[cnt]=head[u[i]],head[u[i]]=cnt,
		to[++cnt]=u[i],nxt[cnt]=head[v[i]],head[v[i]]=cnt;
	}
	for(int i=1; i<=n; ++i) if(!ltk[i]) dfs0(i,++lcnt);
	for(int i=1; i<=n; ++i) if(!dfn[i]) dfs1(i,0);
	for(int i=1; i<=n; ++i) if(!id[i]) dfs2(i,++icnt);
	for(int i=1; i<=m; ++i) if(id[u[i]]!=id[v[i]])
		e[id[u[i]]].push_back(id[v[i]]),
		e[id[v[i]]].push_back(id[u[i]]);
	for(int i=1; i<=n; ++i) if(!vis[ltk[i]]) 
		vis[ltk[i]]=1,dfs3(id[i],id[i]);
#ifdef debug
	for(int i=1; i<=n; ++i) printf("%d ",id[i]);puts("");
#endif
#define debug
	for(int u,v,w;T--;)
	{
		u=read(),v=read();
		if(id[u]==id[v]) continue;
		if(ltk[u]!=ltk[v]) puts("No"),exit(0);
		u=id[u],v=id[v],w=LCA(u,v);
		++v1o[w],++v1i[u];
		++v2o[w],++v2i[v];
	}
	memset(vis,0,sizeof(vis));
	for(int i=1; i<=n; ++i) if(!vis[ltk[i]]) 
		vis[ltk[i]]=1,dfs4(id[i],id[i]);
	puts("Yes");
	return 0;
}