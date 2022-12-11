#include <bits/stdc++.h>

const int MAXN = 300010;
int n, Q, A[MAXN];
int go[MAXN][19], lst[19];

int main() {
	scanf("%d%d", &n, &Q);
	for (int i = 1; i <= n; ++i) scanf("%d", A + i);
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j != 19; ++j)
			if (A[i] >> j & 1) {
				go[i][j] = i;
				for (int k = 0; k != 19; ++k)
					go[i][k] = std::max(go[i][k], go[lst[j]][k]);
				lst[j] = i;
			}
	}
	for (int i = 1, t1, t2; i <= Q; ++i) {
		scanf("%d%d", &t1, &t2);
		bool can = false;
		for (int j = 0; j != 19; ++j)
			if (A[t1] >> j & 1)
				can |= go[t2][j] >= t1;
		puts(can ? "Shi" : "Fou");
	}
	return 0;
}