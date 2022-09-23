#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll A[3][101010];
int sz[3];

int N, M, K;

ll ans;

void f(int a, int b, int c) {
	for(int i = 1; i <= sz[b]; i++) {
		ll y = A[b][i];

		int t = upper_bound(A[a] + 1, A[a] + sz[a] + 1, y) - A[a];
		// printf("%d %d %d %lld -> %d\n", a, b, c, y, t);
		t--;
		if(t <= 0) continue;
		ll x = A[a][t];

		t = lower_bound(A[c] + 1, A[c] + sz[c] + 1, y) - A[c];
		if(t > sz[c]) continue;
		ll z = A[c][t];

		// printf("%lld %lld %lld f\n", x, y, z);

		ans = min(ans, (x - y) * (x - y) + (y - z) * (y - z) + (z - x) * (z - x));
	}
}

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%d%d%d", &sz[0], &sz[1], &sz[2]);
		for(int i = 0; i < 3; i++) {
			for(int j = 1; j <= sz[i]; j++) {
				scanf("%lld", &A[i][j]);
			}
			sort(A[i] + 1, A[i] + sz[i] + 1);
		}

		ans = (1LL << 62);

		f(0, 1, 2);
		f(0, 2, 1);
		f(1, 0, 2);
		f(1, 2, 0);
		f(2, 0, 1);
		f(2, 1, 0);

		printf("%lld\n", ans);
	}
	return 0;
}