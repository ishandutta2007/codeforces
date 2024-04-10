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
int main(){
	//return 0;
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	ll t=readll();
	for(ll i=1;i<=t;i++) {
		ll a=readll(),k=readll(),x;k--;
		while((x=add(a))&&k)a+=x,k--;
		printf("%lld\n",a);
	}
	return 0;
}