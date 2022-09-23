#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int N, M;
int A[303030];
vector<int> V[303030];
map<pii, int> mp;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &M);
		for(int i = 1; i <= N; i++) V[i].clear();
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);

		mp.clear();
		for(int i = 1; i <= M; i++) {
			int x, y; scanf("%d%d", &x, &y);
			mp[{x, y}]++; mp[{y, x}]++;
		}

		sort(A + 1, A + N + 1);

		vector<int> sz;
		for(int i = 2; i <= N; i++) {
			if(A[i] != A[i - 1]) {
				int c = upper_bound(A + 1, A + N + 1, A[i - 1]) - lower_bound(A + 1, A + N + 1, A[i - 1]);
				if(!V[c].size()) {
					sz.push_back(c);
				}
				V[c].push_back(A[i - 1]);
			}
		}
		int c = upper_bound(A + 1, A + N + 1, A[N]) - lower_bound(A + 1, A + N + 1, A[N]);
		if(!V[c].size()) {
			sz.push_back(c);
		}
		V[c].push_back(A[N]);

		for(int i = 1; i <= N; i++) {
			sort(V[i].begin(), V[i].end());
			reverse(V[i].begin(), V[i].end());
		}
		sort(sz.begin(), sz.end());
		reverse(sz.begin(), sz.end());

		ll ans = 0;
		for(int i = 0; i < sz.size(); i++) {
			for(int j = 0; j < sz.size(); j++) {
				for(int a : V[sz[i]]) {
					for(int b : V[sz[j]]) {
						if(a == b) continue;
						ll t = (ll)(sz[i] + sz[j]) * (a + b);
						if(t <= ans) break;
						if(mp[pii(a, b)]) continue;
						ans = max(ans, t); break;
					}
				}
			}
		}

		printf("%lld\n", ans);
	}
	return 0;
}