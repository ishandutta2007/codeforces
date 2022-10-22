#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll solve(ll n){
	ll t=1;
	while(n%(t+t)==0) t<<=1;
	ll p1=t+t,p2=n/t;
	return min(p1,p2);
}
int main(){
	int T; scanf("%d",&T);
	while(T--){
		ll n; scanf("%lld",&n);
		ll ans=solve(n);
		if(ans==1||ans*(ans+1)/2>n) puts("-1");
		else printf("%lld\n",ans);
	}
	return 0;
}