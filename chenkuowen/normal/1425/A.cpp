#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
unordered_map<ll,ll> mp;
ll solve2(ll n){
	if(n==0) return 0;
	if(n&1) return n-solve2(n-1);
	else{
		if(n<=20) return n-min(solve2(n-1),solve2(n/2));
		if((n>>1)&1) return n-solve2(n/2);
		else return n-solve2(n-1);
	}
}
int main(){
//	for(ll n=1;n<=30;n++){
//		printf("[%lld %lld %lld]\n",n,solve(n),solve2(n));
//	}
	int T; scanf("%d",&T);
	while(T--){
		ll n; scanf("%lld",&n);
		printf("%lld\n",solve2(n));
	}
	return 0;
}