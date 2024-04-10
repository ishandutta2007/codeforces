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
int main() {
	long long n, ans = 0, cnt = 0;
	int k, pos = 1; read(n); read(k);
	for (int i = 1; i <= k; i++) {
		long long x; read(x);
		long long tcnt = n / x;
		long long tans = tcnt * x;
		if (tans > ans) {
			ans = tans;
			cnt = tcnt;
			pos = i;
		}
	}
	cout << pos << ' ' << cnt << endl;
	return 0;
}