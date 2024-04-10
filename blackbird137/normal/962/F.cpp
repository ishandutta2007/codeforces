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

const int N=1e5+5;
int n,m,dfn[N],low[N],in[N],st1[N],top1,st2[N],top2,tg[N],fa[N],hav[N],ans,cnt;

struct Edge
{
	int v,w,ne;
}e[N*2];
int head[N],tot;

inline void add(int u,int v,int w);
void tarjin(int u);

signed main()
{
	n=read();m=read();
	for(int i=1;i<=m;++i)
	{
		int u=read(),v=read();
		add(u,v,i);add(v,u,i);
	}
	for(int i=1;i<=n;++i)
		if(!dfn[i])
			tarjin(i);
	for(int i=1;i<=m;++i)
		if(tg[i]) ++ans;
	write(ans);puts("");
	for(int i=1;i<=m;++i)
		if(tg[i]) write(i),putchar(' ');
	return 0;
}

inline void add(int u,int v,int w)
{
	e[++tot]=(Edge){v,w,head[u]};
	head[u]=tot;
}

void tarjin(int u)
{
	dfn[u]=low[u]=++cnt;
	st1[++top1]=u;
	for(int i=head[u];i;i=e[i].ne)
	{
		int v=e[i].v;
		if(e[i].w==fa[u])
			continue;
		if(!dfn[v])
		{
			fa[v]=e[i].w;
			st2[++top2]=e[i].w;
			tarjin(v);
			low[u]=min(low[u],low[v]);
			if(low[v]>=dfn[u])
			{
				int s1=1,s2=0;
				while(1)
				{
					int x=st1[top1--];++s1;
					if(x==v) break;
				}
				while(1)
				{
					int x=st2[top2--];
					hav[++s2]=x;
					if(x==fa[v]) break;
				}
				if(s1==s2)
				{
					for(int i=1;i<=s2;++i)
						tg[hav[i]]=1;
				}
			}
		}
		else
		{
			low[u]=min(low[u],dfn[v]);
			if(dfn[v]<dfn[u])
				st2[++top2]=e[i].w;
		}
	}
}