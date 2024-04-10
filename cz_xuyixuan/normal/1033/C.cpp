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
int n, a[MAXN], p[MAXN];
bool dp[MAXN];
bool cmp(int x, int y) {
	return a[x] > a[y];
}
int main() {
	read(n);
	for (int i = 1; i <= n; i++)
		read(a[i]), p[i] = i;
	sort(p + 1, p + n + 1, cmp);
	for (int i = 1; i <= n; i++) {
		int pos = p[i];
		for (int j = pos + a[pos]; j <= n; j += a[pos])
			if (a[j] > a[pos]) dp[pos] |= !dp[j];
		for (int j = pos - a[pos]; j >= 1; j -= a[pos])
			if (a[j] > a[pos]) dp[pos] |= !dp[j];
	}
	for (int i = 1; i <= n; i++)
		if (dp[i]) putchar('A');
		else putchar('B');
	putchar('\n');
	return 0;
}