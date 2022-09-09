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
long long gcd(long long x, long long y) {
	if (y == 0) return x;
	else return gcd(y, x % y);
}
int main() {
	int n; read(n);
	while (n--) {
		long long a, b, c;
		read(a), read(b), read(c);
		if (a % b == 0) printf("Finite\n");
		else {
			long long g = gcd(a, b);
			b /= g; g = gcd(b, c);
			for (int i = 1; i <= 64; i++) {
				g = gcd(b, g);
				b /= g;
			}
			if (b == 1) printf("Finite\n");
			else printf("Infinite\n");
		}
	}
	return 0;
}