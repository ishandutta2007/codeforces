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
int getv() {
	int ans = 0, x;
	read(x), ans += x;
	read(x), ans += x;
	read(x), ans += x;
	read(x), ans += x;
	return ans;
}
int main() {
	int n, ans = 1;
	read(n); n--;
	int now = getv();
	while (n--) {
		int tmp = getv();
		if (tmp > now) ans++;
	}
	writeln(ans);
	return 0;
}