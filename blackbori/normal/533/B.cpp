#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair <ll, ll> pll;

vector <ll> V[202020];
ll C[202020];
ll n;
pll ans;

pll dfs(ll p)
{
	pll k;
	ll s, m, f;
	
	s = f = 0; m = 1e18;
	
	for(ll t: V[p]){
		k = dfs(t);
		if(k.first > k.second){
			s += k.first;
			m = min(m, k.first - k.second);
		}
		else{
			s += k.second; f = !f;
			m = min(m, k.second - k.first);
		}
	}
	
	if(f) return pll(s - m, max(s, s - m + C[p]));
	else return pll(s, s + C[p]);
}

int main()
{
	ll i, a, b;
	
	scanf("%lld", &n);
	
	for(i=1; i<=n; i++){
		scanf("%lld%lld", &a, &b);
		if(a != -1) V[a].push_back(i);
		C[i] = b;
	}
	
	ans = dfs(1);
	
	printf("%lld\n", max(ans.first, ans.second));
	
	return 0;
}