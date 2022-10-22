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

const int N=105;
int n,a[N],k,d;

signed main()
{
	n=read();k=read();
	int lim=k,mx=0;
	for(int i=1;i<=n;++i)
	{
		a[i]=read()-1;
		lim+=a[i]+1;
		mx=max(mx,a[i]);
	}
	if(lim/n>mx) d=lim/n;
	for(int l=1,r;l<=mx;l=r+1)
	{
		r=mx;
		for(int i=1;i<=n;++i)
			if(a[i]/l!=0)
				r=min(r,a[i]/(a[i]/l));
		int sum=n;
		for(int i=1;i<=n;++i)
			sum+=a[i]/r;
		if(l*sum<=lim)
			d=max(d,min(lim/sum,r));
	}
	write(d);
	return 0;
}