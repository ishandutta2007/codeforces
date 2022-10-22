#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int T; scanf("%d",&T);
	while(T--){
		int n; scanf("%d",&n);
		ll k1=0,k2=0;
		for(int i=1;i<=n;++i){
			ll x; scanf("%lld",&x);
			k1+=x; k2^=x;
		}
		printf("2\n%lld %lld\n",k2,k1+k2);
	}
	return 0;
}