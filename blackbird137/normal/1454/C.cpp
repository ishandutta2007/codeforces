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

inline int Abs(int a){return a>0?a:-a;};
inline int Min(int a,int b){return a>b?b:a;}
inline int Max(int a,int b){return a>b?a:b;}

const int N=2e5+5;
int t,n,vis[N],sum[N],ok[N];

signed main()
{
	t=read();
	while(t--)
	{
		n=read();
		for(int i=1;i<=n;++i)
			vis[i]=0,sum[i]=0,ok[i]=0;
		for(int i=1;i<=n;++i)
		{
			int a=read();
			if(vis[a]!=i-1)
				sum[a]++;
			vis[a]=i;ok[a]=1;
		}
		for(int i=1;i<=n;++i)
			if(vis[i]!=n)
				sum[i]++;
		int ans=1e18;
		for(int i=1;i<=n;++i)
			if(ok[i])
				ans=min(ans,sum[i]);
		printf("%lld\n",ans);
	}
	return 0;
}