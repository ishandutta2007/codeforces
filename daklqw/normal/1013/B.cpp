#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAXN 1000010
int n, x, a[MAXN], b[MAXN], cnt1[MAXN], cnt2[MAXN];
int main() {
	scanf("%d%d", &n, &x);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		b[i] = a[i] & x;
		if (b[i] != a[i]) ++cnt2[b[i]];
		++cnt1[a[i]];
	}
	int ans = 0x3f3f3f3f, f2 = 0;
	for (int i = 0; i <= 100000; ++i) 
		if (cnt1[i] >= 2) {
			puts("0");
			return 0;
		} else if (cnt1[i] == 1) {
			if (cnt2[i])
				ans = min(ans, 1);
		} else if (cnt2[i] >= 2) ans = min(ans, 2);
	if (ans == 0x3f3f3f3f) puts("-1");
	else printf("%d\n", ans);
	return 0;
}