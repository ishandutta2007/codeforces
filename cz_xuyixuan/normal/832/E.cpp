#include<bits/stdc++.h>
using namespace std;
#define MAXN	1005
#define P	1000000007
int inv[5] = {0, 1, 3, 2, 4};
int n, m, q;
int a[MAXN][MAXN];
bool used[MAXN];
char s[MAXN];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("\n%s", s + 1);
		for (int j = 1; j <= m; j++)
			a[j][i] = s[j] - 'a';
	}
	scanf("%d", &q);
	for (int i = 1; i <= q; i++) {
		scanf("\n%s", s + 1);
		for (int j = 1; j <= m; j++)
			a[j][i + n] = s[j] - 'a';
	}
	long long ans = 1;
	for (int i = 1; i <= n; i++) {
		int pos = 0;
		for (int j = 1; j <= m; j++)
			if (a[j][i] && !used[j]) {
				pos = j;
				break;
			}
		if (pos == 0) {
			ans = ans * 5 % P;
			continue;
		}
		used[pos] = true;
		for (int j = 1; j <= m; j++) {
			if (used[j]) continue;
			int tmp = inv[a[pos][i]] * a[j][i] % 5;
			for (int k = 1; k <= n + q; k++)
				a[j][k] = (a[j][k] - a[pos][k] * tmp % 5 + 5) % 5;
		}
	}
	for (int i = 1; i <= q; i++) {
		bool flg = true;
		for (int j = 1; j <= m; j++)
			if (!used[j] && a[j][i + n]) {
				flg = false;
				break;
			}
		printf("%I64d\n", ans * flg);
	}
	return 0;
}