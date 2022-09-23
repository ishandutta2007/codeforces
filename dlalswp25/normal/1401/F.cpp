#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int K, N, Q;
ll T[4 * 262626];

bool inv[20];
bool sw[20];

pii cvt(int k, int s, int e) {
	int ts = s, te = e;
	for(int i = K; i >= k; i--) {
		if(inv[i]) {
			int tmp = te;
			te = ts ^ (1 << i) - 1;
			ts = tmp ^ (1 << i) - 1;
		}
		if(sw[i]) {
			ts ^= 1 << i;
			te ^= 1 << i;
		}
		// printf("i = %d, %d %d\n", i, ts, te);
	}
	// printf("%d %d -> %d %d\n", s, e, ts, te);
	return {ts, te};
}

void upd(int k, int idx, int s, int e, int p, int x) {
	int ts, te;
	tie(ts, te) = cvt(k, s, e);

	if(p < ts || te < p) return;
	if(ts == te) {
		T[idx] = x;
		return;
	}
	int m = s + e >> 1;
	upd(k - 1, idx << 1, s, m, p, x);
	upd(k - 1, idx << 1 | 1, m + 1, e, p, x);
	T[idx] = T[idx << 1] + T[idx << 1 | 1];
}

ll get(int k, int idx, int s, int e, int p, int q) {
	int ts, te, tp, tq;
	tie(ts, te) = cvt(k, s, e);

	if(q < p || q < ts || te < p) return 0;
	if(p <= ts && te <= q) return T[idx];
	int m = s + e >> 1;
	return get(k - 1, idx << 1, s, m, p, q) + get(k - 1, idx << 1 | 1, m + 1, e, p, q);
}

int main() {
	scanf("%d%d", &K, &Q);
	N = 1 << K;
	for(int i = 1; i <= N; i++) {
		int a; scanf("%d", &a);
		T[N + i - 1] = a;
	}

	for(int i = N - 1; i >= 1; i--) T[i] = T[i << 1] + T[i << 1 | 1];

	while(Q--) {
		int t; scanf("%d", &t);
		if(t == 1) {
			int x, k; scanf("%d%d", &x, &k);
			x--;
			upd(K, 1, 0, N - 1, x, k);
		}
		else if(t == 2) {
			int k; scanf("%d", &k);
			inv[k] = !inv[k];
		}
		else if(t == 3) {
			int k; scanf("%d", &k);
			sw[k] = !sw[k];
		}
		else {
			int l, r; scanf("%d%d", &l, &r);
			l--; r--;
			printf("%lld\n", get(K, 1, 0, N - 1, l, r));
		}
	}

	return 0;
}