#include <iostream>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

int dp[5009][5009], dp2[5009][5009];

int n, a[5009], q, l, r;

void init() {
	for (int i = 1; i <= n; i++) dp[i][i] = a[i];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n - i; j++) {
			int l = j, r = j + i;
			dp[l][r] = (dp[l][r - 1] ^ dp[l + 1][r]);
		}
	}
	for (int i = 0; i <= n; i++) {
		for (int j = 1; j <= n - i; j++) {
			int l = j, r = j + i;
			dp2[l][r] = max({ dp[l][r],dp2[l][r - 1],dp2[l + 1][r] });
		}
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	init();
	cin >> q;
	for (int i = 1; i <= q; i++) {
		scanf("%d%d", &l, &r);
		printf("%d\n", dp2[l][r]);
	}
	return 0;
}