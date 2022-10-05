#include<bits/stdc++.h>
using namespace std;

const int maxn = 20000009;
int p[maxn], flag[maxn], ans[maxn], res, cnt, n, sum, a;

void init() {
	for (int i=2; i<maxn; i++) {
		if (!flag[i]) p[++cnt] = i;
		for (int j=1; j<=cnt&&i*p[j]<maxn; j++) {
			flag[i*p[j]] = 1;
			if (i%p[j] == 0) break;
		}
	}
}

int main() {
	scanf("%d", &n); init();
	sum = n * (n + 1) / 2;
	if (flag[sum]) {
		if (!flag[sum-2]) ans[2] = 1;
		else {
			if (sum&1) {
				a = n; while (flag[a]) a--;
				ans[a] = 2; sum -= a;
			}
			a = 3;
			while (a <= sum && (flag[a] || flag[sum-a])) a++;
			for (int i=n; i>=1; i--)
				if (!ans[i] && a >= i) {
					ans[i] = 1; a -= i;
				}
		}
	}
	for (int i=1; i<=n; i++) printf("%d ", ans[i]+1);
	return 0;
}