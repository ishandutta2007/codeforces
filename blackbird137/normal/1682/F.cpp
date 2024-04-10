#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<random>
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

const int N=4e5+5,mod=1e9+7;
int n,q,a[N],b[N],m,c[N],s[N],ans[N];

inline int id(int x)
{
	return lower_bound(c+1,c+1+m,x)-c;
}

inline int ID(int x)
{
	return upper_bound(c+1,c+1+m,x)-c;
}

struct BIT
{
	int c[N];
	inline void add(int x,int v)
	{
		v%=mod;
		for(;x<=m;x+=lowbit(x))
			c[x]=(c[x]+v)%mod;
	}
	inline void upd(int l,int r,int v)
	{
		if(l>r) return;
		add(l,v);add(r+1,-v);
	}
	inline int query(int x)
	{
		int res=0;
		for(;x;x-=lowbit(x))
			res=(res+c[x])%mod;
		return res;
	}
	inline void clear()
	{
		for(int i=1;i<=n;++i)
			c[i]=0;
	}
}s1,s2;

signed main()
{
	n=read();q=read();
	for(int i=1;i<=n;++i)
		a[i]=read();
	for(int i=1;i<=n;++i)
		b[i]=read(),s[i]=s[i-1]+b[i],c[++m]=s[i];
	c[++m]=0;
	sort(c+1,c+1+m);
	m=unique(c+1,c+1+m)-c-1;
	for(int i=n;i>=1;--i)
	{
		if(b[i]>=0)
		{
			int l=id(s[i-1])-1;
			s1.upd(1,l,-a[i]*b[i]%mod);
			int r=ID(s[i-1]+b[i]);
			s1.upd(r,m,a[i]*b[i]%mod);
			s1.upd(l+1,r-1,(-2*s[i-1]%mod-b[i])*a[i]%mod);
			s2.upd(l+1,r-1,2*a[i]%mod);
		}
		else
		{
			int r=ID(s[i-1]);
			s1.upd(r,m,a[i]*b[i]%mod);
			int l=id(s[i-1]+b[i])-1;
			s1.upd(1,l,-a[i]*b[i]%mod);
			s1.upd(l+1,r-1,(2*s[i-1]%mod+b[i])*a[i]%mod);
			s2.upd(l+1,r-1,-2*a[i]%mod);
		}
		ans[i]=(s1.query(id(s[i-1]))+s[i-1]%mod*s2.query(id(s[i-1]))%mod)%mod;
	}
	while(q--)
	{
		int l=read(),r=read();
		write(((ans[l]-ans[r+1])%mod+mod)%mod);puts("");
	}
	return 0;
}