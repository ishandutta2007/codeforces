#pragma GCC diagnostic error "-std=c++14"
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
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

const int N=1e5+5,LIM=30000;
int n,m,k,b[N*5],ans=2e9+5;

struct Node
{
	int w,p[6];
	bool operator < (const Node &x)const
	{
		return w<x.w;
	}
}a[N];

bitset<N> cnt[LIM+5],tmp;
vector<int> hav[N*5];

signed main()
{
	n=read();m=read();
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			a[i].p[j]=read();
			b[++k]=a[i].p[j];
		}
		a[i].w=read();
	}
	sort(a+1,a+1+n);
	sort(b+1,b+1+k);
	k=unique(b+1,b+1+k)-b-1;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
		{
			int p=lower_bound(b+1,b+1+k,a[i].p[j])-b;
			a[i].p[j]=p;hav[p].push_back(i);
		}
	for(int l=1,r;l<=n;l=r+1)
	{
		r=min(l+LIM-1,n);
		for(int i=l;i<=r;++i)
			cnt[i-l].reset();
		for(int i=1;i<=k;++i)
		{
			tmp.reset();
			for(int j=0;j<hav[i].size();++j)
				tmp[hav[i][j]]=1;
			for(int j=0;j<hav[i].size();++j)
				if(hav[i][j]>=l&&hav[i][j]<=r)
					cnt[hav[i][j]-l]|=tmp;
		}
		for(int i=l;i<=r;++i)
		{
			cnt[i-l]=(~cnt[i-l]);
			cnt[i-l][0]=0;
			int p=cnt[i-l]._Find_first();
			if(p>=1&&p<=n)
				ans=min(ans,a[i].w+a[p].w);
		}	
	}
	
	if(ans==2e9+5) ans=-1;
	write(ans);
	return 0;
}