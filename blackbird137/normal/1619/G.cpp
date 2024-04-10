// Problem: G. Unusual Minesweeper
// Contest: Codeforces Round #762 (Div. 3)
// URL: https://codeforces.com/contest/1619/problem/G
// Memory Limit: 256 MB
// Time Limit: 2000 ms

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
#define INF 0x3f3f3f3f3f3f3f3f

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

namespace Codeforces
{
	#define YES puts("Yes")
	#define NO puts("NO")
	#define OUT_YN(o) puts((o)?"Yes":"No")
	#define ENDL puts("")
	#define y1 y1__
	const int mod=998244353;
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
	inline int gcd(int a,int b)
	{
		return b==0?a:gcd(b,a%b);
	}
}

using namespace Codeforces;

const int N=5e5+5;
int t,n,k,m,b[N];

pair<int,int> c[N];

struct Node
{
	int x,y,k;
}a[N];

vector<int> l[N],h[N];

struct DSU
{
	int fa[N],siz[N],mn[N];
	inline void init(int x)
	{
		for(int i=1;i<=x;++i)
			fa[i]=i,siz[i]=1,mn[i]=a[i].k;
	}
	int find(int x)
	{
		return fa[x]==x?x:fa[x]=find(fa[x]);
	}
	bool merge(int x,int y)
	{
		int f1=find(x),f2=find(y);
		if(f1==f2) return 0;
		fa[f1]=f2;siz[f2]+=siz[f1];
		mn[f2]=min(mn[f2],mn[f1]);
		return 1;
	}
}dsu;

inline bool check(int x)
{
	int num=0;
	for(int i=1;i<=n;++i)
		if(i==dsu.find(i)&&dsu.mn[i]>x)
			++num;
	return num<=x+1;
}

signed main()
{
	t=read();
	while(t--)
	{
		n=read();k=read();m=0;
		for(int i=1;i<=n;++i)
		{
			a[i].x=read();
			a[i].y=read();
			a[i].k=read();
			b[++m]=a[i].x;
			b[++m]=a[i].y;
		}
		dsu.init(n);
		sort(b+1,b+1+m);
		for(int i=1;i<=n;++i)
		{
			a[i].x=lower_bound(b+1,b+1+m,a[i].x)-b;
			a[i].y=lower_bound(b+1,b+1+m,a[i].y)-b;
			h[a[i].x].push_back(i);
			l[a[i].y].push_back(i);
		}
		for(int i=1;i<=m;++i)
		{
			int len=h[i].size();
			for(int j=0;j<len;++j)
				c[j+1]=mp(b[a[h[i][j]].y],h[i][j]);
			sort(c+1,c+1+len);
			for(int j=2;j<=len;++j)
				if(c[j].fi-c[j-1].fi<=k)
					dsu.merge(c[j].se,c[j-1].se);
		}
		for(int i=1;i<=m;++i)
		{
			int len=l[i].size();
			for(int j=0;j<len;++j)
				c[j+1]=mp(b[a[l[i][j]].x],l[i][j]);
			sort(c+1,c+1+len);
			for(int j=2;j<=len;++j)
				if(c[j].fi-c[j-1].fi<=k)
					dsu.merge(c[j].se,c[j-1].se);
		}
		for(int i=1;i<=m;++i)
		{
			h[i].clear();
			l[i].clear();
		}
		int l=0,r=n,res=-1;
		while(l<=r)
		{
			if(check(mid))
				res=mid,r=mid-1;
			else l=mid+1;
		}
		write(res);puts("");
	}
	return 0;
}