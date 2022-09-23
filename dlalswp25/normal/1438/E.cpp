#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
int A[202020];
ll S[202020];
int bef[202020][35];

int dig(int x) {
	int ret = 0;
	while(x) {
		x >>= 1;
		ret++;
	}
	return ret;
}

bool chk(int l, int r) {
	bool x = r - l + 1 >= 3 && (A[l] ^ A[r]) == (S[r - 1] - S[l]);
	// printf("chk %d %d %d\n", x, l, r);
	return x;
}

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) {
		scanf("%d", &A[i]);
		S[i] = S[i - 1] + A[i];
	}

	ll ans = 0;
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= 30; j++) bef[i + 1][j] = bef[i][j];
		int d = dig(A[i]);
		bef[i + 1][d] = i;

		// printf("%d %d\n", i, d);
		// printf("i=%d\n", i);

		for(int j = d; j <= 30; j++) {
			int t = bef[i][j];
			if(t) ans += chk(t, i);
			t = bef[t][j];
			if(t) ans += chk(t, i);
		}

		// printf("%lld\n", ans);

		for(int j = 1; j < d; j++) {
			int x = 1 << j - 1;
			int y = (A[i] ^ x) & ~(x - 1);
			// printf("j %d x %d y %d\n", j, x, y);
			int t = upper_bound(S + 1, S + i - 1, S[i - 1] - y) - S;
			// printf("%d\n", t);
			t = bef[t][j];
			if(t) ans += chk(t, i);
			t = bef[t][j];
			if(t) ans += chk(t, i);
		}
		// printf("%lld\n", ans);
	}
	printf("%lld\n", ans);

	return 0;
}