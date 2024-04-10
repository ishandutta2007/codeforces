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

const int N=2e5+5,mod=1e9+7;
int t,n,m,sm[N][31],a[N],dp[N][2];

signed main()
{
	t=read();
	while(t--)
	{
		n=read();m=read();
		for(int i=1;i<=n+1;++i)
			for(int j=0;j<=30;++j)
				sm[i][j]=0;
		for(int i=1;i<=m;++i)
		{
			int l=read(),r=read(),x=read();
			for(int j=0;j<=30;++j)
				if(!((x>>j)&1))
					sm[l][j]++,sm[r+1][j]--;
		}
		for(int i=1;i<=n;++i)
		{
			a[i]=0;
			for(int j=0;j<=30;++j)
			{
				sm[i][j]+=sm[i-1][j];
				if(!sm[i][j]) a[i]|=(1<<j);
			}
		}
		int ans=0;
		for(int i=0;i<=30;++i)
		{
			for(int j=0;j<=n;++j)
				dp[j][0]=dp[j][1]=0;
			dp[0][0]=1;
			for(int j=1;j<=n;++j)
			{
				int p=((a[j]>>i)&1);
				dp[j][0]=(dp[j][0]+dp[j-1][p])%mod;
				dp[j][1]=(dp[j][1]+dp[j-1][1^p])%mod;
				dp[j][0]=(dp[j][0]+dp[j-1][0])%mod;
				dp[j][1]=(dp[j][1]+dp[j-1][1])%mod;
			}
			ans=(ans+(1<<i)*1ll*dp[n][1]%mod)%mod;
		}
		write(ans);puts("");
	}
	return 0;
}