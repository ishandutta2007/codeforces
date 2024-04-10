#include<bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
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
char s[MAXN], t[MAXN];
int main() {
	int n, m; read(n), read(m);
	scanf("\n%s", s + 1);
	scanf("\n%s", t + 1);
	int pos = 0;
	for (int i = 1; i <= n; i++)
		if (s[i] == '*') pos = i;
	if (pos == 0) {
		bool flg = n == m;
		for (int i = 1; i <= n; i++)
			flg &= s[i] == t[i];
		if (flg) printf("YES\n");
		else printf("NO\n");
	} else {
		bool flg = n - 1 <= m;
		for (int i = 1; i <= pos - 1; i++)
			flg &= s[i] == t[i];
		for (int i = pos + 1; i <= n; i++)
			flg &= s[i] == t[m - (n - i)];
		if (flg) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}