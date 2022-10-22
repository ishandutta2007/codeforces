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
int t,n,m,tg[N],f[N],du[N],flag;

vector<int> hv[N][2],ans;

struct edge
{
	int u,v;
}ee[N];

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

void dfs(int u,int fa)
{
	int p[2]={0,0};f[u]=fa;
	for(int i=head[u];i;i=e[i].ne)
	{
		int v=e[i].v;
		if(v==fa) continue;
		dfs(v,u);p[tg[v]]++;
		hv[u][tg[v]].push_back(v);
	}
	if(u!=1)
	{
		if(p[1]<=p[0])
			tg[u]=1,hv[u][1].push_back(u),p[1]++;
		else tg[u]=0,hv[u][0].push_back(u),p[0]++;
	}
	if(p[0]!=p[1]&&p[0]!=p[1]-1)
		flag=0;
}

signed main()
{
	t=read();
	while(t--)
	{
		n=read();m=0;tot=0;
		for(int i=1;i<=n;++i)
		{
			du[i]=0;head[i]=0;
			hv[i][0].clear();
			hv[i][1].clear();
		}
		for(int i=1;i<n;++i)
		{
			int u=read(),v=read();
			add(u,v);add(v,u);
			du[u]++;du[v]++;
		}
		flag=1;
		dfs(1,0);
		if(!flag)
		{
			puts("NO");
			continue;
		}
		puts("YES");
		for(int i=1;i<=n;++i)
			if(du[i]%2==0)
			{
				for(int j=0;j<hv[i][0].size();++j)
				{
					ee[++m]=(edge){hv[i][0][j],hv[i][1][j]};
					if(j!=hv[i][0].size()-1) ee[++m]=(edge){hv[i][1][j],hv[i][0][j+1]};
				}
			}
			else
			{
				for(int j=0;j<hv[i][0].size();++j)
				{
					ee[++m]=(edge){hv[i][1][j],hv[i][0][j]};
					ee[++m]=(edge){hv[i][0][j],hv[i][1][j+1]};
				}
			}
			
		for(int i=1;i<=n;++i)
			head[i]=0,du[i]=0;
		tot=0;
		for(int i=1;i<=m;++i)
		{
			du[ee[i].v]++;
			add(ee[i].u,ee[i].v);
		}
		queue<int> qu;
		ans.clear();
		for(int i=2;i<=n;++i)
			if(!du[i]) qu.push(i);
		while(!qu.empty())
		{
			int u=qu.front();
			qu.pop();ans.push_back(u);
			for(int i=head[u];i;i=e[i].ne)
			{
				int v=e[i].v;du[v]--;
				if(!du[v]) qu.push(v);
			}
		}
		for(int i=0;i<ans.size();++i)
			write(ans[i]),putchar(' '),write(f[ans[i]]),puts("");
	}
	return 0;
}