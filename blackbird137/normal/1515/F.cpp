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

const int N=6e5+5;
int n,m,x,a[N],vis[N],all;

struct Edge
{
	int v,w,ne;
}e[N*2];
int head[N],tot;

inline void add(int u,int v,int w)
{
	e[++tot]=(Edge){v,w,head[u]};
	head[u]=tot;
}

vector<int> p1,p2;

void dfs(int u)
{
	vis[u]=1;
	for(int i=head[u];i;i=e[i].ne)
	{
		int v=e[i].v;
		if(vis[v]) continue;
		dfs(v);
		if(a[v]>=x)
		{
			a[u]=a[u]+a[v]-x;a[v]=a[i];
			p1.push_back(e[i].w);
		}
			
		else p2.push_back(e[i].w);
	}
}

signed main()
{
	n=read();m=read();x=read();
	for(int i=1;i<=n;++i)
		a[i]=read(),all+=a[i];
	for(int i=1;i<=m;++i)
	{
		int u=read(),v=read();
		add(u,v,i);add(v,u,i);
	}
	if(all<(n-1)*x)
	{
		puts("NO");
		return 0;
	}
	dfs(1);
	for(int i=1;i<=n;++i)
		if(!vis[i])
		{
			puts("NO");
			return 0;
		}
	puts("YES");
	for(int i=0;i<p1.size();++i)
		write(p1[i]),puts("");
	for(int i=p2.size()-1;i>=0;--i)
		write(p2[i]),puts("");
	return 0;
}