#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

ll p, q;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%lld%lld", &p, &q);
		if(p == 1) { puts("1"); continue; }
		vector<pii> v;
		for(ll i = 2; i * i <= q; i++) {
			while(q % i == 0) {
				if(!v.size() || v.back().first != i) v.emplace_back(i, 1);
				else v.back().second++;
				q /= i;
			}
		}
		if(q > 1) {
			if(!v.size() || v.back().first != q) v.emplace_back(q, 1);
			else v.back().second++;
		}

		ll ans = 1;
		for(pii i : v) {
			ll tmp = p;
			int c = 0;
			while(tmp % i.first == 0) {
				tmp /= i.first;
				c++;
			}
			tmp = p;
			for(int j = 0; j <= c - i.second; j++) tmp /= i.first;
			ans = max(ans, tmp);
		}
		printf("%lld\n", ans);
	}
	return 0;
}