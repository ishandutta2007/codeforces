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
	//freopen("d.in","r",stdin);
	//freopen("d.out","w",stdout);
	ll n=readll(),s=readll();
//	if(s-n+1>=n-1){
//		puts("Yes");
//		for(ll i)
//	}
	if(s<n*2)printf("No");
	else{
		puts("Yes");
		for(ll i=1;i<=n-1;i++)printf("2 ");
		printf("%lld\n1",s-n*2+2);
	}
	return 0;
}