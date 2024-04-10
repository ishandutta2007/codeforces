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

const int N=3005,M=3e7+5,mod=1e9+7;
int n,m,dp[N][N],sm[N][N],Sm[N],f[N],jc[N],inv[N];

inline int q_pow(int a,int b)
{
	int c=1;
	while(b)
	{
		if(b&1) c=a*1ll*c%mod;
		a=a*1ll*a%mod;b>>=1;
	}
	return c;
}

inline void init(int x)
{
	jc[0]=1;
	for(int i=1;i<=x;++i)
		jc[i]=jc[i-1]*1ll*i%mod;
	inv[x]=q_pow(jc[x],mod-2);
	for(int i=x-1;i>=0;--i)
		inv[i]=inv[i+1]*1ll*(i+1)%mod;
}

inline int C(int n,int m)
{
	return n<m?0:jc[n]*1ll*inv[m]%mod*inv[n-m]%mod;
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

void dfs(int u,int fa)
{
	for(int i=head[u];i;i=e[i].ne)
	{
		int v=e[i].v;
		if(v==fa) continue;
		dfs(v,u);
	}
	for(int i=1;i<=n;++i)
	{
		dp[u][i]=1;
		for(int j=head[u];j;j=e[j].ne)
		{
			int v=e[j].v;
			if(v==fa) continue;
			dp[u][i]=dp[u][i]*1ll*sm[v][i]%mod;
		}
		sm[u][i]=(sm[u][i-1]+dp[u][i])%mod;
	}
}

inline int query(int x)
{
	if(x<=n) return Sm[x];
	int res=0;
	for(int i=1,j=x;i<=n;++i,j=j*1ll*(x-i+1)%mod)
		res=(res+f[i]*1ll*j%mod*inv[i]%mod)%mod;
	return res;
}

signed main()
{
	n=read();m=read();
	init(n);
	for(int i=2;i<=n;++i)
	{
		int u=read();
		add(i,u);add(u,i);
	}
	dfs(1,0);
	for(int i=1;i<=n;++i)
		Sm[i]=(Sm[i-1]+dp[1][i])%mod;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=i;++j)
			if((i-j)%2==0)
				f[i]=(f[i]+Sm[j]*1ll*C(i,j)%mod)%mod;
			else f[i]=(f[i]-Sm[j]*1ll*C(i,j)%mod+mod)%mod;
	write(query(m));
	return 0;
}