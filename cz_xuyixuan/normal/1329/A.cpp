#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
typedef long long ll;
template <typename T> void chkmax(T &x, T y) {x = max(x, y); }
template <typename T> void chkmin(T &x, T y) {x = min(x, y); } 
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
int n, m, lft, a[MAXN], ans[MAXN];
int main() {
	read(m), read(n), lft = m;
	for (int i = 1; i <= n; i++)
		read(a[i]);
	for (int i = n; i >= 1; i--) {
		if (m - i + 1 < a[i]) {
			puts("-1");
			return 0;
		}
		ans[i] = max(i, lft - a[i] + 1);
		lft = ans[i] - 1;
	}
	if (lft != 0) {
		puts("-1");
		return 0;
	}
	for (int i = 1; i <= n; i++)
		printf("%d ", ans[i]);
	printf("\n");
	return 0;
}