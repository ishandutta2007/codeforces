#include<bits/stdc++.h>

using namespace std;
#define ll long long

int T;
ll n;
int main() {
	scanf("%d", &T);
	while(T--){
		scanf("%lld", &n), --n;
		ll x=n/3, y=1;
		while(y<=x) x-=y, y*=4;
		n%=3;
		ll ans=(n+1)*y;
		if(!n){ printf("%lld\n", ans+x); continue;}
		for(ll i=y/4; i; i/=4) if(x/i) ans+=((x/i+n-1)%3+1)*i, x&=i-1;
		printf("%lld\n", ans);
	}
	return 0;
}