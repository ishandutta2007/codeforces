#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		ll N; scanf("%lld", &N);
		vector<pii> v;
		vector<ll> ans;
		ll tmp = N;
		ll p = 2;
		while(tmp > 1) {
			if(p * p > tmp) break;
			if(tmp % p == 0) {
				v.emplace_back(p, 0);
				while(tmp % p == 0) {
					v.back().second++;
					tmp /= p;
				}
			}
			p++;
		}
		if(tmp > 1) v.emplace_back(tmp, 1);
		sort(v.begin(), v.end(), [&](pii& a, pii& b) {
			return a.second > b.second;
		});

		ll k = v[0].second;
		ans = vector<ll>(k, 1);
		for(pii i : v) {
			for(int j = k - i.second; j < k; j++) {
				ans[j] *= i.first;
			}
		}
		printf("%lld\n", k);
		for(ll i : ans) printf("%lld ", i); puts("");
	}
	return 0;
}