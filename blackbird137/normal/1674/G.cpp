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
#define pb(x) push_back(x)
#define lowbit(x) ((x)&(-(x)))
#define fan(x) ((((x)-1)^1)+1)
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

const int N=3e5+5;
int n,m,dp[N],du[N],id[N],in[N],ot[N];

struct Edge
{
	int v,ne;
}e[N*2];
int head[N],tot;

inline void add(int u,int v)
{
	e[++tot]=(Edge){v,head[u]};
	head[u]=tot;
}

signed main()
{
	n=read();m=read();
	for(int i=1;i<=m;++i)
	{
		int u=read(),v=read();
		add(u,v);du[v]++;
		in[v]++;ot[u]++;
	}
	queue<int> qu;
	for(int i=1;i<=n;++i)
		if(du[i]==0)
			qu.push(i);
	int k=0;
	while(!qu.empty())
	{
		int u=qu.front();
		qu.pop();id[++k]=u;
		for(int i=head[u];i;i=e[i].ne)
		{
			int v=e[i].v;du[v]--;
			if(!du[v]) qu.push(v);
		}
	}
	int ans=1;
	memset(dp,-0x3f,sizeof(dp));
	for(int I=1;I<=n;++I)
	{
		int u=id[I];
		if(in[u]>=2)
			ans=max(ans,dp[u]+1);
		if(in[u]>=2&&ot[u]>=2)
		{
			for(int i=head[u];i;i=e[i].ne)
			{
				int v=e[i].v;
				dp[v]=max(dp[v],dp[u]+1);
			}
		}
		if(ot[u]>=2)
		{
			for(int i=head[u];i;i=e[i].ne)
			{
				int v=e[i].v;
				dp[v]=max(dp[v],1);
			}
		}
	}
	write(ans);
	return 0;
}