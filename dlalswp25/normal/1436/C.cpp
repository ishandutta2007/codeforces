#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

int N, X, P;
ll ncr[1010][1010];
ll F[1010];

int main() {
	scanf("%d%d%d", &N, &X, &P);
	for(int i = 0; i <= N; i++) {
		ncr[i][0] = 1;
		for(int j = 1; j <= i; j++) ncr[i][j] = (ncr[i - 1][j] + ncr[i - 1][j - 1]) % MOD;
	}

	F[0] = 1;
	for(int i = 1; i <= N; i++) F[i] = F[i - 1] * i % MOD;

	int l = 0, r = N;
	int a = 0, b = 0;
	while(l < r) {
		int m = l + r >> 1;
		// printf("%d\n", m);
		if(m < P) { a++; l = m + 1; }
		else if(m > P) { b++; r = m; }
		else l = m + 1;
	}
	// printf("%d %d\n", a, b);

	if(X - 1 < a || N - X < b) puts("0");
	else printf("%lld\n", F[N - a - b - 1] * ncr[X - 1][a] % MOD * F[a] % MOD * ncr[N - X][b] % MOD * F[b] % MOD);
	return 0;
}