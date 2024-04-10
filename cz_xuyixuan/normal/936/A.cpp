#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
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
	long long k, d, t;
	read(k), read(d), read(t);
	t = t * 2;
	long long c = (k - 1) / d + 1;
	long long len = c * d;
	long long cnt = k * 2 + (len - k);
	long long b = t / cnt;
	long long ans = b * len;
	t %= cnt;
	if (t <= k * 2) {
		ans += t / 2;
		if (t % 2 == 0) printf("%I64d\n", ans);
		else printf("%I64d.5\n", ans);
	} else {
		t -= k * 2;
		ans += k;
		ans += t;
		printf("%I64d\n", ans);
	}
	return 0;
}