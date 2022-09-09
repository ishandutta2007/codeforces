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
int main() {
	int q; read(q);
	while (q--) {
		int n; read(n);
		int tmp = 1;
		while (tmp < n) {
			tmp <<= 1;
			tmp += 1;
		}
		if (tmp == n) {
			int ans = 1;
			for (int i = 2; i * i <= n; i++)
				if (n % i == 0) {
					ans = n / i;
					break;
				}
			writeln(ans);
		} else writeln(tmp);
	}
	return 0;
}