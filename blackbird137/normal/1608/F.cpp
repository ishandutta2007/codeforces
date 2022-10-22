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
#define lowbit(x) (x&(-x))
#define fan(x) (((x-1)^1)+1)
#define mp(x,y) make_pair(x,y)
#define clr(f,n) memset(f,0,sizeof(int)*(n))
#define cpy(f,g,n) memcpy(f,g,sizeof(int)*(n))
#define INF 0x3f3f3f3f

using namespace std;

namespace fastIO
{
    #define BUF_SIZE 100000
    bool IOerror=0;
    inline char nc()
	{
        static char buf[BUF_SIZE],*p1=buf+BUF_SIZE,*pend=buf+BUF_SIZE;
        if(p1==pend)
		{
            p1=buf;
            pend=buf+fread(buf,1,BUF_SIZE,stdin);
            if(pend==p1)
			{
                IOerror=1;
                return -1;
            }
        }
        return *p1++;
    }
    inline bool blank(char ch)
	{
        return ch==' '||ch=='\n'||ch=='\r'||ch=='\t';
    }
    inline int read()
	{
		int ans=0,f=1;
		char c=nc();
		while(c>'9'||c<'0'){if(c=='-')f=-1;c=nc();}
		while(c>='0'&&c<='9'){ans=ans*10+c-'0';c=nc();}
		return ans*f;
	}
    #undef BUF_SIZE
};

using namespace fastIO;

inline void write(int x)
{
	if(x<0) putchar('-'),x=-x;
	if(x/10) write(x/10);
	putchar((char)(x%10)+'0');
}

template<typename T>inline T Abs(T a){return a>0?a:-a;};
template<typename T,typename TT>inline T Min(T a,TT b){return a<b?a:b;}
template<typename T,typename TT> inline T Max(T a,TT b){return a<b?b:a;}

const int N=2005,K=105,mod=998244353;
int n,k,l[N],r[N],dp[2][N][N],sm[2][N][N],jc[N],inv[N];

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

signed main()
{
	init(2000);
	n=read();k=read();
	for(int i=1;i<=n;++i)
	{
		int x=read();
		l[i]=max(0,x-k);
		r[i]=min(i,x+k);
	}
	dp[0][0][0]=1;
	sm[0][0][0]=1;
	for(int I=1,i=1;I<=n;++I,i^=1)
	{
		for(int j=0;j<=I;++j)
			for(int k=l[I];k<=r[I]&&k<=j;++k)
			{
				dp[i][j][k]=(dp[i][j][k]+dp[i^1][j][k]*j%mod)%mod;
				if(j) dp[i][j][k]=(dp[i][j][k]+dp[i^1][j-1][k])%mod;
				if(j&&k) dp[i][j][k]=(dp[i][j][k]+sm[i^1][j-1][min(k-1,r[I-1])]*inv[j-k]%mod)%mod;
				sm[i][j][k]=dp[i][j][k]*jc[j-k]%mod;
				if(k) sm[i][j][k]=(sm[i][j][k]+sm[i][j][k-1])%mod;
			}
		for(int j=0;j<=I-1;++j)
			for(int k=l[I-1];k<=r[I-1]&&k<=j;++k)
				dp[i^1][j][k]=sm[i^1][j][k]=0;
	}
	int ans=0;
	for(int i=0;i<=n;++i)
		for(int j=l[n];j<=r[n]&&j<=i;++j)
			ans=(ans+dp[n&1][i][j]*jc[n-j]%mod*inv[n-i]%mod)%mod;
	write(ans);
	return 0;
}