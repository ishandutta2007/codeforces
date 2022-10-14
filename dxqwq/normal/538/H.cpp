// Problem: CF538H Summer Dichotomy
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF538H
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
namespace ts//two-sat
{
	int head[2000003],nxt[2000003],to[2000003],cnt;
	int vis[2000003],dfn[2000003],low[2000003],cur;
	int id[2000003],now=0;
	stack<int> s;
	void dfs(int x)
	{
	    vis[x]=1,dfn[x]=low[x]=++cur,s.push(x);
		for(int i=head[x]; i; i=nxt[i])
		{
			int y=to[i];
			if(vis[y]==0) dfs(y),low[x]=min(low[x],low[y]);
			else if(vis[y]==1) low[x]=min(low[x],dfn[y]);
		}
		if(low[x]==dfn[x]) 
		{
			++now;
			while(vis[x]==1) vis[s.top()]=2,id[s.top()]=now,s.pop();
		}
		return ;
	}
	void add(int x,int y)
	{
		to[++cnt]=y,nxt[cnt]=head[x],head[x]=cnt;
		return ;
	}
	signed main(int n,int L,int R)
	{
		for(int i=1; i<=2*n; i++) if(!vis[i]) dfs(i);
		for(int i=1; i<=n; i++) if(id[i]==id[i+n]) puts("IMPOSSIBLE"),exit(0);
		puts("POSSIBLE");
		printf("%lld %lld\n",L,R);
		for(int i=1; i<=n; i++) if(id[i]>id[i+n]) printf("1"); else printf("2");
		puts("");
		return 0;
	}
}
int l[100003],r[100003];
signed main()
{
	int L=read(),R=read();
	int n=read(),m=read();
	int A=0,B=1e18;
	for(int i=1; i<=n; ++i) 
		l[i]=read(),r[i]=read(),
		A=max(A,l[i]),B=min(B,r[i]);
	swap(A,B);
	(A+B<L)&&(B=L-A),(A+B>R)&&(A=R-B);
	if(A<0||B<0) puts("IMPOSSIBLE"),exit(0);
	for(int i=1; i<=n; ++i) 
	{
		bool f1=(l[i]<=A&&A<=r[i]),f2=(l[i]<=B&&B<=r[i]);
		if(!f1&&!f2) puts("IMPOSSIBLE"),exit(0);
		if(f1&&f2) continue;
		if(f1) ts::add(i,i+n);
		else ts::add(i+n,i);
	}
	for(int i=1,u,v; i<=m; ++i) 
		u=read(),v=read(),
		ts::add(u,v+n),ts::add(v+n,u),ts::add(v,u+n),ts::add(u+n,v);
	ts::main(n,A,B);
	return 0;
}