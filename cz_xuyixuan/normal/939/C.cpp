#include<bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
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
long long a[MAXN], sum[MAXN];
int main() {
	int n; read(n);
	for (int i = 1; i <= n; i++)
		read(a[i]), a[i + n] = a[i];
	for (int i = 1; i <= 2 * n; i++)
		sum[i] = a[i] + sum[i - 1];
	int s, f; read(s), read(f);
	long long ans = 0; int pos = 1;
	for (int i = 1; i <= n; i++) {
		int start = s - i + n;
		if (start >= n) start -= n;
		long long tmp = sum[start + f - s] - sum[start];
		if (tmp > ans) {
			ans = tmp;
			pos = i;
		}
	}
	writeln(pos);
	return 0;
}