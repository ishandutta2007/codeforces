#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const ll INF = (1LL << 60);

int N, M;
int A[202020];
ll D[202020];
ll E[202020];
vector<pii> V[202020];
multiset<ll> S;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &M);
		for(int i = 1; i <= N + 1; i++) V[i].clear();
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		sort(A + 1, A + N + 1);
		for(int i = 1; i <= M; i++) {
			int l, r; scanf("%d%d", &l, &r);
			int t = lower_bound(A + 1, A + N + 1, l) - A;
			if(t <= N && A[t] <= r) continue;
			V[t].emplace_back(r, l);
		}
		for(int i = 1; i <= N + 1; i++) {
			sort(V[i].begin(), V[i].end());
			reverse(V[i].begin(), V[i].end());
		}

		for(int i = 1; i <= N; i++) {
			D[i] = E[i] = INF;
			if(!V[i].size()) {
				D[i] = E[i] = min(D[i - 1], E[i - 1]);
				continue;
			}

			if(i == 1) {
				ll t = V[i].back().first;
				D[i] = 2 * (A[i] - t);
				E[i] = (A[i] - t);
				continue;
			}

			S.clear();
			for(auto& j : V[i]) S.insert(j.second);
			ll r = A[i];
			for(auto& j : V[i]) {
				ll t = min(D[i - 1] + (*(--S.end()) - A[i - 1]), E[i - 1] + 2 * (*(--S.end()) - A[i - 1]));
				D[i] = min(D[i], (A[i] - r) * 2 + t);
				E[i] = min(E[i], (A[i] - r) + t);
				r = j.first;
				S.erase(S.find(j.second));
			}

			ll t = min(D[i - 1], E[i - 1]);
			D[i] = min(D[i], (A[i] - r) * 2 + t);
			E[i] = min(E[i], (A[i] - r) + t);
		}

		ll ans = min(D[N], E[N]);
		if(V[N + 1].size()) {
			ll lft = -INF;
			for(auto& j : V[N + 1]) lft = max(lft, (ll)j.second);
			ans = min(D[N] + (lft - A[N]), E[N] + 2 * (lft - A[N]));
		}
		printf("%lld\n", ans);
	}
	return 0;
}