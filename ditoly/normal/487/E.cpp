#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
#define MN 200000
#define N 262144
#define INF 0x3FFFFFFF
struct edge{int nx,t;}e[MN*3+5];
int n,h[MN+5],H[MN+5],en,l[MN+5],d[MN+5],dfn,zx[MN+5],zy[MN+5],zn,u[MN+5];
int w[MN+5],cnt,T[N*2+5],f[MN+5],fa[MN+5],s[MN+5],mx[MN+5];
priority_queue< pair<int,int> > q[MN+5];
inline void ins(int*h,int x,int y)
{
	e[++en]=(edge){h[x],y};h[x]=en;
	e[++en]=(edge){h[y],x};h[y]=en;
}
void tj(int x,int fa)
{
	l[x]=d[x]=++dfn;
	for(int i=h[x];i;i=e[i].nx)if(e[i].t!=fa)
		if(d[e[i].t])
		{
			l[x]=min(l[x],d[e[i].t]);
			if(d[e[i].t]<d[x])zx[++zn]=x,zy[zn]=e[i].t;
		}
		else
		{
			zx[++zn]=x;zy[zn]=e[i].t;
			tj(e[i].t,x);l[x]=min(l[x],l[e[i].t]);
			if(l[e[i].t]>=d[x])for(++cnt;zx[zn+1]!=x||zy[zn+1]!=e[i].t;--zn)
			{
				if(u[zx[zn]]!=cnt)u[zx[zn]]=cnt,ins(H,cnt,zx[zn]);
				if(u[zy[zn]]!=cnt)u[zy[zn]]=cnt,ins(H,cnt,zy[zn]);
			}
		}
}
void dfs(int x)
{
	s[x]=1;
	for(int i=H[x];i;i=e[i].nx)if(e[i].t!=fa[x])
	{
		fa[e[i].t]=x;d[e[i].t]=d[x]+1;
		dfs(e[i].t);
		s[x]+=s[e[i].t];
		if(s[e[i].t]>s[mx[x]])mx[x]=e[i].t;
	}
}
void build(int x)
{
	l[x]=++dfn;
	if(!f[x])f[x]=x;
	if(mx[x])f[mx[x]]=f[x],build(mx[x]);
	for(int i=H[x];i;i=e[i].nx)
		if(e[i].t!=fa[x]&&e[i].t!=mx[x])build(e[i].t);
}
int query(int l,int r)
{
	int res=INF;
	for(l+=N-1,r+=N+1;l^r^1;l>>=1,r>>=1)
	{
		if(~l&1)res=min(res,T[l+1]);
		if( r&1)res=min(res,T[r-1]);
	}
	return res;
}
void renew(int k,int x){for(T[k+=N]=x;k>>=1;)T[k]=min(T[k<<1],T[k<<1|1]);}
void change(int k,int x)
{
	renew(l[k],w[k]=x);if(!fa[k])return;
	q[fa[k]].push(make_pair(-x,k));
	while(-q[fa[k]].top().first<w[q[fa[k]].top().second])q[fa[k]].pop();
	renew(l[fa[k]],-q[fa[k]].top().first);
}
int Q(int x,int y)
{
	int res=INF;
	for(;f[x]!=f[y];x=fa[f[x]])
	{
		if(d[f[x]]<d[f[y]])swap(x,y);
		res=min(res,query(l[f[x]],l[x]));
	}
	if(l[x]>l[y])swap(x,y);
	if(x>n)res=min(res,T[l[fa[x]]+N]);
	return min(res,query(l[x],l[y]));
}
int main()
{
	int m,q,i;char s[5];
	cnt=n=read();m=read();q=read();
	for(i=1;i<=n;++i)w[i]=read();
	while(m--)ins(h,read(),read());
	tj(1,0);dfs(1);d[1]=dfn=0;build(1);
	for(i=1;i<2*N;++i)T[i]=INF;
	for(i=1;i<=n;++i)change(i,w[i]);
	while(q--)
	{
		scanf("%s",s);
		if(s[0]=='C')i=read(),change(i,read());
		else printf("%d\n",Q(read(),read()));
	}
}