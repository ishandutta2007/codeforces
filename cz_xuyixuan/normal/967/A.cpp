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
int n, s, a[MAXN];
bool valid(int x) {
	if (x + s < a[1]) return true;
	if (x - s > a[n]) return true;
	for (int i = 1; i < n; i++)
		if (x - s > a[i] && x + s < a[i + 1]) return true;
	return false;
}
int main() {
	read(n), read(s);
	for (int i = 1; i <= n; i++) {
		int x, y;
		read(x), read(y);
		a[i] = x * 60 + y;
	}
	int ans = 0;
	while (!valid(ans)) ans++;
	printf("%d %d\n", ans / 60, ans % 60);
	return 0;
}