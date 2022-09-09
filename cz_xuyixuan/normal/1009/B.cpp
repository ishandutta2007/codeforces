#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
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
int main() {
	scanf("%s", s + 1);
	int n = strlen(s + 1), cnt = 0;
	for (int i = 1; i <= n; i++)
		if (s[i] == '1') cnt++;
	for (int i = 1; i <= n; i++)
		if (s[i] != '1') {
			if (s[i] == '0') putchar(s[i]);
			else {
				if (cnt > 0) while (cnt--) putchar('1');
				putchar(s[i]);
			}
		}
	if (cnt > 0) while (cnt--) putchar('1');
	return 0;
}