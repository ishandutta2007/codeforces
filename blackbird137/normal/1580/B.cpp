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

const int N=105;
int n,m,k,mod,jc[N],C[N][N],dp[N][N][N];

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
	for(int i=0;i<=x;++i)
		for(int j=0;j<=i;++j)
			if(j==0) C[i][j]=1;
			else C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
}

signed main()
{
	n=read();m=read();k=read();mod=read();
	init(100);
	for(int i=0;i<=n;++i)
		dp[0][i][0]=1;
	for(int i=1;i<=n;++i)
	{
		dp[i][1][1]=jc[i];
		for(int j=i+1;j<=n;++j)
			dp[i][j][0]=jc[i];
		for(int j=2;j<=i;++j)
			for(int p=0;p<=i-j+1;++p)
			{
				if(p-(j==1)>=0) dp[i][j][p]=dp[i-1][j-1][p-(j==1)]*2%mod;
				for(int l=2;l<=i-1;++l)
					for(int t=0;t<=p+(j==1);++t)
						if(dp[l-1][j-1][t]&&dp[i-l][j-1][p-t-(j==1)])
							dp[i][j][p]=(dp[i][j][p]+dp[l-1][j-1][t]*dp[i-l][j-1][p-t-(j==1)]%mod*C[i-1][l-1]%mod)%mod;
			}
	}
		
				
	write(dp[n][m][k]);
	return 0;
}