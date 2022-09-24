#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll C[202020], D[202020];
ll n, p, k, ans;

int main()
{
	ll t, i;
	
	scanf("%lld", &t);
	
	for(; t --; ){
		scanf("%lld%lld%lld", &n, &p, &k);
		
		ans = 0;
		
		for(i = 1; i <= n; i ++){
			scanf("%lld", C + i);
		}
		
		sort(C + 1, C + n + 1);
		
		for(i = 1; i <= n; i ++){
			if(i >= k) D[i] = D[i - k] + C[i];
			else D[i] = D[i - 1] + C[i];
			if(p >= D[i]) ans = max(ans, i);
		}
		
		printf("%lld\n", ans);
	}
	
	return 0;
}