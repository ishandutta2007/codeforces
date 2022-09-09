#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2005;
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
char a[MAXN][MAXN];
int main() {
	int n, m, k, ans = 0;
	read(n), read(m), read(k);
	for (int i = 1; i <= n; i++)
		scanf("\n%s", a[i] + 1);
	if (k == 1) {
		for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (a[i][j] == '.') ans++;
		writeln(ans);
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		int now = 0;
		for (int j = 1; j <= m + 1; j++)
			if (a[i][j] == '.') now++;
			else {
				if (now >= k) ans += now - k + 1;
				now = 0;
			}
	}
	for (int j = 1; j <= m; j++) {
		int now = 0;
		for (int i = 1; i <= n + 1; i++)
			if (a[i][j] == '.') now++;
			else {
				if (now >= k) ans += now - k + 1;
				now = 0;
			}
	}
	writeln(ans);
	return 0;
}