#include<bits/stdc++.h>
using namespace std;
const int MAXN = 105;
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
char name[MAXN][5];
int n, k, ans[MAXN];
int main() {
	read(n), read(k);
	for (int i = 1; i <= n; i++) {
		name[i][0] = 'A' + i / 26;
		name[i][1] = 'a' + i % 26;
		if (i < k) ans[i] = i;
		else {
			char opt[5];
			scanf("\n%s", opt);
			if (opt[0] == 'Y') ans[i] = i;
			else ans[i] = ans[i - k + 1];
		}
	}
	for (int i = 1; i <= n; i++)
		printf("%s ", name[ans[i]]);
	return 0;
}