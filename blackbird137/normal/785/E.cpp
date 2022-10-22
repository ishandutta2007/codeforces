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

#define lowbit(x) (x&(-x))
#define mid ((l+r)>>1)
#define fan(x) (((x-1)^1)+1)
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
int n,m,a[N],cnt;
long long ans;

vector<long long> val;
vector<int> lc,rc;

inline void add(int x,int y,int v);
inline long long getsum(int x,int l,int r);
inline long long query(int x,int y,int l,int r);
void update(int x,int l,int r,int p,int v);
long long qquery(int x,int l,int r,int L,int R);
inline void pushup(int x);

signed main()
{
	n=read();m=read();cnt=n;
	for(int i=0;i<=n;++i)
	{
		val.push_back(0);
		lc.push_back(0);
		rc.push_back(0);
	}
	for(int i=1;i<=n;++i)
	{
		a[i]=i;
		add(i,i,1);
	}
	for(int i=1;i<=n;++i)
		ans+=query(1,i-1,a[i]+1,n);
	while(m--)
	{
		int x=read(),y=read();
		if(y<x) swap(x,y);
		ans-=query(x+1,y,1,a[x]-1);
		ans-=query(x,y-1,a[y]+1,n);
		if(a[x]>a[y]) ans++;
		add(x,a[x],-1);add(y,a[y],-1);
		swap(a[x],a[y]);
		add(x,a[x],1);add(y,a[y],1);
		ans+=query(x+1,y,1,a[x]-1);
		ans+=query(x,y-1,a[y]+1,n);
		if(a[x]>a[y]) ans--;
		printf("%lld\n",ans);
	}
	return 0;
}

inline void add(int x,int y,int v)
{
	for(;x<=n;x+=lowbit(x))
		update(x,1,n,y,v);
}

inline long long getsum(int x,int l,int r)
{
	long long res=0;
	for(;x;x-=lowbit(x))
		res=res+qquery(x,1,n,l,r);
	return res;
}

inline long long query(int x,int y,int l,int r)
{
	if(x>y||l>r) return 0;
	return getsum(y,l,r)-getsum(x-1,l,r);
}

void update(int x,int l,int r,int p,int v)
{
	if(l==r)
	{
		if(v>0) val[x]++;
		else val[x]--;
		return;
	}
	if(p<=mid)
	{
		if(lc[x]==0)
		{
			lc[x]=++cnt;
			val.push_back(0);
			lc.push_back(0);
			rc.push_back(0);
		}
		update(lc[x],l,mid,p,v);
	}
	else
	{
		if(rc[x]==0)
		{
			rc[x]=++cnt;
			val.push_back(0);
			lc.push_back(0);
			rc.push_back(0);
		}
		update(rc[x],mid+1,r,p,v);
	}
	pushup(x);
}

long long qquery(int x,int l,int r,int L,int R)
{
	if(L<=l&&r<=R) return val[x];
	long long res=0;
	if(L<=mid&&lc[x]) res=res+qquery(lc[x],l,mid,L,R);
	if(mid+1<=R&&rc[x]) res=res+qquery(rc[x],mid+1,r,L,R);
	return res;
}

inline void pushup(int x)
{
	val[x]=val[lc[x]]+val[rc[x]];
}