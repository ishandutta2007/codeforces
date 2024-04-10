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

const int N=2e5+5;
int t,n,a[N];

signed main()
{
	t=read();
	while(t--)
	{
		n=read();
		for(int i=1;i<=n;++i)
			a[i]=read();
		int mmax=0,pos=-1;
		for(int i=2;i<=n-1;++i)
			if(abs(a[i]-a[i-1])+abs(a[i]-a[i+1])-abs(a[i+1]-a[i-1])>mmax)
			{
				mmax=abs(a[i]-a[i-1])+abs(a[i]-a[i+1])-abs(a[i+1]-a[i-1]);
				pos=i;
			}
		if(abs(a[1]-a[2])>mmax) mmax=abs(a[1]-a[2]),pos=1;
		if(abs(a[n]-a[n-1])>mmax) mmax=abs(a[n]-a[n-1]),pos=n;
		if(pos==1) a[1]=a[2];
		else if(pos==n) a[n]=a[n-1];
		else a[pos]=(a[pos-1]+a[pos+1])/2;
		int res=0;
		for(int i=2;i<=n;++i)
			res+=abs(a[i]-a[i-1]);
		printf("%lld\n",res);
	}
	return 0;
}