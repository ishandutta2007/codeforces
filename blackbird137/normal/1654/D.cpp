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

const int N=2e5+5,mod=998244353;
int t,n,m,a[N],ans[N];

struct Node
{
	int x,y;
	Node operator * (const Node &p)const
	{
		return (Node){x*p.x%mod,y*p.y%mod};
	}
}dp[N];

struct node
{
	int x,y;
	bool operator < (const node &p)const
	{
		return x<p.x;
	}
};

set<node> yz;

struct Edge
{
	int v,ne;
	Node w;
}e[N*2];
int head[N],tot;

inline void add(int u,int v,Node w)
{
	e[++tot]=(Edge){v,head[u],w};
	head[u]=tot;
}

void dfs(int u,int fa)
{
	for(int i=head[u];i;i=e[i].ne)
	{
		int v=e[i].v;
		if(v==fa) continue;
		vector<pair<int,int> > upd;
		int tmp=e[i].w.y;
		for(int j=2;j*j<=tmp;++j)
			if(tmp%j==0)
			{
				int sm=0;
				while(tmp%j==0)
					tmp/=j,++sm;
				upd.push_back(mp(j,sm)); 
			}
		if(tmp!=1) upd.push_back(mp(tmp,1));
		tmp=e[i].w.x;
		for(int j=2;j*j<=tmp;++j)
			if(tmp%j==0)
			{
				int sm=0;
				while(tmp%j==0)
					tmp/=j,++sm;
				upd.push_back(mp(j,-sm)); 
			}
		if(tmp!=1) upd.push_back(mp(tmp,-1));
		for(int j=0;j<upd.size();++j)
		{
			auto it=yz.find((node){upd[j].fi,0});
			if(it==yz.end())
			{
				ans[upd[j].fi]=max(ans[upd[j].fi],upd[j].se);
				yz.insert((node){upd[j].fi,upd[j].se});
			}
			else
			{
				node pp=*it;yz.erase(it);
				ans[pp.x]=max(ans[pp.x],pp.y+upd[j].se);
				yz.insert((node){pp.x,pp.y+upd[j].se});
			}
		}
		dp[v]=dp[u]*e[i].w;
		dfs(v,u);
		for(int j=0;j<upd.size();++j)
		{
			auto it=yz.find((node){upd[j].fi,0});
			node pp=*it;yz.erase(it);pp.y-=upd[j].se;
			yz.insert(pp);
		}
	}
}

inline int q_pow(int a,int b)
{
	int c=1;
	while(b)
	{
		if(b&1) c=a*c%mod;
		a=a*a%mod;b>>=1;
	}
	return c;
}

signed main()
{
	t=read();
	while(t--)
	{
		n=read();m=0;
		for(int i=1;i<n;++i)
		{
			int u=read(),v=read();
			int x=read(),y=read();
			int tmp=__gcd(x,y);
			x/=tmp;y/=tmp;
			add(u,v,(Node){y,x});
			add(v,u,(Node){x,y});
		}
		yz.clear();
		dp[1]=(Node){1,1};
		dfs(1,0);
		int Ans=0,ggg=1;
		for(int i=1;i<=n;++i)
			Ans=(Ans+dp[i].x*q_pow(dp[i].y,mod-2)%mod)%mod;
		for(int i=1;i<=n;++i)
			if(ans[i])
			{
				ggg=ggg*q_pow(i,ans[i])%mod;
				ans[i]=0;
			}
		Ans=Ans*ggg%mod;
		write(Ans);puts("");
		for(int i=1;i<=n;++i)
			head[i]=0;
		tot=0;
	}
	return 0;
}