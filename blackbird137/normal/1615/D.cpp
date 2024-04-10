#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<cmath>
#include<ctime>
#include<queue>
#include<map>
#include<set>

#define int long long
#define fi first
#define se second
#define max Max
#define min Min
#define abs Abs
#define lc (x<<1)
#define rc (x<<1|1)
#define mid ((l+r)>>1)
#define lowbit(x) (x&(-x))
#define fan(x) (((x-1)^1)+1)
#define mp(x,y) make_pair(x,y)
#define clr(f,n) memset(f,0,sizeof(int)*(n))
#define cpy(f,g,n) memcpy(f,g,sizeof(int)*(n))
#define INF 0x3f3f3f3f

using namespace std;

inline int read()
{
	int ans=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=(ans<<1)+(ans<<3)+c-'0';c=getchar();}
	return ans*f;
}

inline void write(int x)
{
	if(x<0) putchar('-'),x=-x;
	if(x/10) write(x/10);
	putchar((char)(x%10)+'0');
}

template<typename T>inline T Abs(T a){return a>0?a:-a;};
template<typename T,typename TT>inline T Min(T a,TT b){return a<b?a:b;}
template<typename T,typename TT> inline T Max(T a,TT b){return a<b?b:a;}

const int N=4e5+5;
int t,n,m,a[N],uu[N],vv[N],xx[N],yy[N],zz[N],b[N],fl;

struct Edge
{
	int v,w,ne;
}e[N*2];
int head[N],tot;

struct Edge2
{
	int v,w,ne;
}ee[N*2];
int headd[N],tott;

inline void add(int u,int v,int w)
{
	e[++tot]=(Edge){v,w,head[u]};
	head[u]=tot;
}

inline void add2(int u,int v,int w)
{
	ee[++tott]=(Edge2){v,w,headd[u]};
	headd[u]=tott;
}

void dfs1(int u)
{
	for(int i=headd[u];i;i=ee[i].ne)
	{
		int v=ee[i].v;
		if(b[v]==-1)
		{
			if(ee[i].w)
				b[v]=(b[u]^1);
			else b[v]=b[u];
			dfs1(v);
		}
		else
		{
			if(ee[i].w&&b[v]!=(b[u]^1))
				fl=0;
			else if(!ee[i].w&&b[v]!=b[u])
				fl=0;
		}
	}
}

void dfs2(int u,int fa,int s,int ls)
{
	if(ls!=-1)
		a[ls]=(s^b[u]);
	s=b[u];
	for(int i=head[u];i;i=e[i].ne)
	{
		int v=e[i].v;
		if(v==fa)
			continue;
		dfs2(v,u,s,a[e[i].w]==-1?e[i].w:-1);
	}
}

int dfs3(int u,int fa,int s,int t)
{
	if(u==t) return s;
	for(int i=head[u];i;i=e[i].ne)
	{
		int v=e[i].v;
		if(v==fa) continue;
		int tmp=dfs3(v,u,s^a[e[i].w],t);
		if(tmp!=-1) return tmp;
	}
	return -1;
 } 
 
 inline int query(int x)
 {
 	int res=0;
 	for(int i=0;i<31;++i)
 		if((x>>i)&1)
 			res^=1;
 	return res;
 }

signed main()
{
	t=read();
	while(t--)
	{
		n=read();m=read();
		for(int i=2;i<=n;++i)
		{
			int u=read(),v=read(),w=read();
			add(u,v,i);add(v,u,i);a[i]=w;
			if(w!=-1) add2(u,v,query(w)),add2(v,u,query(w));
			uu[i]=u;vv[i]=v;
		}
		for(int i=1;i<=m;++i)
		{
			int x=read(),y=read(),w=read();
			add2(x,y,w);add2(y,x,w);
			xx[i]=x;yy[i]=y;zz[i]=w;
		}
		for(int i=1;i<=n;++i)
			b[i]=-1;
		fl=1;
		for(int i=1;i<=n;++i)
			if(b[i]==-1)
			{
				b[i]=0;
				dfs1(i);
			}
		if(!fl)
			puts("NO");
		else
		{
			puts("YES");
			dfs2(1,0,0,-1);
			
			for(int i=2;i<=n;++i)
				printf("%lld %lld %lld\n",uu[i],vv[i],a[i]);
		}
		for(int i=1;i<=n;++i)
			head[i]=headd[i]=0;
		tot=0;tott=0;
	}
	return 0;
}