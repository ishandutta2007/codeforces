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

inline void write(int x)
{
	if(x<0) putchar('-'),x=-x;
	if(x/10) write(x/10);
	putchar((char)(x%10)+'0');
}

template<typename T>inline T Abs(T a){return a>0?a:-a;};
template<typename T,typename TT>inline T Min(T a,TT b){return a<b?a:b;}
template<typename T,typename TT> inline T Max(T a,TT b){return a<b?b:a;}

const int N=2e6+5,mod=1e9+7;
int n,k,a[N],now,b[N],add[N],m,pri[N],vis[N],miu[N],pw[N];

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
	miu[1]=1;
	for(int i=2;i<=x;++i)
	{
		if(!vis[i])
			pri[++m]=i,miu[i]=-1;
		for(int j=1;j<=m;++j)
		{
			if(pri[j]*i>x)
				break;
			vis[pri[j]*i]=1;
			if(i%pri[j]==0)
			{
				miu[i*pri[j]]=0;
				break;
			}
			miu[i*pri[j]]=-miu[i];
		}
	}
	pw[0]=0;
	for(int i=1;i<=x;++i)
		pw[i]=q_pow(i,n);
	for(int i=x;i>=1;--i)
		pw[i]=(pw[i]-pw[i-1]+mod)%mod;
}

inline int query(int x,int y)
{
	return (pw[y]*1ll*miu[x]+mod)%mod;
}

signed main()
{
	n=read();k=read();
	init(k);
	for(int i=1;i<=k;++i)
		for(int j=i;j<=k;j+=i)
			add[j]=(add[j]+query(i,j/i))%mod;
	int ans=0,now=0;
	for(int i=1;i<=k;++i)
	{
		now=(now+add[i])%mod;
		ans=(ans+(now^i))%mod;
	}
	write(ans);
	return 0;
}