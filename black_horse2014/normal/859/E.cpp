#include <bits/stdc++.h>
using namespace std;

const int MAXN = 210000;
const int MOD = 1e9+7;

int a[MAXN], chk[MAXN], b[MAXN], c[MAXN];

int main() {
	int n; scanf("%d", &n);
	for (int i = 1, u, v; i <= n; i++) scanf("%d%d", &u, &v), a[u] = v;
	int ans = 1;
	for (int i = 1; i <= 2*n; i++) if (!chk[i] && a[i]) {
		int j = i;
		while (!chk[j] && a[j]) chk[j] = i, j = a[j];
		if (!a[j] || b[j]) {
			if (!a[j]) b[j] = j;
			for (int k = i; k != j; k = a[k]) b[k] = b[j];
		} else if (chk[j] == i) {
			int len = 1;
			for (int k = a[j]; k != j; len++, k = a[k]);
			if (len > 1) ans = 2LL * ans % MOD;
		}
	}
	for (int i = 1; i <= 2*n; i++) if (a[i]) c[b[i]]++;
	for (int i = 1; i <= 2*n; i++) ans = 1LL * ans * (c[i] + 1) % MOD;
	cout << ans << endl;
	return 0;
}