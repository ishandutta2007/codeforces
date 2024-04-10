#include <bits/stdc++.h>
using namespace std;

const int N = 110;

int c[N], d[N], e[N];

int main() {
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) scanf("%d", &c[i]);
	for (int i = 1; i <= m; i++) scanf("%d", &d[i]);
	int sum = 0;
	for (int i = 1; i <= m; i++) sum += d[i];
	for (int i = 0; i <= n - sum; i++) {
		memset(e, 0, sizeof e);
		for (int j = i; j < i + sum; j++) e[c[j]]++;
		int flg = 0;
		for (int j = 1; j <= m; j++) if (e[j] != d[j]) {
			flg = 1;
			break;
		}
		if (!flg) return puts("YES"), 0;
	}
	puts("NO");
	return 0;
}