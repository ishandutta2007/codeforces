#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN = 1000010;
typedef long long LL;
int pre[MAXN], lst[MAXN], a[MAXN], n;
LL ans;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		pre[i] = lst[a[i]];
		lst[a[i]] = i;
		ans += static_cast<LL> (i - pre[i]) * (n - i + 1) - 1;
		// std::cout << ans << std::endl;
	}
	printf("%.6lf\n", (ans * 2 + n) / (static_cast<double> (n) * n));
	return 0;
}