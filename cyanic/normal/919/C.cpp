#include<bits/stdc++.h>
using namespace std;

const int maxn = 2005;
char s[maxn][maxn];
int n, m, K, last;
long long ans;

int main() {
	scanf("%d%d%d", &n, &m, &K);
	for (int i=1; i<=n; i++) scanf("%s", s[i] + 1);
	for (int i=1; i<=n; i++) {
		last = 0;
		for (int j=1; j<=m+1; j++)
			if (j == m + 1 || s[i][j] == '*') {
				ans += max(0, j-last-K);
				last = j;
			}
	}
	for (int i=1; i<=m; i++) {
		last = 0;
		for (int j=1; j<=n+1; j++)
			if (j == n + 1 || s[j][i] == '*') {
				ans += max(0, j-last-K);
				last = j;
			}
	}
	if (K == 1) ans /= 2;
	printf("%I64d\n", ans);
	return 0;
}