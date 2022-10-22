#include<cstdio>
#include<algorithm>
#include<cmath>
#define ll long long
ll readll(){
	ll x=0,w=1;char c=getchar();
	for(;c<'0'||c>'9';(c-'-')||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=(x<<1)+(x<<3)+(c^48),c=getchar());
	return x*w;
}
ll add(ll a){
	ll maxx=0,minn=9;
	while(a){
		ll x=a%10;
		maxx=std::max(maxx,x);
		minn=std::min(minn,x);
		a/=10;
	}
	return maxx*minn;
}
ll n,a,b,m;
ll aa[222222];
ll ans(ll u,ll d) {
	if(u<d) {
	return u*m+(d-u)*b;
	}
	else {
	return d*m+(u-d)*a;
	}
}
ll ans(ll mid) {
	ll u=0,d=0;
	for(ll i=1;i<=n;i++)
	if(aa[i]<mid){
		u+=mid-aa[i];
	}
	else {
		d+=aa[i]-mid;
	}
	return ans(u,d);
}
int main(){
	//return 0;
	//freopen("e.in","r",stdin);
	//freopen("e.out","w",stdout);
	n=readll(),a=readll(),b=readll(),m=readll();
	if(m>a+b)m=a+b;
	for(ll i=1;i<=n;i++)aa[i]=readll();
	std::sort(aa+1,aa+n+1);
	ll minn=0x3f3f3f3f3f3f3f3f;
//	for(ll i=1;i<=n;i++){
//		d-=(a[i+1]-a[i])*(n-i+1);
//		u+=(a[i+1]-a[i])*i;
//	}
	ll l=0,r=1000000000;
	//return 0;
	while(l<=r){
		ll mid=(l+r)>>1;
		if(ans(mid)<ans(mid+1)){
			r=mid-1;
		}
		else {
			l=mid+1;
		}
	}
	printf("%lld\n",ans(r+1));
	return 0;
}