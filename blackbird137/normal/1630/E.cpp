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

const int N=1e6+5,mod=998244353;
int t,n,a[N],jc[N],p1[N],p2[N];

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
		n=read();jc[0]=1;
		for(int i=1;i<=n;++i)
			jc[i]=jc[i-1]*i%mod,a[i]=0;
		for(int i=1;i<=n;++i)
			a[read()]++;
		int gcd=0;
		for(int i=1;i<=n;++i)
			gcd=__gcd(gcd,a[i]);
		if(gcd==n)
		{
			puts("1");
			continue;
		}
		for(int i=1;i<=gcd;++i)
			if(gcd%i==0)
			{
				int s1=0,s2=0,res=q_pow(jc[n/i-2],mod-2);
				for(int j=1;j<=n;++j)
					if(a[j])
					{
						res=res*jc[a[j]/i]%mod;
						s1=(s1+s2*(a[j]/i)*2%mod)%mod;
						s2=(s2+a[j]/i)%mod;
					}
				p2[i]=q_pow(res,mod-2)*(n/i-1)%mod*(n/i)%mod;
				p1[i]=q_pow(res,mod-2)*s1%mod*n%mod;
			}
		int ans1=0,ans2=0;
		for(int i=1;i<=n;++i)
		{
			int tmp=n/__gcd(n,i);
			if(gcd%tmp==0)
			{
				ans1=(ans1+p1[tmp])%mod;
				ans2=(ans2+p2[tmp])%mod;
			}
		}
		write(ans1*q_pow(ans2,mod-2)%mod);
		puts("");
	}
	return 0;
}