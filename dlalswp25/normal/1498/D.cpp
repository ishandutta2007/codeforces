#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll P = 100000;
const int INF = 10101010;

int N, M;
int T[202];
ll X[202];
int Y[202];
int D[101010];
int E[101010];

struct SegTree {
	int T[4 * 101010];

	void init(int idx, int s, int e) {
		T[idx] = INF;
		if(s == e) return;
		int m = s + e >> 1;
		init(idx << 1, s, m);
		init(idx << 1 | 1, m + 1, e);
	}

	void upd(int idx, int s, int e, int p, int x) {
		if(p < s || e < p) return;
		if(s == e) { T[idx] = min(T[idx], x); return; }
		int m = s + e >> 1;
		upd(idx << 1, s, m, p, x);
		upd(idx << 1 | 1, m + 1, e, p, x);
		T[idx] = min(T[idx << 1], T[idx << 1 | 1]);
	}

	int get(int idx, int s, int e, int p, int q) {
		if(q < p || q < s || e < p) return INF;
		if(p <= s && e <= q) return T[idx];
		int m = s + e >> 1;
		return min(get(idx << 1, s, m, p, q), get(idx << 1 | 1, m + 1, e, p, q));
	}

	void upd(int p, int x) { upd(1, 1, M, p, x); }
	int get(int p, int q) { return get(1, 1, M, p, q); }
}seg;

int main() {
	scanf("%d%d", &N, &M);
	for(int i = 1; i <= N; i++) scanf("%d%lld%d", &T[i], &X[i], &Y[i]);
	D[0] = 1;
	seg.init(1, 1, M);

	for(int i = 1; i <= N; i++) {
		if(T[i] == 1) {
			int t = (X[i] + P - 1) / P;
			for(int j = t; j <= M; j++) {
				if(D[j]) continue;
				if(D[j - t] && !(D[j - t] == i && E[j - t] == Y[i])) {
					D[j] = i;
					if(D[j - t] == i) E[j] = E[j - t] + 1;
					else E[j] = 1;
					seg.upd(j, 0);
				}
			}
		}
		else {
			vector<int> v;
			for(int j = 1; j <= M; j++) {
				if(D[j]) continue;
				ll mx = j * P / X[i];
				ll mn = (j - 1) * P / X[i] + 1;
				if(mn > M || mx <= 0) continue;
				mx = min(mx, (ll)M);
				mn = max(mn, 1LL);
				int t = seg.get(mn, mx);
				// printf("%d %d %lld %lld\n", i, j, mn, mx);
				if(t < Y[i]) {
					D[j] = i; seg.upd(j, t + 1);
					v.push_back(j);
				}
			}

			for(int j : v) seg.upd(j, 0);
		}
	}

	for(int i = 1; i <= M; i++) printf("%d ", D[i] ? D[i] : -1); puts("");
	return 0;
}