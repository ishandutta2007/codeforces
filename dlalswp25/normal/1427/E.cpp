#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

vector<pair<int, pii> > ans;

int main() {
	int N; scanf("%d", &N);
	if(N & 2) {
		ans.emplace_back(0, pii(N, N));
		ans.emplace_back(1, pii(2 * N, N));
		N = (2 * N) ^ N;
	}

	int tmp = N, dig = 0;
	while(tmp) {
		dig++; tmp >>= 1;
	}

	ll t = N;
	for(int i = 0; i < dig - 1; i++) {
		ans.emplace_back(0, pii(t, t));
		t <<= 1;
	}
	ans.emplace_back(0, pii(t, N));
	ans.emplace_back(1, pii(t, t + N));
	ans.emplace_back(1, pii(N, (t + N) ^ t));
	ll M = (t + N) ^ t ^ N;

	while(M > 1) {
		ll tmp = N;
		while(tmp >= M) {
			ll m = M;
			while(1) {
				if(m & tmp) {
					ans.emplace_back(1, pii(m, tmp));
					tmp ^= m;
					break;
				}
				else {
					ans.emplace_back(0, pii(m, m));
					m <<= 1;
				}
			}
		}

		while(1) {
			int cnt = 0;
			ll j;
			for(ll i = 1; i < M; i <<= 1) {
				if(tmp & i) { cnt++; j = i; }
			}
			if(cnt == 1) { M = j; break; }

			ll t = tmp;
			while(t < M) {
				ans.emplace_back(0, pii(t, t));
				t <<= 1;
			}
			ans.emplace_back(1, pii(t, M));
			t ^= M; tmp = t;
		}
		// printf("M=%lld\n", M);
	}

	printf("%d\n", ans.size());
	for(auto i : ans) {
		int c = i.first;
		ll x, y; tie(x, y) = i.second;
		printf("%lld ", x);
		if(c == 0) printf("+ ");
		else printf("^ ");
		printf("%lld\n", y);
	}
	return 0;
}