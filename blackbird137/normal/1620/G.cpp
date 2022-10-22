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
 
inline void write(long long x)
{
	if(x<0) putchar('-'),x=-x;
	if(x/10) write(x/10);
	putchar((char)(x%10)+'0');
}
 
template<typename T>inline T Abs(T a){return a>0?a:-a;};
template<typename T,typename TT>inline T Min(T a,TT b){return a<b?a:b;}
template<typename T,typename TT> inline T Max(T a,TT b){return a<b?b:a;}
 
const int N=23,M=1e5+5,mod=998244353;
int n,m,sm[N+5][30],nm[(1<<N)+5],mn[30],dp[(1<<N)+5][2];
char s[M];
 
signed main()
{
	n=read();
	for(int i=1;i<=n;++i)
	{
		scanf("%s",s+1);
		m=strlen(s+1);
		for(int j=1;j<=m;++j)
			sm[i][s[j]-'a']++;
	}
	for(int i=1;i<(1<<n);++i)
	{
		int sum=0,tmp=1;
		for(int j=0;j<26;++j)
			mn[j]=1e9;
		for(int j=0;j<n;++j)
			if((i>>j)&1)
			{
				sum^=1;
				for(int k=0;k<26;++k)
					mn[k]=min(mn[k],sm[j+1][k]);
			}
		for(int j=0;j<26;++j)
			tmp=tmp*1ll*(mn[j]+1)%mod;
		dp[i][sum]=tmp;
	}
	for(int i=0;i<n;++i)
		for(int j=0;j<(1<<n);++j)
			if((j>>i)&1)
			{
				dp[j][0]=(dp[j][0]+dp[j^(1<<i)][0])%mod;
				dp[j][1]=(dp[j][1]+dp[j^(1<<i)][1])%mod;
			}
	long long ans=0;
	for(int i=1;i<(1<<n);++i)
	{
		int tmp=(dp[i][1]-dp[i][0]+mod)%mod;
		int s1=0,s2=0;
		for(int j=0;j<n;++j)
			if((i>>j)&1)
				s1++,s2+=j+1;
		ans^=s1*1ll*s2*tmp;
	}
	write(ans);
	return 0;
}