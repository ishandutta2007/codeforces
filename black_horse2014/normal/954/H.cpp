#include <bits/stdc++.h>
using namespace std;

const int N = 5500;
const int MOD = 1e9 + 7;

int a[N], down[2*N], up[2*N], ans[2*N];

int main() {
	int n; scanf("%d", &n);
	for (int i = 1; i <= n-1; i++) scanf("%d", &a[i]);
	up[0] = down[0] = 1;
	for (int i = 1; i <= n-1; i++) down[i] = down[i-1] * 1LL * a[i] % MOD;
	for (int i = 1; i <= n-1; i++) ans[i] = (up[i] + down[i]) % MOD;
	for (int i = 1; i <= n-1; i++) {
		for (int j = 2*(n-1); j > 0; j--) up[j] = up[j-1] * 1LL * a[i] % MOD;
		down[0] = up[0] = up[0] * 1LL * a[i] % MOD;
		for (int j = 1; j <= n-1-i; j++) down[j] = down[j-1] * 1LL * a[i+j] % MOD;
		for (int j = n-i; j <= 2*(n-1); j++) down[j] = 0;
		for (int j = 2; j <= n+1-i; j++) up[j] = (up[j] + down[j-2] * 1LL * (a[i]-1)) % MOD;
		for (int j = 1; j <= 2*(n-1); j++) ans[j] = ((ans[j] + up[j]) % MOD + down[j]) % MOD;
	}
	for (int j = 1; j <= 2*(n-1); j++) ans[j] = ans[j] * 1LL * (MOD+1) / 2 % MOD;
	for (int j = 1; j <= 2*(n-1); j++) printf("%d ", ans[j]);
	return 0;
}