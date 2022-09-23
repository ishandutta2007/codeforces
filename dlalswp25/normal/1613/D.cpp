#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 998244353;

int N;
int A[505050];
ll D[505050];
ll E[505050];
ll pw[505050];
int nxt[505050];
vector<int> v[505050];

int main() {
	pw[0] = 1;
	for(int i = 1; i <= 500000; i++) pw[i] = pw[i - 1] * 2 % MOD;
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 0; i <= N + 1; i++) D[i] = E[i] = 0;
		for(int i = 0; i <= N; i++) v[i].clear();

		int one = 0;
		for(int i = 1; i <= N; i++) {
			scanf("%d", &A[i]);
			one += A[i] == 1;
			if(v[A[i]].size()) nxt[v[A[i]].back()] = i;
			v[A[i]].push_back(i);
		}

		ll ans = (pw[one] + MOD - 1) % MOD;

		for(int i = 0; i <= N; i++) {
			if(v[i].size()) nxt[v[i].back()] = N + 1;
		}

		for(int i = N; i >= 1; i--) {
			if(A[i] < 2) { E[i] = 0; continue; }
			int t = v[A[i]].size() - (lower_bound(v[A[i]].begin(), v[A[i]].end(), i) - v[A[i]].begin());
			t--;
			int s = v[A[i] - 2].size() - (lower_bound(v[A[i] - 2].begin(), v[A[i] - 2].end(), i) - v[A[i] - 2].begin());
			E[i] = (E[nxt[i]] + pw[t + s]) % MOD;
		}

		// for(int i = 1; i <= N; i++) printf("e%d ", E[i]); puts("");

		for(int i = 1; i <= N; i++) {
			ll t = D[A[i]];
			if(A[i]) t = (t + D[A[i] - 1]) % MOD;
			if(!A[i]) t++;

			ll s = 0;
			if(A[i] <= N - 2) {
				auto it = lower_bound(v[A[i] + 2].begin(), v[A[i] + 2].end(), i);
				if(it != v[A[i] + 2].end()) {
					s = E[*it];
				}
			}
			// printf("i%d t%lld s%lld\n", i, t, s);
			ans = (ans + t * (s + 1)) % MOD;
			D[A[i]] = (D[A[i]] + t) % MOD;
			// printf("%lld\n", ans);
		}
		printf("%lld\n", ans);
	}
	return 0;
}