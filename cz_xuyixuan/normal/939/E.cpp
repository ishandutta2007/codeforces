#include<bits/stdc++.h>
using namespace std;
const int MAXN = 500005;
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
long long x[MAXN], sum[MAXN];
int main() {
	int T; read(T);
	int n = 0;
	while (T--) {
		int opt; read(opt);
		if (opt == 1) read(x[++n]), sum[n] = sum[n - 1] + x[n];
		else {
			long double ans = x[n] - sum[n] * 1.0 / n;
			int l = 1, r = n - 1;
			while (l <= r) {
				int mid = (l + r) / 2;
				long double tmp = x[n] - (sum[mid] + x[n]) / (mid + 1.0);
				ans = max(ans, tmp);
				long double tnp = x[n] - (sum[mid + 1] + x[n]) / (mid + 2.0);
				if (tnp > tmp) l = mid + 1;
				else r = mid - 1;
			}
			printf("%.10Lf\n", ans);
		}
	}
	return 0;
}