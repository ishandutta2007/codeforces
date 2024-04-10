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
	//freopen("c.in","r",stdin);
	//freopen("c.out","w",stdout);
	ll a=readll(),b=readll(),c=readll(),d=readll();
	ll sum=0,ans=0;
	for(ll xjy=b+c;xjy>=c;xjy--) {
		ll l=std::max(xjy-c,a),r=std::min(xjy-b,b);
		if(l>r)continue;
		ll l2=c,r2=std::min(d,xjy-1);
		if(l2>r2)continue;
		ans+=(r-l+1)*(r2-l2+1);
	}
	printf("%lld\n",ans);
	return 0;
}