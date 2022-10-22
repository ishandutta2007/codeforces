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
#define lowbit(x) (x&(-x))
#define mid ((l+r)>>1)
#define lc (x<<1)
#define rc (x<<1|1)
#define max Max
#define min Min
#define abs Abs

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
template<typename T,typename TT>inline T Min(T a,TT b){return a>b?b:a;}
template<typename T,typename TT> inline T Max(T a,TT b){return a>b?a:b;}

const int N=5e5+5,K=65,mod=1e9+7;
int t,n,a[N],sum[K];

signed main()
{
	t=read();
	while(t--)
	{
		n=read();
		memset(sum,0,sizeof(sum));
		for(int i=1;i<=n;++i)
		{
			a[i]=read();
			for(int j=0;j<=60;++j)
				if((a[i]>>j)&1) sum[j]++;
		}
		int ans=0;
		for(int i=1;i<=n;++i)
		{
			int s1=0,s2=0;
			for(int j=0;j<=60;++j)
				if((a[i]>>j)&1) s1=(s1+sum[j]*((1ll<<j)%mod)%mod)%mod;
			for(int j=0;j<=60;++j)
				if((a[i]>>j)&1) s2=(s2+n*((1ll<<j)%mod)%mod)%mod;
				else s2=(s2+sum[j]*((1ll<<j)%mod)%mod)%mod;
			ans=(ans+s1*s2%mod)%mod;
		}
		printf("%lld\n",ans);
	}
	return 0;
}