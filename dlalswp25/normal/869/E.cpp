#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N, M, Q;
ll P = 998244353;
ll MOD = 1000000007LL;

ll F[2525][2525];
ll X[101010];
int I[2525][2525];

void upd(int x, int y, ll v) {
	for(int i = x; i <= N; i += i&-i) {
		for(int j = y; j <= M; j += j&-j) {
			F[i][j] += v;
			F[i][j] %= MOD;
		}
	}
}

ll query(int x, int y) {
	ll ret = 0;
	for(int i = x; i; i -= i&-i) {
		for(int j = y; j; j -= j&-j) {
			ret += F[i][j];
			ret %= MOD;
		}
	}
	return ret;
}

int main() {
	X[0] = 1;
	for(int i = 1; i <= 100000; i++) X[i] = X[i - 1] * P % MOD;

	scanf("%d%d%d", &N, &M, &Q);

	for(int q = 1; q <= Q; q++) {
		int t; scanf("%d", &t);
		int x1, y1, x2, y2; scanf("%d%d%d%d", &x1, &y1, &x2, &y2);

		if(t == 1) {
			upd(x1, y1, X[q]);
			upd(x2 + 1, y1, MOD - X[q]);
			upd(x1, y2 + 1, MOD - X[q]);
			upd(x2 + 1, y2 + 1, X[q]);
			I[x1][y1] = q;
		}
		else if(t == 2) {
			upd(x1, y1, MOD - X[I[x1][y1]]);
			upd(x2 + 1, y1, X[I[x1][y1]]);
			upd(x1, y2 + 1, X[I[x1][y1]]);
			upd(x2 + 1, y2 + 1, MOD - X[I[x1][y1]]);
		}
		else {
			if(query(x1, y1) == query(x2, y2)) puts("Yes");
			else puts("No");
		}
	}

	return 0;
}