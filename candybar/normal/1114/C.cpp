#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <utility>

using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,b;
ll calc(ll p,ll a){
	ll tmp = n,ans = 0;
	while(tmp){
		ans += tmp / p;
		tmp /= p;
	}
	return ans / a;
}
int main(){
	scanf("%I64d%I64d",&n,&b);
	ll ans = (ll)1e18;
	ll tmp = b;
	for(ll i = 2;i * i <= tmp;i++){
		if(tmp % i == 0){
			int a = 0;
			while(tmp % i == 0){
				a++;
				tmp /= i;
			}
			ans = min(ans,calc(i,a));
		}
	}
	if(tmp > 1){
		ans = min(ans,calc(tmp,1ll));
	}
	printf("%I64d\n",ans);
	return 0;
}