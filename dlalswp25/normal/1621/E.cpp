#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N, M;
int A[101010];
vector<int> B[101010];
int sz[101010];
ll sum[101010];

struct Node {
	int add = 0, mx = 0;
};

struct SegTree {
	Node T[4 * 101010];

	void init(int idx, int s, int e) {
		T[idx].add = T[idx].mx = 0;
		if(s == e) {
			T[idx].mx = s - (N + 1);
			return;
		}
		int m = s + e >> 1;
		init(idx << 1, s, m);
		init(idx << 1 | 1, m + 1, e);
		T[idx].mx = max(T[idx << 1].mx, T[idx << 1 | 1].mx);
	}

	void init() {
		init(1, 1, N + 1);
	}

	void upd(int idx, int s, int e, int p, int q, int x) {
		if(q < p || q < s || e < p) return;
		if(p <= s && e <= q) {
			T[idx].add += x;
			T[idx].mx += x;
			return;
		}
		int m = s + e >> 1;
		upd(idx << 1, s, m, p, q, x);
		upd(idx << 1 | 1, m + 1, e, p, q, x);
		T[idx].mx = max(T[idx << 1].mx, T[idx << 1 | 1].mx) + T[idx].add;
	}

	void upd(int p, int q, int x) { upd(1, 1, N + 1, p, q, x); }

	int get() {
		return T[1].mx + T[1].add <= 0;
	}
}seg;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &M);
		for(int i = 1; i <= M; i++) B[i].clear();

		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		sort(A + 1, A + N + 1);
		for(int i = 1; i <= M; i++) {
			scanf("%d", &sz[i]);
			sum[i] = 0;
			for(int j = 1; j <= sz[i]; j++) {
				int x; scanf("%d", &x);
				sum[i] += x;
				B[i].push_back(x);
			}
		}

		seg.init();
		for(int i = 1; i <= M; i++) {
			int t = lower_bound(A + 1, A + N + 1, (sum[i] + sz[i] - 1) / sz[i]) - A;
			seg.upd(1, t, 1);
		}

		for(int i = 1; i <= M; i++) {
			for(int j : B[i]) {
				int t = lower_bound(A + 1, A + N + 1, (sum[i] + sz[i] - 1) / sz[i]) - A;
				seg.upd(1, t, -1);
				sum[i] -= j;
				sz[i]--;
				t = lower_bound(A + 1, A + N + 1, (sum[i] + sz[i] - 1) / sz[i]) - A;
				seg.upd(1, t, 1);
				printf("%d", seg.get());
				seg.upd(1, t, -1);
				sum[i] += j;
				sz[i]++;
				t = lower_bound(A + 1, A + N + 1, (sum[i] + sz[i] - 1) / sz[i]) - A;
				seg.upd(1, t, 1);
			}
		}
		puts("");
	}
	return 0;
}