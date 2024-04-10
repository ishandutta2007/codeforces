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

const int N=2e5+5,mod=1e9+7;
int n,k,a,jc[N],inv[N];

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

inline int S(int n,int m)
{
	int res=0;
	for(int i=0;i<=m;++i)
		if(i%2==0) res=(res+inv[i]*inv[m-i]%mod*q_pow(m-i,n)%mod)%mod;
		else res=(res-inv[i]*inv[m-i]%mod*q_pow(m-i,n)%mod+mod)%mod;
	return res;
}

signed main()
{
	init(2e5);
	n=read();k=read();
	for(int i=1;i<=n;++i)
		a+=read();
	write(a%mod*(S(n,k)+(n-1)*S(n-1,k)%mod)%mod);
	return 0;
}