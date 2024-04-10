#include<bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 5;
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
long long a[MAXN], f[MAXN];
int n, m, p, ans[MAXN];
bool odd[MAXN];
void operate(int pos) {
	if (pos >= n || pos <= 0) return;
	int tmp = min(a[pos], a[pos + 1]);
	if (tmp == 0) return;
	ans[++m] = pos;
	a[pos] -= tmp; a[pos + 1] -= tmp;
}
int main() {
	read(n);
	for (int i = 1; i <= n; i++)
		read(a[i]);
	for (int i = 1; i <= n; i++) {
		long long fo = f[max(i - 2, 0)] + a[i];
		long long fe = f[max(i - 3, 0)] + max(a[i], a[i - 1]);
		f[i] = min(fo, fe);
		odd[i] = f[i] == fo;
	}
	long long vans = min(f[n - 1], f[n]);
	if (vans == f[n - 1]) p = n - 1;
	else p = n;
	while (p != 0) {
		if (odd[p]) {
			operate(p);
			operate(p - 1);
			p -= 2;
		} else {
			operate(p - 1);
			operate(p - 2);
			operate(p);
			p -= 3;
		}
		p = max(p, 0);
	}
	writeln(m);
	for (int i = 1; i <= m; i++)
		writeln(ans[i]);
	return 0;
}