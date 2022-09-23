#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int NONE = 300001;

int Q;
int A[303030];
int C[303030];
int st[20][303030];

int up(int v, int k) {
	for(int i = 19; i >= 0; i--) {
		if(k & 1 << i) v = st[i][v];
	}
	return v;
}

int main() {
	scanf("%d", &Q);
	scanf("%d%d", &A[0], &C[0]);
	for(int i = 0; i <= 19; i++) st[i][NONE] = NONE;
	for(int i = 0; i <= 19; i++) st[i][0] = NONE;

	for(int q = 1; q <= Q; q++) {
		int t; scanf("%d", &t);
		if(t == 1) {
			int p; scanf("%d%d%d", &p, &A[q], &C[q]);
			st[0][q] = p;
			for(int i = 1; i <= 19; i++) st[i][q] = st[i - 1][st[i - 1][q]];
		}
		else {
			int v, w; scanf("%d%d", &v, &w);
			ll ans = 0, bw = w;
			int len = 0, u = v;
			for(int i = 19; i >= 0; i--) {
				if(!A[st[i][u]]) continue;
				len += 1 << i;
				u = st[i][u];
			}
			for(; len >= 0; len--) {
				u = up(v, len);
				if(w <= A[u]) {
					ans += (ll)C[u] * w;
					A[u] -= w;
					w = 0;
					break;
				}
				else {
					ans += (ll)C[u] * A[u];
					w -= A[u];
					A[u] = 0;
				}
			}
			printf("%lld %lld\n", bw - w, ans);
		}
		fflush(stdout);
	}
	return 0;
}