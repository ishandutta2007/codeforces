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
ll cnt[2];
int main() {
	int n; read(n);
	for (int i = 1; i <= n; i++) {
		int x; read(x);
		if (i & 1) cnt[0] += x / 2, cnt[1] += x - x / 2;
		else cnt[1] += x / 2, cnt[0] += x - x / 2;
	}
	cout << min(cnt[0], cnt[1]) << endl;
	return 0;
}