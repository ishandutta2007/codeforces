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
void force() {
	int a, b; read(a), read(b);
	int n = a + b, ans = 0;
	for (int i = 1; i <= n; i++) {
		int r = n / i, delta = (n % i - (a % r + b % r)) / r;
		if (delta >= 0 && a / r >= a % r && b / r >= b % r && delta - (a / r - a % r) / (r + 1) - (b / r - b % r) / (r + 1) <= 0) ans++;
	}
	writeln(ans);
}
int main() {
	int a, b; read(a), read(b);
	int n = a + b, ans = 0;
	for (int i = 1, nxt; i <= n; i = nxt + 1) {
		int r = n / i; nxt = n / r;
		if (a / r >= a % r && b / r >= b % r) {
			int Min = (a % r + b % r);
			int Max = ((a / r - a % r) / (r + 1) + (b / r - b % r) / (r + 1)) * r + (a % r + b % r);
			int rMin = (n - Max) / r + ((n - Max) % r != 0);
			int rMax = (n - Min) / r;
			chkmax(rMin, i);
			chkmin(rMax, nxt);
			if (rMin <= rMax) ans += rMax - rMin + 1;
		}
	}
	writeln(ans);
	return 0;
}