#include <bits/stdc++.h>

using namespace std;

const int INF = 1010101010;

int N;

struct NODE {
	int mx;
	int lz;
}T[4 * 303030];

void upd(int idx, int s, int e, int p, int q, int v) {
	if(q < p || q < s || e < p) return;
	if(p <= s && e <= q) {
		T[idx].mx += v;
		T[idx].lz += v;
		return;
	}

	int m = s + e >> 1;
	upd(idx << 1, s, m, p, q, v);
	upd(idx << 1 | 1, m + 1, e, p, q, v);
	T[idx].mx = max(T[idx << 1].mx, T[idx << 1 | 1].mx) + T[idx].lz;
}

int get() {
	return T[1].mx;
}

int P[303030];
int Q[303030];
int R[303030];
int pos[303030];

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) {
		scanf("%d", &P[i]);
		pos[P[i]] = i;
	}
	for(int i = 1; i <= N; i++) scanf("%d", &Q[i]);

	int p = N;
	int q = 0;
	while(p >= 1) {
		upd(1, 1, N, 1, pos[p], 1);
		while(q < N && get() > 0) {
			q++;
			upd(1, 1, N, 1, Q[q], -1);

			// for(int j = 0; j < 20; j++) printf("%d ", T[j].mx); puts("");
		}
		R[p] = q;
		p--;
	}

	// for(int i = 1; i <= N; i++) printf("%d ", R[i]);

	for(int i = 0; i < R[N]; i++) printf("%d ", N);
	for(int i = N - 1; i >= 1; i--) {
		for(int j = R[i + 1]; j < R[i]; j++) printf("%d ", i);
	}
	puts("");

	return 0;
}