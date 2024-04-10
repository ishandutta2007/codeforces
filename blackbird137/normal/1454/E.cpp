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
#define lowbit(x) (x&(-x))
#define mid ((l+r)>>1)
#define lc (x<<1)
#define rc (x<<1|1)

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

inline int Abs(int a){return a>0?a:-a;};
inline int Min(int a,int b){return a>b?b:a;}
inline int Max(int a,int b){return a>b?a:b;}

const int N=2e5+5;
int t,n,vis[N],on[N],col[N],siz[N],du[N],ans,flag;

struct Edge
{
	int v,ne;
}e[N*2];
int head[N],tot;

inline void add(int u,int v);
void dfs(int u,int fa,int c);

queue<int> qu;

signed main()
{
	t=read();
	while(t--)
	{
		n=read();ans=0;
		for(int i=1;i<=n;++i)
		{
			int u=read(),v=read();
			add(u,v);add(v,u);du[u]++,du[v]++;
		}
		while(!qu.empty()) qu.pop();
		for(int i=1;i<=n;++i)
			if(du[i]==1) qu.push(i);
		while(!qu.empty())
		{
			int u=qu.front();
			qu.pop();
			on[u]=1;
			for(int i=head[u];i;i=e[i].ne)
			{
				int v=e[i].v;
				du[v]--;
				if(du[v]==1) qu.push(v);
			}
		}
		int m=0;
		for(int i=1;i<=n;++i)
			if(on[i]==0) dfs(i,0,++m);
		ans=0;
		for(int i=1;i<=m;++i)
			ans+=siz[i]*(siz[i]-1+(n-siz[i])*2);
		printf("%lld\n",ans/2);
		for(int i=1;i<=n;++i)
		{
			head[i]=0;du[i]=0;
			vis[i]=0;on[i]=0;
			col[i]=0;siz[i]=0;
		}
		tot=0;flag=0;
	}
	return 0;
}

inline void add(int u,int v)
{
	e[++tot]=(Edge){v,head[u]};
	head[u]=tot;
}

void dfs(int u,int fa,int c)
{
	col[u]=c;
	siz[c]++;
	for(int i=head[u];i;i=e[i].ne)
	{
		int v=e[i].v;
		if(v==fa||on[v]==0)
			continue;
		dfs(v,u,c);
	}
}