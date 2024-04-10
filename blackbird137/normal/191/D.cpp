#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<random>
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
#define pb(x) push_back(x)
#define lowbit(x) ((x)&(-(x)))
#define fan(x) ((((x)-1)^1)+1)
#define mp(x,y) make_pair(x,y)
#define clr(f,n) memset(f,0,sizeof(int)*(n))
#define cpy(f,g,n) memcpy(f,g,sizeof(int)*(n))
#define INF 0x3f3f3f3f

using namespace std;

namespace fastIO
{
    #define BUF_SIZE 100000
    bool IOerror=0;
    inline char nc()
	{
        static char buf[BUF_SIZE],*p1=buf+BUF_SIZE,*pend=buf+BUF_SIZE;
        if(p1==pend)
		{
            p1=buf;
            pend=buf+fread(buf,1,BUF_SIZE,stdin);
            if(pend==p1)
			{
                IOerror=1;
                return -1;
            }
        }
        return *p1++;
    }
    inline bool blank(char ch)
	{
        return ch==' '||ch=='\n'||ch=='\r'||ch=='\t';
    }
    inline int read()
	{
		int ans=0,f=1;
		char c=nc();
		while(c>'9'||c<'0'){if(c=='-')f=-1;c=nc();}
		while(c>='0'&&c<='9'){ans=ans*10+c-'0';c=nc();}
		return ans*f;
	}
    #undef BUF_SIZE
};

using namespace fastIO;

inline void write(int x)
{
	if(x<0) putchar('-'),x=-x;
	if(x/10) write(x/10);
	putchar((char)(x%10)+'0');
}

template<typename T>inline T Abs(T a){return a>0?a:-a;};
template<typename T,typename TT>inline T Min(T a,TT b){return a<b?a:b;}
template<typename T,typename TT> inline T Max(T a,TT b){return a<b?b:a;}

const int N=1e6+5;
int n,m,fa[N],siz[N],id[N],cnt,sm[N],vis[N],tg[N*4],l1[N],l2[N],l3[N],l4[N],l5[N],l6[N],du[N],dp[N],hv[N],ans;

struct edge
{
	int u,v;
}ee[N*2];
int tott;

struct Edge
{
	int v,ne;
}e[N*4];
int head[N],tot;

inline void add(int u,int v)
{
	e[++tot]=(Edge){v,head[u]};
	head[u]=tot;
}

void dfs(int u,int ls)
{
	vis[u]=++cnt;
	for(int i=head[u];i;i=e[i].ne)
	{
		int v=e[i].v;
		if(fan(i)==ls)
			continue;
		if(!vis[v])
		{
			dfs(v,i);
			sm[u]+=sm[v];
		}
		else if(vis[v]<vis[u])
		{
			sm[u]++;
			sm[v]--;
		}
	}
	if(ls&&sm[u]==0)
		tg[ls]=tg[fan(ls)]=1;
}

void dfs2(int u,int fa)
{
	// 
	if(l1[u])
	{
		// 
		int sum=0;
		for(int i=head[u];i;i=e[i].ne)
		{
			int v=e[i].v;
			if(v==fa) continue;
			dfs2(v,u);sum+=dp[v]+(!hv[v]);
		}
		dp[u]=sum;
		if(l5[u]==1)
		{
			dp[u]++;
			return;
		}
		dp[u]-=l6[u];hv[u]=0;
		if(l5[u]-l6[u]*2<=1)
			dp[u]++;
		if(l2[u]==1)
		{
			sum-=l4[u];
			if(l3[u]>=2)
			{
				sum--;
				if(u==1)
				{
					if(sum<dp[u])
						dp[u]=sum;
				}
				else
				{
					if(sum+1<dp[u]+(!hv[u]))
						dp[u]=sum,hv[u]=0;
				}
			}
		}
		else if(l2[u]>=2)
		{
			sum-=l2[u];
			sum-=l4[u];
			if(u==1)
			{
				if(sum<dp[u])
					dp[u]=sum;
			}
			else
			{
				if(sum+1<dp[u]+(!hv[u]))
					dp[u]=sum,hv[u]=0;
			}
		}
		return;
	}
	int sum=0;
	for(int i=head[u];i;i=e[i].ne)
	{
		int v=e[i].v;
		if(v==fa) continue;
		dfs2(v,u);sum++;
		dp[u]+=dp[v]+(!hv[v]);
	}
	dp[u]-=sum/2;hv[u]=sum%2;
}

inline int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}

inline void merge(int x,int y)
{
	x=find(x);y=find(y);
	if(x==y) return;
	fa[y]=x;siz[x]+=siz[y];
}

signed main()
{
	//freopen("graph.in","r",stdin);
	//freopen("graph.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=m;++i)
	{
		int u=read(),v=read();
		add(u,v);add(v,u);
		du[u]++;du[v]++;
	}
	dfs(1,0);cnt=0;
	for(int i=1;i<=n;++i)
		fa[i]=i,vis[i]=0,siz[i]=1;
	for(int i=1;i<=tot;i+=2)
		if(!tg[i]) merge(e[i].v,e[i+1].v);
	for(int i=1;i<=n;++i)
	{
		if(!vis[find(i)])
			vis[find(i)]=++cnt;
		id[i]=vis[find(i)];
		if(siz[find(i)]!=1)
			l1[id[i]]=1;
		if(du[i]>=4)
			l2[id[i]]++,l4[id[i]]+=(du[i]-4)/2;
		if(du[i]>=3)
			l3[id[i]]++;
		if(du[i]>=2)
			l5[id[i]]+=du[i]-2,l6[id[i]]+=(du[i]-2)/2;
	}
	for(int i=1;i<=tot;i+=2)
		if(tg[i]) ee[++tott]=(edge){id[e[i].v],id[e[i+1].v]};
	for(int i=1;i<=n;++i) head[i]=0;tot=0;
	for(int i=1;i<=tott;++i)
		add(ee[i].u,ee[i].v),add(ee[i].v,ee[i].u);
	dfs2(1,0);ans+=dp[1];
	write(ans);putchar(' '),write(m);
	return 0;
}