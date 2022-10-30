#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
namespace io {
	const ll SIZE=(1<<21)+1;
	char ibuf[SIZE],*iS,*iT;
	char gc()
	{
		if(iS==iT) iT=(iS=ibuf)+fread(ibuf,1,SIZE,stdin);
		if(iS==iT) return EOF;
		return *iS++;
	}
	inline ll gi()
	{
		char c; ll x=0,f=1;
		for(;c<'0'||c>'9';c=gc())if(c=='-')f=-1;
		for(;c>='0'&&c<='9';c=gc())x=(x<<1)+(x<<3)+c-'0';
		return x*f;
	}
}
using io::gi;
const ll N=100005,qN=320;
ll n,w,amx,bmx=1,bel[N],b,s[qN][qN],tp[qN],pos[qN],ind=1,br[N];
ll a[N],add[qN];
pair<ll,ll> p[N];
#define fir first
#define sec second
#define top s[x][tp[x]]
#define dtp s[x][tp[x]-1]
#define Max(x) s[x][pos[x]]
void build(ll x)
{
	for(ll i=br[x-1]+1;i<=br[x];i++) a[i]+=add[x]*i;
	add[x]=pos[x]=tp[x]=0;
	for(ll i=br[x-1]+1;i<=br[x];i++)
	{
		while(tp[x]>1&&(a[i]-a[top])*(top-dtp)>=(a[top]-a[dtp])*(i-top))--tp[x];
		s[x][++tp[x]]=i;
	}
	for(pos[x]=1;pos[x]<tp[x]&&a[s[x][pos[x]+1]]>=a[s[x][pos[x]]];pos[x]++);
}
void update(ll x)
{
	for(;pos[x]<tp[x]&&a[s[x][pos[x]+1]]+add[x]*s[x][pos[x]+1]>=
		a[s[x][pos[x]]]+add[x]*s[x][pos[x]];pos[x]++);
}
void upd(ll r)
{
	ll y;
	for(y=1;y*b+1<=r;y++) ++add[y],update(y);
	for(ll l=(y-1)*b+1;l<=r;l++) a[l]+=l;
	build(bel[r]);
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("laofu.in","r",stdin);
#endif
	n=gi(),w=gi();
	for(ll i=1;i<=n;i++)
	{
		p[i].sec=gi(),p[i].fir=gi();
		amx=max(amx,p[i].sec);
		bmx=max(bmx,p[i].fir);
	}
	b=sqrt(amx);
	for(ll i=1;i<=amx;i++) bel[i]=(i-1)/b+1,br[i]=min(i*b,amx);
	sort(p+1,p+1+n);
	for(ll i=1;i<=bel[amx];i++) build(i);
	for(ll c=0;c<=bmx+1;c++)
	{
		for(;ind<=n&&c>p[ind].fir;++ind) upd(p[ind].sec);
		ll ans=0,ans2=0;
		for(ll i=1;i<=bel[amx];i++)
		{
			if(a[Max(i)]+add[i]*Max(i)>ans)
				ans=a[Max(i)]+add[i]*Max(i),ans2=Max(i);
		}
		printf("%lld %lld\n",ans+(ll)w*c*(n-ind+1),ans2);
	}
}