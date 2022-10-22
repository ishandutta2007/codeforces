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
#include<assert.h>

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
int n,m[N],k,b[N],hav[N],sum[N],vis[N],now;

vector<int> a[N],ans[N];
map<int,int> ps[N],res[N];

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

void dfs(int u)
{
	for(int &i=head[u];i;i=e[i].ne)
	{
		if(vis[(i+1)/2])
			continue;
		vis[(i+1)/2]=1;
		int v=e[i].v;
		int w=e[i].w;
		res[u][w]=1;res[v][w]=-1;
		dfs(v);
	}
}

inline bool check()
{
	for(int i=1;i<=k;++i)
		hav[i]=0;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m[i];++j)
			hav[a[i][j]]+=ans[i][j];
	for(int i=1;i<=k;++i)
		if(hav[i]) return 0;
	for(int i=1;i<=n;++i)
	{
		int tmp=0;
		for(int j=1;j<=m[i];++j)
			tmp+=ans[i][j];
		if(tmp) return 0;
	}
	return 1;
}

signed main()
{
	n=read();
	for(int i=1;i<=n;++i)
	{
		m[i]=read();
		a[i].push_back(0);
		ans[i].push_back(0);
		for(int j=1;j<=m[i];++j)
		{
			a[i].push_back(read());
			ans[i].push_back(0);
			b[++k]=a[i][j];
		}
	}
	sort(b+1,b+1+k);
	k=unique(b+1,b+1+k)-b-1;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m[i];++j)
		{
			a[i][j]=lower_bound(b+1,b+1+k,a[i][j])-b;
			if(!hav[a[i][j]])
				hav[a[i][j]]=j;
			else
			{
				int tmp=hav[a[i][j]];
				ans[i][tmp]=1;ans[i][j]=-1;
				hav[a[i][j]]=0;
			}
			sum[a[i][j]]^=1;
		}
		for(int j=1;j<=m[i];++j)
			hav[a[i][j]]=0;
	}
	for(int i=1;i<=k;++i)
		if(sum[i])
		{
			puts("NO");
			return 0;
		}
	puts("YES");
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m[i];++j)
			if(!ans[i][j])
			{
				if(hav[a[i][j]])
				{
					add(i,hav[a[i][j]],a[i][j]);
					add(hav[a[i][j]],i,a[i][j]);
					hav[a[i][j]]=0;
				}
				else hav[a[i][j]]=i;
			}
	for(int i=1;i<=n;++i)
		dfs(i);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m[i];++j)
			if(!ans[i][j])
				ans[i][j]=res[i][a[i][j]];
	assert(check());
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m[i];++j)
			if(ans[i][j]==1)
				putchar('L');
			else putchar('R');
		puts("");
	}
	return 0;
}