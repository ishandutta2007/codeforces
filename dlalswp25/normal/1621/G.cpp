#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const ll MOD = 1000000007;

int N;
int A[202020];
int B[202020];
ll L[202020];
ll R[202020];

vector<int> V[202020];

struct BIT {
	vector<pii> hist;
	ll T[202020];

	void add(int x, int v) {
		v %= MOD;
		hist.emplace_back(x, v);
		T[x] = (T[x] + v) % MOD;
	}

	void upd(int x, int v) {
		for(int i = x; i <= N; i += i&-i) add(i, v);
	}

	ll get(int x) {
		ll ret = 0;
		for(int i = x; i; i -= i&-i) ret = (ret + T[i]) % MOD;
		return ret;
	}

	void rollback() {
		for(auto& i : hist) {
			T[i.first] = (T[i.first] + MOD - i.second) % MOD;
		}
		hist.clear();
	}
}tl, tr, tx;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		tl.rollback();
		tr.rollback();
		tx.rollback();
		scanf("%d", &N);

		vector<pii> tmp;
		for(int i = 1; i <= N; i++) {
			scanf("%d", &A[i]);
			tmp.emplace_back(A[i], -i);
		}

		sort(tmp.begin(), tmp.end());
		for(int i = 0; i < N; i++) {
			B[-tmp[i].second] = i + 1;
		}

		ll ans = 0;
		for(int i = 1; i <= N; i++) {
			L[i] = (tl.get(B[i]) + 1) % MOD;
			tl.upd(B[i], L[i]);
		}
		for(int i = N; i >= 1; i--) {
			R[i] = (tr.get(N) + MOD - tr.get(B[i]) + 1) % MOD;
			tr.upd(B[i], R[i]);
		}

		for(int i = 1; i <= N; i++) ans = (ans + L[i] * R[i]) % MOD;

		for(int i = 1; i <= N; i++) V[i].clear();
		vector<pii> stk;
		for(int i = N; i >= 1; i--) {
			if(stk.empty() || stk.back().first < B[i]) {
				stk.emplace_back(B[i], i);
				V[i].push_back(i);
			}
			else {
				auto it = lower_bound(stk.begin(), stk.end(), pii(B[i], 0));
				V[it->second].push_back(i);
			}
		}

		for(int i = 1; i <= N; i++) {
			if(!V[i].size()) continue;
			for(int j : V[i]) {
				ll t;
				if(j == i) t = 1;
				else {
					t = (tx.get(N) + MOD - tx.get(B[j])) % MOD;
				}
				// printf("%d %d %lld\n", i, j, t);
				tx.upd(B[j], t);
				ans = (ans + MOD - L[j] * t % MOD) % MOD;
			}
			tx.rollback();
		}
		printf("%lld\n", ans);
	}
	return 0;
}