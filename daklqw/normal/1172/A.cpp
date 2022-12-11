#include <bits/stdc++.h>

const int MAXN = 200010;
int A[MAXN], B[MAXN], n;
int lst = 0;
void push(int x) {
	if (x == 1) lst = 1;
	else if (x == lst + 1) ++lst;
	else lst = 0;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", A + i);
	for (int i = 1; i <= n; ++i) scanf("%d", B + i), push(B[i]);
	int ans = 0;
	bool can = true;
	for (int i = 1; i <= n; ++i) {
		if (B[i]) {
			ans = std::max(ans, i - B[i] + 1);
		}
	}
	if (lst) {
		int at = B[n];
		for (int i = n; i > n - at; --i) B[i] = 0;
	}
	for (int i = 1; i <= n; ++i) {
		if (B[i])
			can &= B[i] - lst > i;
	}
	if (can) printf("%d\n", n - lst);
	else printf("%d\n", ans + n);
	return 0;
}