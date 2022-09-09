#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5005;
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
template <typename T> void write(T x) {
	if (x < 0) x = -x, putchar('-');
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
template <typename T> void writeln(T x) {
	write(x);
	puts("");
}
long long a[MAXN], b[MAXN];
int main() {
	int n, m; read(n), read(m);
	for (int i = 1; i <= n; i++)
		read(a[i]);
	for (int i = 1; i <= m; i++)
		read(b[i]);
	long long ans = 1e18;
	for (int i = 1; i <= n; i++) {
		long long now = -1e18;
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			for (int k = 1; k <= m; k++)
				now = max(now, a[j] * b[k]);
		}
		ans = min(ans, now);
	}
	writeln(ans);
	return 0;
}