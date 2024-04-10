#include<bits/stdc++.h>
using namespace std;
#define MAXN	100005
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
int ans[MAXN], tot;
int sum(int x) {
	int ans = 0;
	while (x) {
		ans += x % 10;
		x /= 10;
	}
	return ans;
}
int main() {
	int n; read(n);
	for (int i = max(1, n - 10000); i <= n; i++)
		if (i + sum(i) == n) ans[++tot] = i;
	printf("%d\n", tot);
	for (int i = 1; i <= tot; i++)
		printf("%d ", ans[i]);
	return 0;
}