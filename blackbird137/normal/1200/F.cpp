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

const int N=3e3+5,M=2520;
int n,m[N],k,q,a[N],e[N][15],id[N][M+5],vis[N*M],hav[N],ans[N*M];

struct DSU
{
	int fa[N*M],siz[N*M];
	inline void init(int x)
	{
		for(int i=1;i<=x;++i)
			fa[i]=i,siz[i]=1;
	}
	int find(int x)
	{
		return fa[x]==x?x:fa[x]=find(fa[x]);
	}
	bool merge(int x,int y)
	{
		int f1=find(x),f2=find(y);
		if(f1==f2) return 0;
		fa[f1]=f2;siz[f2]+=siz[f1];
		return 1;
	}
}dsu;

inline void dfs(int x,int y)
{
	if(vis[id[x][y]])
		return;
	vis[id[x][y]]=1;
	hav[x]=1;
	int v=e[x][y%m[x]];
	dfs(v,(y+a[v])%M);
}

signed main()
{
	n=read();
	for(int i=1;i<=n;++i)
		a[i]=(read()%M+M)%M;
	for(int i=1;i<=n;++i)
	{
		m[i]=read();
		for(int j=0;j<m[i];++j)
			e[i][j]=read();
	}
	for(int i=1;i<=n;++i)
		for(int j=0;j<=M;++j)
			id[i][j]=++k;
	dsu.init(k);
	for(int i=1;i<=n;++i)
		for(int j=0;j<=M;++j)
		{
			int v=e[i][j%m[i]];
			dsu.merge(id[i][j],id[v][(j+a[v])%M]);
		}
	for(int i=1;i<=n;++i)
		for(int j=0;j<=M;++j)
			if(id[i][j]==dsu.find(id[i][j]))
			{
				for(int p=1;p<=n;++p)
					hav[p]=0;
				dfs(i,j);
				int tmp=0;
				for(int p=1;p<=n;++p)
					tmp+=hav[p];
				ans[id[i][j]]=tmp;
			}
	q=read();
	while(q--)
	{
		int x=read(),y=((read()+a[x])%M+M)%M;
		write(ans[dsu.find(id[x][y])]);puts("");
	}
	return 0;
}