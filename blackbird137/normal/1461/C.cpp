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

const int N=1e5+5;
int t,n,m,a[N],mmax;
double ans;

signed main()
{
	t=read();
	while(t--)
	{
		n=read();m=read();
		mmax=0;ans=1;
		for(int i=1;i<=n;++i)
			a[i]=read();
		for(int i=n;i>=1;--i)
			if(a[i]!=i)
			{
				mmax=i;
				break;
			}
		
		for(int i=1;i<=m;++i)
		{
			int x=read();
			double y;
			scanf("%lf",&y);
			if(x>=mmax) ans*=(1-y);
		}
		if(mmax==0)
		{
			printf("1\n");
			continue;
		}
		printf("%.6lf\n",1-ans);
	}
	return 0;
}