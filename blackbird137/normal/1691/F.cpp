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

const int N=3e5+5,mod=1e9+7;
int n,k,F[N],jc[N],inv[N],siz[N],dp1[N],dp2[N];

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

inline void init(int x)
{
	jc[0]=1;
	for(int i=1;i<=x;++i)
		jc[i]=jc[i-1]*i%mod;
	inv[x]=q_pow(jc[x],mod-2);
	for(int i=x-1;i>=0;--i)
		inv[i]=inv[i+1]*(i+1)%mod;
}

inline int C(int n,int m)
{
	return n<m?0:jc[n]*inv[m]%mod*inv[n-m]%mod;
}

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
	int nm=0;siz[u]=1;F[u]=fa;
	for(int i=head[u];i;i=e[i].ne)
	{
		int v=e[i].v;
		if(v==fa) continue;
		dfs1(v,u);siz[u]+=siz[v];
		nm=(nm+C(siz[v],k))%mod;
		dp1[u]=(dp1[u]+dp1[v])%mod;
	}
	nm=(C(siz[u],k)-nm+mod)%mod;
	dp1[u]=(dp1[u]+siz[u]*nm%mod)%mod;
}

void dfs2(int u,int fa)
{
	int al1=C(n-siz[u],k),al2=dp2[u];
	for(int i=head[u];i;i=e[i].ne)
	{
		int v=e[i].v;
		if(v==fa) continue;
		al1=(al1+C(siz[v],k))%mod;
		al2=(al2+dp1[v])%mod;
	}
	for(int i=head[u];i;i=e[i].ne)
	{
		int v=e[i].v;
		if(v==fa) continue;
		int tmp=(al1-C(siz[v],k)+mod)%mod;
		tmp=(C(n-siz[v],k)-tmp+mod)%mod;
		dp2[v]=(al2-dp1[v]+mod+tmp*(n-siz[v])%mod)%mod;
		dfs2(v,u);
	}
}

signed main()
{
	n=read();k=read();
	init(n);
	for(int i=1;i<n;++i)
	{
		int u=read(),v=read();
		add(u,v);add(v,u);
	}
	dfs1(1,0);dfs2(1,0);
	int ans=0;
	for(int u=1;u<=n;++u)
	{
		int all=C(n,k);
		for(int i=head[u];i;i=e[i].ne)
		{
			int v=e[i].v;
			if(v==F[u]) continue;
			ans=(ans+dp1[v])%mod;
			all=(all-C(siz[v],k)+mod)%mod;
		}
		ans=(ans+dp2[u])%mod;
		all=(all-C(n-siz[u],k)+mod)%mod;
		ans=(ans+all*n%mod)%mod;
	}
	write(ans);
	return 0;
}