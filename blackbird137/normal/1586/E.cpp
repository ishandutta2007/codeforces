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

const int N=3e5+5;
int n,m,q,a[N],fa[N],faa[N],dep[N],sm[N];

inline int find(int x)
{
	return faa[x]==x?x:faa[x]=find(faa[x]);
}

struct Edge
{
	int v,ne;
}e[N*2];
int head[N],tot;

vector<vector<int> > ans;
vector<int> qwq,res;

inline void add(int u,int v);
void dfs(int u,int f);
inline int lca(int x,int y);
inline void work(int x,int y);
void dfs2(int u);

signed main()
{
	n=read();m=read();
	for(int i=1;i<=n;++i)
		faa[i]=i;
	for(int i=1;i<=m;++i)
	{
		int u=read(),v=read();
		if(find(u)!=find(v))
		{
			add(u,v);add(v,u);
			faa[find(u)]=find(v);
		}
	}
	dfs(1,0);
	q=read();
	while(q--)
	{
		int x=read(),y=read();
		int LCA=lca(x,y);
		res.clear();
		work(x,LCA);
		for(int i=0;i<qwq.size();++i)
			res.push_back(qwq[i]);
		res.pop_back();
		work(y,LCA);
		reverse(qwq.begin(),qwq.end());
		for(int i=0;i<qwq.size();++i)
			res.push_back(qwq[i]);
		ans.push_back(res);
	}
	int flag=1;
	for(int i=1;i<=n;++i)
		if(a[i]) flag=0;
	if(flag)
	{
		puts("YES");
		for(int i=0;i<ans.size();++i)
		{
			printf("%d\n",ans[i].size());
			for(int j=0;j<ans[i].size();++j)
				printf("%d ",ans[i][j]);
			puts("");
		}
	}
	else
	{
		puts("NO");
		dfs2(1);
		write(sm[1]);
	}
	return 0;
}

inline void add(int u,int v)
{
	e[++tot]=(Edge){v,head[u]};
	head[u]=tot;
}

void dfs(int u,int f)
{
	fa[u]=f;dep[u]=dep[f]+1;
	for(int i=head[u];i;i=e[i].ne)
	{
		int v=e[i].v;
		if(v==f) continue;
		dfs(v,u);
	}
}

inline int lca(int x,int y)
{
	while(x!=y)
	{
		if(dep[x]<dep[y])
			swap(x,y);
		x=fa[x];
	}
	return x;
}

inline void work(int x,int y)
{
	qwq.clear();
	qwq.push_back(x);
	while(x!=y)
	{
		a[x]^=1;x=fa[x];
		qwq.push_back(x);
	}
}

void dfs2(int u)
{
	int sum=0;sm[u]=a[u];
	for(int i=head[u];i;i=e[i].ne)
	{
		int v=e[i].v;
		if(v==fa[u]) continue;
		dfs2(v);
		sm[u]+=sm[v];
		sum+=a[v];
	}
	if(sum&&a[u])
		sum--,sm[u]--;
	sm[u]-=sum/2;
}