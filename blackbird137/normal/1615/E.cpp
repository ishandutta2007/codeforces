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
#define pb(x) push_back(x)
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

const int N=2e5+5;
int n,k,b_son[N],dep[N],mx[N];

vector<int> hav;

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

void dfs1(int u,int fa)
{
	dep[u]=dep[fa]+1;mx[u]=dep[u];
	for(int i=head[u];i;i=e[i].ne)
	{
		int v=e[i].v;
		if(v==fa) continue;
		dfs1(v,u);
		mx[u]=max(mx[u],mx[v]);
		if(mx[b_son[u]]<mx[v])
			b_son[u]=v;
	}
}

void dfs2(int u,int fa,int s)
{
	if(s) hav.push_back(mx[u]-dep[u]+1);
	if(b_son[u]) dfs2(b_son[u],u,0);
	for(int i=head[u];i;i=e[i].ne)
	{
		int v=e[i].v;
		if(v==fa||v==b_son[u])
			continue;
		dfs2(v,u,1);
	}
}

signed main()
{
	n=read();k=read();
	for(int i=1;i<n;++i)
	{
		int u=read(),v=read();
		add(u,v);add(v,u);
	}
	dfs1(1,0);dfs2(1,0,1);
	sort(hav.begin(),hav.end());
	if(k>=hav.size())
	{
		k=min(k,max(hav.size(),n>>1));
		write((n-k)*k);
	}
	else
	{
		int num=0;
		for(int i=1;i<=k;++i)
			num+=hav[hav.size()-i];
		int r=k,b=min(n-num,n>>1);
		write((r-b)*(n-r-b));
	}
	return 0;
}