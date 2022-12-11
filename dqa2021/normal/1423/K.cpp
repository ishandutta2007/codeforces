#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= int(b); i++)
#define per(i, a, b) for (int i = (a); i >= int(b); i--)
using namespace std;

const int maxn = 1e6;
int T, n, ans[maxn + 5], c, p[maxn + 5];
bool b[maxn + 5];

void work(int n) {
	fill(ans + 1, ans + n + 1, 1);
	rep(i, 2, n) {
		if (!b[i]) {
			p[++c] = i;
		}
		for (int j = 1; j <= c && i * p[j] <= n; j++) {
			b[i * p[j]] = true;
			if (i % p[j] == 0) {
				break;
			}
		}
	}
	rep(i, 2, n) {
		int x = sqrt(i + .5) + 1;
		ans[i] += lower_bound(p + 1, p + c + 1, i + 1) - lower_bound(p + 1, p + c + 1, x);
	}
}

int main() {
	work(maxn);
	scanf("%d", &T);
	for (; T --> 0; ) {
		scanf("%d", &n);
		printf("%d\n", ans[n]);
	}
	return 0;
}