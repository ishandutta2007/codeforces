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
int t,n,la,lb,vis[N],rk1[N],rk2[N];

pair<int,int> a[N],b[N];

signed main()
{
	t=read();
	while(t--)
	{
		n=read();
		for(int i=1;i<=n;++i)
			a[i]=mp(read(),i);
		for(int i=1;i<=n;++i)
			b[i]=mp(read(),i);
		sort(a+1,a+1+n);
		sort(b+1,b+1+n);
		for(int i=1;i<=n;++i)
		{
			rk1[a[i].se]=i;
			rk2[b[i].se]=i;
		}
		la=lb=n;
		queue<int> qu;
		qu.push(a[n].se);
		qu.push(b[n].se);
		while(!qu.empty())
		{
			int x=qu.front();
			qu.pop();
			if(vis[x])
				continue;
			vis[x]=1;
			for(int i=rk1[x]+1;i<la;++i)
				qu.push(a[i].se);
			for(int i=rk2[x]+1;i<lb;++i)
				qu.push(b[i].se);
			la=min(la,rk1[x]);
			lb=min(lb,rk2[x]);
		}
		for(int i=1;i<=n;++i)
			write(vis[i]),vis[i]=0;
		puts("");
	}
	return 0;
}