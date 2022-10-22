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
ll a[333333];
int main(){
	//return 0;
	//freopen("b.in","r",stdin);
	//freopen("b.out","w",stdout);
	ll t=readll();
	while(t-->0) {
		ll n=readll();
		for(ll i=1;i<=n;i++){
			a[i]=readll();
		}
		std::sort(a+1,a+n+1);
		ll s=0;
		for(ll i=1,member=0;i<=n;i++){
			member++;
			if(a[i]<=member){
				s++,member=0;
			}
		}
		printf("%lld\n",s);
	}
	return 0;
}