#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN = 100010;
int A[MAXN], n;
int lx = 0, ans = 0;
void app(int x) {
	ans = std::max(ans, std::min(lx, x));
	lx = x;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", A + i);
	int lst = A[1], now = 1;
	for (int i = 2; i <= n; ++i) {
		if (A[i] != lst) {
			app(now);
			now = 1; lst = A[i];
		} else ++now;
	}
	app(now);
	printf("%d\n", ans << 1);
	return 0;
}