#include <bits/stdc++.h>

using namespace std;

const int INF = 1010101010;

int N, M;
int L[202020];
int R[202020];
int A[202020];
vector<int> V[202020];
int G[202020];

struct SegTreeMax {
	int T[4 * 202020];

	void init(int idx, int s, int e) {
		T[idx] = 0;
		if(s == e) return;
		int m = s + e >> 1;
		init(idx << 1, s, m);
		init(idx << 1 | 1, m + 1, e);
	}

	void upd(int idx, int s, int e, int p, int q, int x) {
		if(q < p || q < s || e < p) return;
		if(p <= s && e <= q) { T[idx] = max(T[idx], x); return; }
		int m = s + e >> 1;
		upd(idx << 1, s, m, p, q, x);
		upd(idx << 1 | 1, m + 1, e, p, q, x);
	}

	int get(int idx, int s, int e, int p) {
		if(p < s || e < p) return 0;
		if(s == e) return T[idx];
		int m = s + e >> 1;
		return max({T[idx], get(idx << 1, s, m, p), get(idx << 1 | 1, m + 1, e, p)});
	}
}seg;

void compress(int n, int* X) {
	vector<int> v;
	for(int i = 1; i <= n; i++) v.push_back(X[i]);
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for(int i = 1; i <= n; i++) X[i] = lower_bound(v.begin(), v.end(), X[i]) - v.begin() + 1;
}

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &M);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		for(int i = 1; i <= M; i++) scanf("%d%d", &L[i], &R[i]);

		compress(N, A);
		for(int i = 1; i <= N; i++) V[i].clear();
		for(int i = 1; i <= N; i++) V[A[i]].push_back(i);

		seg.init(1, 1, N);

		for(int i = 1; i <= M; i++) seg.upd(1, 1, N, L[i], R[i], R[i]);
		for(int i = 1; i <= N; i++) G[i] = seg.get(1, 1, N, i);

		seg.init(1, 1, N);

		for(int i = 1; i <= N; i++) {
			if(!G[i]) continue;
			int t = upper_bound(V[A[i]].begin(), V[A[i]].end(), G[i]) - V[A[i]].begin();
			t--;
			int r = V[A[i]][t];
			seg.upd(1, 1, N, i + 1, r - 1, r);
			if(i != r) {
				seg.upd(1, 1, N, 1, N, V[A[i]][t - 1]);
			}
		}

		int mxl = N + 1;
		for(int i = 1; i <= N; i++) {
			for(int j = 0; j + 1 < V[i].size(); j++) {
				int x = V[i][j], y = V[i][j + 1];
				if(G[x] < y) continue;
				mxl = min(mxl, y);
			}
		}

		if(mxl > N) { puts("0"); continue; }

		// for(int i = 1; i <= N; i++) printf("%d ", seg.get(1, 1, N, i)); puts("");
		// printf("mxl=%d\n", mxl);

		int ans = N;
		for(int i = 1; i <= mxl; i++) {
			int r = max(i, seg.get(1, 1, N, i));
			ans = min(ans, r - i + 1);
		}
		printf("%d\n", ans);
	}
	return 0;
}