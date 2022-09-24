#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair <ll, ll> pll;

vector <pll> V;
ll X[202020], T[202020];
ll n, m, a, b, ans;

int main()
{
	ll t, i, j, k, s, x, y, v;
	
	scanf("%lld", &t);
	
	for(; t --; ){
		scanf("%lld%lld%lld%lld", &n, &m, &a, &b);
		
		for(i = 0, x = y = 0; i < n; i ++){
			scanf("%lld", X + i);
			if(X[i]) y ++;
			else x ++;
		}
		
		for(i = 0; i < n; i ++){
			scanf("%lld", T + i);
			V.emplace_back(T[i], i);
		}
		
		sort(V.begin(), V.end());
		
		V.emplace_back(m + 1, -1);
		
		if(V[0].first != 0){
			k = V[0].first - 1;
			if(x * a <= k) v = x + min(y, (k - x * a) / b);
			else v = k / a;
			ans = max(ans, v);
		}
		
		for(i = j = 0, s = 0; i < n; i = j){
			for(; j < n && V[i].first == V[j].first; j ++){
				if(X[V[j].second]) y --, s += b;
				else x --, s += a;
			}
			
			k = V[j].first - 1;
			if(s <= k){
				if(x * a <= k - s) v = x + min(y, (k - s - x * a) / b);
				else v = (k - s) / a;
				ans = max(ans, j + v);
			}
		}
		
		printf("%lld\n", ans);
		
		V.clear(); ans = 0;
	}
	
	return 0;
}