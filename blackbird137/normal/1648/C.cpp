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

const int N=5e5+5,M=400000,mod=998244353;
int n,m,a[N],b[N],c[N],jc[N],inv[N],ans;

struct Seg
{
	int v1[N<<2],v2[N<<2];
	void build(int x,int l,int r)
	{
		if(l==r)
		{
			v1[x]=inv[c[l]];
			v2[x]=c[l];
			return;
		}
		build(lc,l,mid);
		build(rc,mid+1,r);
		v1[x]=v1[lc]*v1[rc]%mod;
		v2[x]=v2[lc]+v2[rc];
	}
	void update(int x,int l,int r,int p)
	{
		if(l==r)
		{
			v1[x]=inv[c[l]];
			v2[x]=c[l];
			return;
		}
		if(p<=mid) update(lc,l,mid,p);
		else update(rc,mid+1,r,p);
		v1[x]=v1[lc]*v1[rc]%mod;
		v2[x]=v2[lc]+v2[rc];
	}
	int query1(int x,int l,int r,int L,int R)
	{
		if(L>R) return 1;
		if(L<=l&&r<=R) return v1[x];
		int res=1;
		if(L<=mid) res=res*query1(lc,l,mid,L,R)%mod;
		if(mid+1<=R) res=res*query1(rc,mid+1,r,L,R)%mod;
		return res;
	}
	int query2(int x,int l,int r,int L,int R)
	{
		if(L>R) return 0;
		if(L<=l&&r<=R) return v2[x];
		int res=0;
		if(L<=mid) res+=query2(lc,l,mid,L,R);
		if(mid+1<=R) res+=query2(rc,mid+1,r,L,R);
		return res;
	}
}sum;

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

signed main()
{
	n=read();m=read();
	for(int i=1;i<=n;++i)
	{
		a[i]=read();
		c[a[i]]++;
	}
	for(int i=1;i<=m;++i)
		b[i]=read();
	jc[0]=1;inv[0]=1;
	for(int i=1;i<=M;++i)
	{
		jc[i]=jc[i-1]*i%mod;
		inv[i]=q_pow(jc[i],mod-2);
	}
	sum.build(1,1,M);
	int lim=min(n,m),flag=1;
	for(int i=1;i<=lim;++i)
	{
		int tmp=sum.query1(1,1,M,1,b[i]-1);
		tmp=tmp*sum.query2(1,1,M,1,b[i]-1)%mod;
		int tmp2=sum.query1(1,1,M,b[i],M);
		tmp2=tmp2*jc[n-i]%mod;
		ans=(ans+tmp*tmp2%mod)%mod;
		if(c[b[i]]==0)
		{
			flag=0;
			break;
		}
		c[b[i]]--;
		sum.update(1,1,M,b[i]);
	}
	if(flag&&n<m)
		ans=(ans+1)%mod;
	write(ans);
	return 0;
}