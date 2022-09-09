#include<bits/stdc++.h>
using namespace std;
const int MAXLOG = 62;
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
long long delta[MAXLOG], size[MAXLOG], l[MAXLOG], r[MAXLOG];
long long rnk(int pos, long long x) {
	long long tmp = x - l[pos] + delta[pos];
	return tmp % size[pos];
}
long long fnd(int pos, long long x) {
	long long tmp = x - delta[pos] + size[pos];
	return tmp % size[pos] + l[pos];
}
int main() {
	size[0] = l[0] = r[0] = 1;
	for (int i = 1; i < MAXLOG; i++) {
		size[i] = size[i - 1] << 1;
		l[i] = r[i - 1] + 1;
		r[i] = r[i - 1] + size[i];
	}
	int q; read(q);
	while (q--) {
		int opt, pos;
		long long x, y;
		read(opt), read(x);
		for (int i = 0; i < MAXLOG; i++)
			if (x <= r[i]) {
				pos = i;
				break;
			}
		if (opt == 1) {
			read(y); y %= size[pos];
			if (y < 0) y += size[pos];
			delta[pos] = (delta[pos] + y) % size[pos];
		}
		if (opt == 2) {
			read(y); y %= size[pos];
			if (y < 0) y += size[pos];
			for (int i = pos; i < MAXLOG; i++) {
				delta[i] = (delta[i] + y) % size[i];
				y <<= 1;
			}
		}
		if (opt == 3) {
			printf("%lld", x);
			for (int i = pos; i >= 1; i--) {
				long long tmp = rnk(i, x);
				x = fnd(i - 1, tmp / 2);
				printf(" %lld", x);
			}
			printf("\n");
		}
	}
	return 0;
}