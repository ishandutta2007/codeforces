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

const int N=1e5+5;
int n,a[N];

inline int q_pow(int a,int b,int p)
{
	int c=1;
	while(b)
	{
		if(b&1) c=a*c%p;
		a=a*a%p;b>>=1;
	}
	return c;
}

inline bool check(int x)
{
	for(int i=2;i*i<=x;++i)
		if(x%i==0) return 0;
	return 1;
}

signed main()
{
	n=read();
	if(n==4)
	{
		puts("YES");
		puts("1");
		puts("3");
		puts("2");
		puts("4");
		return 0;
	}
	if(!check(n))
	{
		puts("NO");
		return 0;
	}
	puts("YES");
	a[1]=1;
	for(int i=2;i<=n-1;++i)
		a[i]=i*q_pow(i-1,n-2,n)%n;
	a[n]=n;
	for(int i=1;i<=n;++i)
		write(a[i]),puts("");
	return 0;
}