#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int N;
int D[404040];
vector<int> v;
vector<pii> evt[404040];

int L[202020];
int R[202020];
int C[202020];

struct NODE {
	int mx;
	int add;
};

struct SEG {
	NODE T[4 * 404040];

	void upd(int idx, int s, int e, int p, int q, int x) {
		if(q < p || q < s || e < p) return;
		if(p <= s && e <= q) {
			T[idx].mx += x;
			T[idx].add += x;
			return;
		}
		int m = s + e >> 1;
		upd(idx << 1, s, m, p, q, x);
		upd(idx << 1 | 1, m + 1, e, p, q, x);
		T[idx].mx = max(T[idx << 1].mx, T[idx << 1 | 1].mx) + T[idx].add;
	}

	int get(int idx, int s, int e, int p, int q) {
		if(q < p || q < s || e < p) return 0;
		if(p <= s && e <= q) return T[idx].mx;
		int m = s + e >> 1;
		return max(T[idx << 1].mx, T[idx << 1 | 1].mx) + T[idx].add;
	}
}segw, segb;

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) {
		scanf("%d%d%d", &L[i], &R[i], &C[i]);
		R[i]++;
		v.push_back(L[i]);
		v.push_back(R[i]);
	}

	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	for(int i = 1; i <= N; i++) {
		L[i] = lower_bound(v.begin(), v.end(), L[i]) - v.begin() + 1;
		R[i] = lower_bound(v.begin(), v.end(), R[i]) - v.begin() + 1;
		R[i]--;
		evt[R[i]].emplace_back(C[i], L[i]);

		// printf("%d %d\n", L[i], R[i]);
	}

	for(int i = 1; i <= 2 * N; i++) {
		for(pii j : evt[i]) {
			// printf("%d %d upd\n", j.first, j.second);
			if(j.first == 1) segw.upd(1, 0, 2 * N, 0, j.second - 1, 1);
			else segb.upd(1, 0, 2 * N, 0, j.second - 1, 1);
		}
		D[i] = max(segw.get(1, 0, 2 * N, 0, i), segb.get(1, 0, 2 * N, 0, i));
		segw.upd(1, 0, 2 * N, i, i, D[i]);
		segb.upd(1, 0, 2 * N, i, i, D[i]);
		// printf("%d %d\n", i, D[i]);
	}

	printf("%d\n", D[2 * N]);

	return 0;
}