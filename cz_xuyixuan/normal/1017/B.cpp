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
char s[MAXN], t[MAXN];
long long one, zero, oneone, zeroone;
int main() {
	int n; read(n);
	scanf("\n%s", s + 1);
	scanf("\n%s", t + 1);
	for (int i = 1; i <= n; i++) {
		if (s[i] == '1') {
			one++;
			if (t[i] == '1') oneone++;
		} else {
			zero++;
			if (t[i] == '1') zeroone++;
		}
	}
	writeln(one * zero - oneone * zeroone);
	return 0;
}