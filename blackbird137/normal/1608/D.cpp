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

const int N=1e5+5,_LIM_=1e5,mod=998244353;
int n,la,lb,lc,ra,rb,rc,jc[N],inv[N],ans;
char opt[5];

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

inline void init()
{
	jc[0]=1;
	for(int i=1;i<=_LIM_;++i)
		jc[i]=jc[i-1]*i%mod;
	inv[_LIM_]=q_pow(jc[_LIM_],mod-2);
	for(int i=_LIM_-1;i>=0;--i)
		inv[i]=inv[i+1]*(i+1)%mod;
}

inline int C(int n,int m)
{
	return n<m?0:jc[n]*inv[m]%mod*inv[n-m]%mod;
}

signed main()
{
	init();
	n=read();
	int A=0,B=0,c=0;
	for(int i=1;i<=n;++i)
	{
		scanf("%s",opt+1);
		if(opt[1]=='W') la++;
		if(opt[1]=='B') lb++;
		if(opt[1]=='?') lc++;
		if(opt[2]=='W') ra++;
		if(opt[2]=='B') rb++;
		if(opt[2]=='?') rc++;
		if(opt[1]=='W'&&opt[2]=='W') A++;
		if(opt[1]=='B'&&opt[2]=='B') B++;
		if(opt[1]=='?'&&opt[2]=='?') c++;
	}
	for(int i=0;i<=lc;++i)
	{
		int j=rb+rc-la-i;
		if(j>=0&&j<=rc)
			ans=(ans+C(lc,i)*C(rc,j)%mod)%mod;
	}
	if(A==0&&B==0)
	{
		ans=(ans-q_pow(2,c)+mod)%mod;
		if(lb==0&&ra==0) ans=(ans+1)%mod;
		if(la==0&&rb==0) ans=(ans+1)%mod;
	}
	write(ans);
	return 0;
}