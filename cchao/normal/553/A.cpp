#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
int n, a[1010], ans = 1, C[2010][2010];

inline int H(int n, int k) {
	return C[n + k - 1][k];
}

int main() {
	for(int i = 0; i < 2010; ++i) {
		C[i][0] = C[i][i] = 1;
		for(int j = 1; j < i; ++j)
			C[i][j] = (C[i-1][j-1] + C[i-1][j]) % mod;
	}
	scanf("%d", &n);
	int sum = 0;
	for(int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		ans = 1LL * ans * H(sum + 1, a[i] - 1) % mod;
		sum += a[i];
	}

	printf("%d\n", ans);
	return 0;
}