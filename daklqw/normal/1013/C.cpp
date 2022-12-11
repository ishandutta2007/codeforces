#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAXN 200010
#define int long long 
int a[MAXN], n;
signed main() {
	scanf("%I64d", &n);
	for (int i = 1; i <= n << 1; ++i) scanf("%I64d", &a[i]);
	sort(a + 1, a + 1 + (n << 1));
	int ans = 0x3f3f3f3f3f3f3f3fLL, cur = n + 1;
	for (int i = n; i != n << 1; ++i) {
		ans = min(ans, (a[i] - a[1]) * (a[n << 1] - a[cur]));
		--cur;
	}
	cur = n + 1;
	for (int i = 2; i <= n; ++i) {
		ans = min(ans, (a[n << 1] - a[1]) * (a[cur] - a[i]));
		++cur;
	}
	printf("%I64d\n", ans);
	return 0;
}