#include<cstdio>
#include<algorithm>
#define ll long long
#define N 400010
#define ls (now<<1)
#define rs (now<<1|1)
#define mid ((l+r)>>1)
using namespace std;
const int mod=998244353;
inline int Mod(int a){return a<mod?a:a-mod;}
ll fac[N],ifac[N],s;
int t[N],n,m,a,b[N],len,mx,ans;
ll fastpow(ll a,int b)
{
	ll s=1;
	while(b)
	{
		if(b&1) s=s*a%mod;
		a=a*a%mod, b>>=1;
	}
	return s;
}
namespace seg
{
	int tr[N<<2];
	int query(int l,int r,int now,int w)
	{
		if(l>w) return 0;
		if(r<=w) return tr[now];
		return query(l,mid,ls,w)+query(mid+1,r,rs,w);
	}
	void update(int now)
	{
		tr[now]=tr[ls]+tr[rs];
	}
	void modify(int l,int r,int now,int w)
	{
		if(l==r) {tr[now]=t[l];return;}
		if(w<=mid) modify(l,mid,ls,w);
		else modify(mid+1,r,rs,w);
		update(now);
	}
	void build(int l,int r,int now)
	{
		if(l==r) {tr[now]=t[l];return;}
		build(l,mid,ls);
		build(mid+1,r,rs);
		update(now);
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	len=n+m;fac[0]=ifac[0]=s=1;
	for(int i=1;i<=len;i++) fac[i]=fac[i-1]*i%mod;
	ifac[len]=fastpow(fac[len],mod-2);
	for(int i=len-1;i;i--) ifac[i]=ifac[i+1]*(i+1)%mod;
	for(int i=1;i<=n;i++) scanf("%d",&a),t[a]++,mx=max(mx,a);
	for(int i=1;i<=m;i++) scanf("%d",&b[i]),mx=max(mx,b[i]);
	seg::build(1,mx,1);
	for(int i=1;i<=mx;i++) s=s*ifac[t[i]]%mod;
	for(int i=1;i<=m;i++)
	{
		a=b[i];
		ans=(ans+seg::query(1,mx,1,a-1)*s%mod*fac[n-i])%mod;
		if(t[a])
		{
			if(i==n&&i<m) {ans=Mod(ans+1);break;}
			if(t[a]>1) s=s*t[a]%mod;
			t[a]--;
			seg::modify(1,mx,1,a);
		}
		else break;
	}
	printf("%d",ans);
}