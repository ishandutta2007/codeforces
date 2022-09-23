#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

ll N;
int x;

vector<int> v;

ll pw(ll a, ll b) {
	ll ret = 1;
	while(b) {
		if(b & 1) ret = ret * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return ret;
}

int main() {
	scanf("%d%lld", &x, &N);
	int p = 2;
	while(x > 1) {
		if(p * p > x) break;
		if(x % p) { p++; continue; }
		else { x /= p; v.push_back(p); }
	}

	if(x > 1) v.push_back(x);

	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	ll ans = 1;

	for(int i : v) {
		int p = i;
		ll t = N;
		while(t >= p) {
			ans = ans * pw(p, t / p) % MOD;
			t /= p;
		}
	}
	printf("%lld\n", ans);

	return 0;
}