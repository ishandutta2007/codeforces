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

const int N=5e5+5,mod=1e9+7;
int n,m,k,fa[N],cnt,ans[N];

inline int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}

signed main()
{
	n=read();m=read();
	for(int i=0;i<=m;++i) fa[i]=i;
	for(int i=1;i<=n;++i)
	{
		k=read();
		if(k==1)
		{
			int a=find(read()),b=find(0);
			if(a!=b) fa[a]=b,ans[++cnt]=i;
		}
		else
		{
			int a=find(read()),b=find(read());
			if(a!=b) fa[a]=b,ans[++cnt]=i;
		}
	}
	int sum=1;
	for(int i=1;i<=cnt;++i) sum=sum*2%mod;
	printf("%lld %lld\n",sum,cnt);
	for(int i=1;i<=cnt;++i) printf("%lld ",ans[i]);
	return 0;
}