#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair <ll, ll> pll;

priority_queue <pll> Q;
ll D[1010101], S[1010101], K[1010101];
bool chk[1010101];
ll n, k, ans1, ans2;

int main()
{
	ll i, j, s, x, t, f;
	
	scanf("%lld%lld", &n, &k);
	
	for(i=1; i<=n; i++){
		D[i] = i; S[i] = 1;
	}
	
	for(i=2; i<=n; i++) if(!chk[i]){
		for(j=i*i; j<=n; j+=i){
			chk[j] = 1;
			for(x=0, s=1; D[j] % i == 0; D[j] /= i, x ++);
			for(; --x; s *= i); s *= i - 1;
			S[j] *= s;
		}
	}
	
	for(i=1; i<=n; i++){
		if(D[i] != 1) S[i] *= (D[i] - 1);
	}
	
	{
		// case 1 : odds
		
		for(i=3; i<=n; i+=2){
			for(j=i; j<=n; j+=i+i) K[j] ++;
			if(K[i] == 1){
				Q.emplace(-S[i], i);
			}
		}
		
		ans1 = 1;
		
		for(i=1; i<=k && !Q.empty(); i++){
			tie(x, t) = Q.top(); Q.pop();
			ans1 -= x;
			for(j=t; j<=n; j+=t+t){
				K[j] --;
				if(K[j] == 1){
					Q.emplace(-S[j], j);
				}
			}
		}
		
		if(i <= k) ans1 = 1e18;
	}
	{
		// case 2 : even + odd
		
		for(; !Q.empty(); Q.pop());
		
		for(i=3; i<=n; i++){
			K[i] = 0;
		}
		
		for(i=3; i<=n; i++){
			for(j=i; j<=n; j+=i) K[j] ++;
			if(K[i] == 1){
				Q.emplace(-S[i], i);
			}
		}
		
		ans2 = 2;
		
		for(i=1, f=0; i<=k && !Q.empty(); i++){
			tie(x, t) = Q.top(); Q.pop();
			ans2 -= x; if(~t & 1) f = 1;
			for(j=t; j<=n; j+=t){
				K[j] --;
				if(K[j] == 1){
					Q.emplace(-S[j], j);
				}
			}
		}
		
		if(!f) ans2 = 1e18;
	}
	
	printf("%lld\n", min(ans1, ans2));
	
	return 0;
}