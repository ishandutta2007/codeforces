#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int T;
int a[maxn];
int n;
int main() {
//	freopen(".in", "r", stdin);
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
		for (int i = 2; i <= n; ++i)
		if (abs(a[i] - a[i - 1]) >= 2) {
			puts("YES");
			printf("%d %d\n", i - 1, i);
			goto loop;
		}
		puts("NO");
		loop:;
	}
	return 0;
}