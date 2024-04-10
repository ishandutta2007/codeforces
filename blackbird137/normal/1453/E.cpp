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
#define INF 0x3f3f3f3f3f3f3f3f

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

const int N=2e5+5;
int T,n,ans,mn[N];

struct Edge
{
	int v,ne;
}e[N*2];
int head[N],tot;

inline void add(int u,int v);
void dfs(int u,int fa);

signed main()
{
	//freopen("flag.in","r",stdin);
	//freopen("flag.out","w",stdout);
	T=read();
	while(T--)
	{
		n=read();tot=0;ans=1;
		for(int i=1;i<=n;++i)
			mn[i]=1e9,head[i]=0;
		for(int i=1;i<=n-1;++i)
		{
			int u=read(),v=read();
			add(u,v);add(v,u);
		}
		dfs(1,0);
		write(ans);puts("");
	}
	return 0;
}

inline void add(int u,int v)
{
	e[++tot]=(Edge){v,head[u]};
	head[u]=tot;
}

void dfs(int u,int fa)
{
	int flag=0;
	int mx1=-1,mx2=-1;
	for(int i=head[u];i;i=e[i].ne)
	{
		int v=e[i].v;
		if(v==fa) continue;
		dfs(v,u);flag=1;
		mn[u]=min(mn[u],mn[v]+1);
		if(mn[v]+1>mx1)
			mx2=mx1,mx1=mn[v]+1;
		else if(mn[v]+1>mx2)
			mx2=mn[v]+1;
	}
	if(!flag) mn[u]=0;
	if(u==1) ans=max(ans,mx2+1);
	else ans=max(ans,mx1+1);
}