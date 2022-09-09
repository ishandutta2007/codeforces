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
char s[MAXN];
int sum[MAXN][26];
int main() {
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	for (int i = 1; i <= n; i++)
	for (int j = 0; j <= 25; j++)
		sum[i][j] = sum[i - 1][j] + (s[i] - 'a' == j);
	int q; read(q);
	while (q--) {
		int l, r; read(l), read(r);
		if (l == r || s[l] != s[r]) puts("Yes");
		else {
			int cnt = 0;
			for (int i = 0; i <= 25; i++)
				cnt += (sum[r][i] - sum[l - 1][i]) != 0;
			if (cnt >= 3) puts("Yes");
			else puts("No");
		}
	}
	return 0;
}