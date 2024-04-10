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
int n,m,t[N],a[N],b[N],_next[N],ans;

signed main()
{
	n=read();m=read();
	for(int i=1;i<=n;++i) t[i]=read();
	for(int i=1;i<n;++i) a[i]=t[i+1]-t[i];
	for(int i=1;i<=m;++i) t[i]=read();
	for(int i=1;i<m;++i) b[i]=t[i+1]-t[i];
	_next[0]=-1;m--;n--;
	if(m==0)
	{
		printf("%lld\n",n+1);
		return 0;
	}
	for(int i=1;i<=m;++i)
	{
		int now=_next[i-1];
		while(now!=-1&&b[now+1]!=b[i]) now=_next[now];
		_next[i]=now+1;
	}
	for(int i=1,j=0;i<=n;++i)
	{
		while(j&&b[j+1]!=a[i]) j=_next[j];
		if(b[j+1]==a[i]) j++;
		if(j==m) ans++,j=_next[j];
	}
	printf("%lld\n",ans);
	return 0;
}