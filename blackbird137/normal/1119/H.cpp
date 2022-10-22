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

const int N=1e6+5,mod=998244353;
int n,k,x,y,z,f1[N],f2[N],f3[N],ans[N];

int XOR[2][2]={{1,1},{1,mod-1}},IXOR[2][2]={{499122177,499122177},{499122177,mod-499122177}};

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

inline void mul(int *a,int *b,int c[2][2],int ic[2][2],int n);
inline void FWT(int *a,int c[2][2],int n);

signed main()
{
	n=read();k=read();
	x=read();y=read();z=read();
	int all=0;
	for(int i=1;i<=n;++i)
	{
		int a=read(),b=read(),c=read();
		all^=a;b^=a;c^=a;
		f1[b]++;f2[c]++;f3[b^c]++;
	}
	FWT(f1,XOR,(1<<k));
	FWT(f2,XOR,(1<<k));
	FWT(f3,XOR,(1<<k));
	int inv2=q_pow(2,mod-2);
	int inv4=inv2*inv2%mod;
	for(int i=0;i<(1<<k);++i)
	{
		int c1=(n+f1[i]+f2[i]+f3[i])*inv4%mod,c2=(n+f1[i])*inv2%mod-c1,c3=(n+f2[i])*inv2%mod-c1,c4=(n+f3[i])*inv2%mod-c1;
		ans[i]=q_pow(x+y+z,c1)*q_pow(x+y-z,c2)%mod*q_pow(x-y+z,c3)%mod*q_pow(x-y-z,c4)%mod;ans[i]=(ans[i]+mod)%mod;
	}
	FWT(ans,IXOR,(1<<k));
	for(int i=0;i<(1<<k);++i)
		write(ans[i^all]),putchar(' ');
	return 0;
}

inline void mul(int *a,int *b,int c[2][2],int ic[2][2],int n)
{
	FWT(a,c,n);FWT(b,c,n);
	for(int i=0;i<n;++i)
		a[i]=a[i]*b[i]%mod;
	FWT(a,ic,n);
}

inline void FWT(int *a,int c[2][2],int n)
{
	for(int l=2;l<=n;l<<=1)
	{
		int len=l>>1;
		for(int i=0;i<n;i+=l)
			for(int k=i;k<i+len;++k)
			{
				int tmp=a[k];
				a[k]=(c[0][0]*tmp+c[0][1]*a[k+len])%mod;
				a[k+len]=(c[1][0]*tmp+c[1][1]*a[k+len])%mod;
			}
	}
}