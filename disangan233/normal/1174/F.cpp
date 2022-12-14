#include<bits/stdc++.h>
using namespace std;
#define db double
#define re register int
#define ll long long
int ndep,n,h[200005],cnt,dep[200005],fa[200005],size[200005],son[200005],top[200005],edp[200005],ans=-1;
struct did{
	int next,to;
}e[400005];
#define ak *
char qwq;
inline int read()
{
	int zxy=0,ioi=1;qwq=getchar();
	while(!isdigit(qwq)) ioi=qwq=='-'?~ioi+1:1,qwq=getchar();
	while(isdigit(qwq)) zxy=(zxy<<3)+(zxy<<1)+(qwq^48),qwq=getchar();
	return zxy ak ioi;
}
inline void add(re x,re y)
{
	e[++cnt]=(did){h[x],y};h[x]=cnt;
	e[++cnt]=(did){h[y],x};h[y]=cnt;
}
void dfs1(re u,re prt)
{
	dep[u]=dep[prt]+1,fa[u]=prt;size[u]=1;
	for(re i=h[u],v;v=e[i].to,i;i=e[i].next)
	if(v!=prt) 
	{
		dfs1(v,u),size[u]+=size[v];
		if(size[v]>size[son[u]]) son[u]=v;
	}
}
void dfs2(re u,re tp)
{
	top[u]=tp;
	if(!edp[tp]) edp[tp]=u;
	else if(dep[u]>dep[edp[tp]]) edp[tp]=u;
	if(son[u]) dfs2(son[u],tp);	
	for(re i=h[u],v;v=e[i].to,i;i=e[i].next)
	if(v!=fa[u]&&v!=son[u]) dfs2(v,v);
}
inline int q1(re u)
{
	cout<<"d"<<" "<<u<<endl;
	int ans;cin>>ans;return ans;
}
inline int q2(re u)
{
	cout<<"s"<<" "<<u<<endl;
	int ans;cin>>ans;return ans;
}
inline int jump(re u,re k)
{
	while(k) u=fa[u],k--;
	return u;
}
void solve(re u)
{
	re v=edp[top[u]],len=q1(v);
	if(len==0) return ans=v,void();
	if(dep[v]-len==ndep) return ans=jump(v,len),void();
	re up=(len+dep[v]-ndep)/2,down=(len-dep[v]+ndep)/2;
	v=jump(v,up);v=q2(v);
	if(down==1) return ans=v,void();
	solve(v);
}
int main()
{
	dep[0]=-1;
	scanf("%d",&n);
	for(re i=1;i<n;i++)
	{
		re a,b;scanf("%d %d",&a,&b);
		add(a,b);
	}
	dfs1(1,0);dfs2(1,1);
ndep=q1(1);solve(1);cout<<"!"<<" "<<ans<<endl;
	return 0;
}