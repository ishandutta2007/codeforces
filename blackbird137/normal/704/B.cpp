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

const int N=5e3+5;
int n,s,e,a[N],b[N],c[N],d[N],dp[N][N];

signed main()
{
	n=read();s=read();e=read();
	for(int i=1;i<=n;++i)
	{
		int x=read();
		a[i]+=x;b[i]-=x;
		c[i]-=x;d[i]+=x;
	}
	for(int i=1;i<=n;++i)
		d[i]+=read();
	for(int i=1;i<=n;++i)
		b[i]+=read();
	for(int i=1;i<=n;++i)
		a[i]+=read();
	for(int i=1;i<=n;++i)
		c[i]+=read();
	memset(dp,0x3f,sizeof(dp));
	dp[0][0]=0;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=i;++j)
			if(i==s)
			{
				dp[i][j]=min(dp[i][j],dp[i-1][j]+a[i]);
				dp[i][j]=min(dp[i][j],dp[i-1][j-1]+c[i]);
			}
			else if(i==e)
			{
				dp[i][j]=min(dp[i][j],dp[i-1][j]+d[i]);
				dp[i][j]=min(dp[i][j],dp[i-1][j-1]+b[i]);
			}
			else
			{
				if(i<s||i<e||j>2) dp[i][j]=min(dp[i][j],dp[i-1][j-1]+b[i]+c[i]);
				dp[i][j]=min(dp[i][j],dp[i-1][j+1]+a[i]+d[i]);
				if(i<e||j>1) dp[i][j]=min(dp[i][j],dp[i-1][j]+c[i]+d[i]);
				if(i<s||j>1) dp[i][j]=min(dp[i][j],dp[i-1][j]+a[i]+b[i]);
			}
	/*for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=i;++j)
			printf("%d ",dp[i][j]);
		puts("");
	}*/
	write(dp[n][1]);
	return 0;
}