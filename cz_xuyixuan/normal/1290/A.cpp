#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
template <typename T> void chkmax(T &x, T y) {x = max(x, y); }
template <typename T> void chkmin(T &x, T y) {x = min(x, y); } 
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
int a[MAXN], b[MAXN];
int main() {
	int T; read(T);
	while (T--) {
		int n, m, k;
		read(n), read(m), read(k);
		chkmin(k, m - 1);
		for (int i = 1; i <= n; i++)
			read(a[i]);
		for (int i = 0, j = n - m + 1; i <= m - 1; i++, j++)
			b[i] = max(a[i + 1], a[j]);
		int ans = 0;
		for (int i = 0, j = m - k - 1; j <= m - 1; i++, j++) {
			int Min = 2e9;
			for (int l = i; l <= j; l++)
				chkmin(Min, b[l]);
			chkmax(ans, Min);
		}
		cout << ans << endl;
	}
	return 0;
}