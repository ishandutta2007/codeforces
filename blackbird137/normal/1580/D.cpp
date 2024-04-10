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
#define mid ((l+r)>>1)
#define pb(x) push_back(x)
#define lowbit(x) ((x)&(-(x)))
#define fan(x) ((((x)-1)^1)+1)
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

const int N=5e3+5;
int n,m,a[N],lc[N],rc[N],dp[N][N],tmp[N],st[N],siz[N],top;

void dfs(int u)
{
	siz[u]=1;
	dp[u][0]=0;
	dp[u][1]=0;
	if(lc[u])
	{
		int v=lc[u],w=a[lc[u]]-a[u];dfs(v);
		for(int i=0;i<=n;++i)
			tmp[i]=-INF;
		for(int i=0;i<=siz[u];++i)
			for(int j=0;j<=siz[v];++j)
				tmp[i+j]=max(tmp[i+j],dp[u][i]+dp[v][j]+j*(m-j)*w);
		siz[u]+=siz[v];
		for(int i=0;i<=n;++i)
			dp[u][i]=tmp[i];
	}
	if(rc[u])
	{
		int v=rc[u],w=a[rc[u]]-a[u];dfs(v);
		for(int i=0;i<=n;++i)
			tmp[i]=-INF;
		for(int i=0;i<=siz[u];++i)
			for(int j=0;j<=siz[v];++j)
				tmp[i+j]=max(tmp[i+j],dp[u][i]+dp[v][j]+j*(m-j)*w);
		siz[u]+=siz[v];
		for(int i=0;i<=n;++i)
			dp[u][i]=tmp[i];
	}
}

signed main()
{
	n=read();m=read();
	for(int i=1;i<=n;++i)
		a[i]=read();
	for(int i=0;i<=n;++i)
		for(int j=0;j<=n;++j)
			dp[i][j]=-INF;
	st[++top]=1;
	int rt=1,mn=a[1];
	for(int i=2;i<=n;++i)
	{
		int ls=0;
		while(top&&a[st[top]]>a[i])
			ls=st[top--];
		if(ls) lc[i]=ls;
		if(top) rc[st[top]]=i;
		st[++top]=i;
		if(a[i]<mn) mn=a[i],rt=i;
	}
	dfs(rt);
	write(dp[rt][m]);
	return 0;
}