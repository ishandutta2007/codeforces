#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 998244353;

ll D[505][505];
int N, M;
int C[505];

ll f(int l, int r) {
	if(l > r) return 1;
	if(l == r) return D[l][r] = 1;
	if(D[l][r] != -1) return D[l][r];

	int m = N + 1, mid;
	for(int i = l; i <= r; i++) {
		if(m > C[i]) { m = C[i]; mid = i; }
	}

	ll sl = 0, sr = 0;

	for(int i = mid; i <= r; i++) {
		sr = (sr + f(mid + 1, i) * f(i + 1, r)) % MOD;
	}
	for(int i = mid; i >= l; i--) {
		sl = (sl + f(i, mid - 1) * f(l, i - 1)) % MOD;
	}

	return D[l][r] = sr * sl % MOD;
}

int main() {
	scanf("%d%d", &N, &M);
	for(int i = 1; i <= N; i++) scanf("%d", &C[i]);
	for(int i = 1; i <= N; i++) for(int j = 1; j <= N; j++) D[i][j] = -1;

	printf("%lld\n", f(1, N));

	return 0;
}