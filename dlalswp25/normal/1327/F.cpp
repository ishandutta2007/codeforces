#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 998244353;

int N, M, K;

struct COND {
	int l, r, x;

	bool operator< (const COND& o) const {
		if(l == o.l) return r > o.r;
		return l < o.l;
	}
}A[505050];

int B[505050];
ll D[505050];

vector<int> ids;

int main() {
	scanf("%d%d%d", &N, &K, &M);
	for(int i = 1; i <= M; i++) {
		scanf("%d%d%d", &A[i].l, &A[i].r, &A[i].x);
	}

	sort(A + 1, A + M + 1);

	ll ans = 1;
	for(int bit = 0; bit < K; bit++) {
		ids.push_back(-1);
		for(int i = 1; i <= M; i++) {
			if(i < 0) continue;
			if(A[i].x & (1 << bit)) {
				B[A[i].l]++;
				B[A[i].r + 1]--;
			}
			else {
				while(ids.size()) {
					if(A[ids.back()].r >= A[i].r) ids.pop_back();
					else break;
				}
				ids.push_back(i);
			}
		}

		int sz = (int)ids.size() - 1;

		for(int i = 1; i <= N; i++) B[i] += B[i - 1];
		for(int i = 1; i <= N; i++) B[i] = (B[i] > 0);

		// for(int i = 1; i <= N; i++) printf("%d ", B[i]); puts("");

		int r = 1, l = 1;
		ll s = 0; D[0] = 1;
		for(int i = 1; i <= N; i++) {
			if(l <= sz && A[ids[l]].r < i) {
				s = (s + MOD - D[l - 1]) % MOD;
				l++;
			}

			if(r <= sz && A[ids[r]].l == i) {
				s = (s + D[r - 1]) % MOD;
				if(B[i] == 0) D[r] = s;
				r++;
			}
			else {
				ll t = (s + D[r - 1]) % MOD;
				if(B[i] == 0) D[r - 1] = (D[r - 1] + t) % MOD;
			}

			// for(int j = 0; j <= sz; j++) printf("%lld ", D[j]); printf("s=%lld\n", s);
		}

		ans = ans * D[sz] % MOD;

		for(int i = 1; i <= N; i++) B[i] = D[i] = 0;

		ids.clear();
	}
	printf("%lld\n", ans);

	return 0;
}