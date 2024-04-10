#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MAXN = 1e5 + 10;

ll n, m;
ll f[MAXN], g[MAXN];

bool ok(ll mid){
	ll cur = 0;
	for (ll i = 0; i < n; i++){
		while (cur < m && abs(f[i] - g[cur]) > mid)	cur++;
		if (cur == m)	return false;
	}
	return true;
}

int main(){
	scanf("%d %d", &n, &m);
	for (ll i = 0; i < n; i++)	scanf("%lld", &f[i]);
	for (ll i = 0; i < m; i++)	scanf("%lld", &g[i]);
	sort(f, f + n);
	sort(g, g + m);

	ll b = 0, e = 2e9, ret = 2e9;
	while (b <= e){
		ll mid = b+e >> 1;
		if (ok(mid))
			ret = mid, e = mid - 1;
		else
			b = mid + 1;
	}
	printf("%d\n", ret);
	return 0;
}