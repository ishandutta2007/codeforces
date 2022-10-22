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
#define pb(x) push_back(x)
#define lowbit(x) ((x)&(-(x)))
#define fan(x) ((((x)-1)^1)+1)
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

const int N=1e6+5;
int t,n,m,a[N],b[N],s[N],mx[N],dp[N];

struct Seg
{
	int val[N<<2];
	void build(int x,int l,int r)
	{
		val[x]=-INF;
		if(l==r) return;
		build(lc,l,mid);
		build(rc,mid+1,r);
	}
	void update(int x,int l,int r,int p,int v)
	{
		if(l==r)
		{
			val[x]=max(val[x],v);
			return;
		}
		if(p<=mid) update(lc,l,mid,p,v);
		else update(rc,mid+1,r,p,v);
		val[x]=max(val[lc],val[rc]);
	}
	int query(int x,int l,int r,int L,int R)
	{
		if(L>R) return -INF;
		if(L<=l&&r<=R) return val[x];
		int res=-INF;
		if(L<=mid) res=max(res,query(lc,l,mid,L,R));
		if(mid+1<=R) res=max(res,query(rc,mid+1,r,L,R));
		return res;
	}
}p1,p2;

signed main()
{
	t=read();
	while(t--)
	{
		n=read();m=0;b[++m]=0;s[0]=0;
		for(int i=1;i<=n;++i)
		{
			a[i]=read();
			s[i]=s[i-1]+a[i];
			b[++m]=s[i];
		}
		sort(b+1,b+1+m);
		m=unique(b+1,b+1+m)-b-1;
		for(int i=0;i<=n;++i)
			s[i]=lower_bound(b+1,b+1+m,s[i])-b;
		p1.build(1,1,m);
		p2.build(1,1,m);
		for(int i=1;i<=m;++i)
			mx[i]=-INF;
		p1.update(1,1,m,s[0],0);
		p2.update(1,1,m,s[0],0);
		mx[s[0]]=0;
		for(int i=1;i<=n;++i)
		{
			int tmp=-INF;
			tmp=max(tmp,p1.query(1,1,m,1,s[i]-1)+i);
			tmp=max(tmp,p2.query(1,1,m,s[i]+1,m)-i);
			tmp=max(tmp,mx[s[i]]);dp[i]=tmp;
			p1.update(1,1,m,s[i],dp[i]-i);
			p2.update(1,1,m,s[i],dp[i]+i);
			mx[s[i]]=max(mx[s[i]],dp[i]);
		}
		write(dp[n]);puts("");
	}
	return 0;
}