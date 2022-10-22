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
#define pb(x) push_back(x)
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

const int N=305;
int n,a[N],b[N];

priority_queue<int> qu;
map<int,int> dp,vis;

inline void add(int x)
{
	if(vis[x])
		return;
	qu.push(x);
	vis[x]=1;
	dp[x]=INF;
}

signed main()
{
	n=read();
	for(int i=1;i<=n;++i)
		a[i]=read();
	for(int i=1;i<=n;++i)
		b[i]=read();
	for(int i=1;i<=n;++i)
	{
		add(a[i]);
		dp[a[i]]=min(dp[a[i]],b[i]);
	}
	while(!qu.empty())
	{
		int u=qu.top();
		qu.pop();
		for(int i=1;i<=n;++i)
		{
			int tmp=__gcd(u,a[i]);
			if(tmp==u) continue;
			add(tmp);dp[tmp]=min(dp[tmp],dp[u]+b[i]);
		}
	}
	if(!vis[1])
		puts("-1");
	else write(dp[1]);
	return 0;
}