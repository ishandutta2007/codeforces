#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5005;
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
int n, k;
long long a, b, ans;
int main() {
	read(n), read(k), read(a), read(b);
	while (n != 1) {
		if (n % k == 0) {
			int m = n / k;
			if (b < a * (n - m)) {
				ans += b;
				n /= k;
			} else ans += a * (n - 1), n = 1;
		} else {
			int m = (n / k) * k;
			ans += a * (n - m);
			n = m;
		}
	}
	writeln(ans);
	return 0;
}