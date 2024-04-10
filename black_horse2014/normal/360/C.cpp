#include <iostream>
#include <cstdio>
#include <memory.h>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#define MOD 1000000007LL
#define MX 2010
using namespace std;

long long val[MX][MX], ls[MX][MX], big[MX][MX];
int N, K;
char s[MX];

main() {
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
	
	int i, j, p, q, k;
	scanf("%d%d%s", &N, &K, s);
	for (i = N - 1; i >= 0; i--) {
		if (i == N - 1) {
			val[i][0] = ls[i][0] = s[i] - 'a' + 1;
			big[i][1] = val[i][1] = 'z' - s[i];
			continue;
		}
		for (k = 0; k <= K; k++) {
			ls[i][k] = ((s[i] - 'a') * val[i + 1][k] + ls[i + 1][k]) % MOD;
			if (k >= N - i) big[i][k] = ('z' - s[i]) * val[i + 1][k - N + i] % MOD;
			for (p = i + 1; k - (p - i) * (N - p) >= 0 && p < N; p++) val[i][k] = (val[i][k] + big[p][k - (p - i) * (N - p)]) % MOD;
			for (q = N - 1; k - (q - i) * (N - q) >= 0 && q >= p; q--) val[i][k] = (val[i][k] + big[q][k - (q - i) * (N - q)]) % MOD;
			val[i][k] = (val[i][k] + ls[i][k] + big[i][k]) % MOD;
		}
	}
	printf("%I64d\n", val[0][K]);
}