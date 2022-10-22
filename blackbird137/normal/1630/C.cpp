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

const int N=2e5+5;
int n,a[N],b[N],dp[N],mx[N],mxx[N],ans;

vector<int> hav[N];

struct Seg
{
	int val[N<<2];
	void build(int x,int l,int r)
	{
		val[x]=-1e9;
		if(l==r) return;
		build(lc,l,mid);
		build(rc,mid+1,r);
	}
	void update(int x,int l,int r,int p,int v)
	{
		if(l==r) return val[x]=v,void();
		if(p<=mid) update(lc,l,mid,p,v);
		else update(rc,mid+1,r,p,v);
		val[x]=max(val[lc],val[rc]);
	}
	int query(int x,int l,int r,int L,int R)
	{
		if(L>R) return -1e9;
		if(L<=l&&r<=R) return val[x];
		int res=-1e9;
		if(L<=mid) res=max(res,query(lc,l,mid,L,R));
		if(mid+1<=R) res=max(res,query(rc,mid+1,r,L,R));
		return res;
	}
}sum;

signed main()
{
	n=read();
	for(int i=1;i<=n;++i)
		a[i]=read(),mxx[i]=-1e9;
	sum.build(1,1,n);
	for(int i=1;i<=n;++i)
	{
		if(!b[a[i]])
			b[a[i]]=i;
		else
		{
			dp[i]=b[a[i]]-i-1;
			dp[i]=max(dp[i],mxx[a[i]]+i-1);
			dp[i]=max(dp[i],sum.query(1,1,n,b[a[i]]+1,i-1)+i-1);
			ans=max(ans,dp[i]);
		}
		mx[i]=max(mx[i-1],dp[i]);
		mxx[a[i]]=max(mxx[a[i]],mx[i-1]-i);
		sum.update(1,1,n,i,dp[i]-i);
	}
		
	write(ans);
	return 0;
}