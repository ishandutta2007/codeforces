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
vector <int> a, b;
int main() {
	int n, m; read(n), read(m);
	int sum = n + m, tot = 0;
	while (sum >= tot + 1) {
		tot++;
		sum -= tot;
	}
	for (int i = tot; i >= 1; i--)
		if (n >= i) {
			n -= i;
			a.push_back(i);
		} else b.push_back(i);
	writeln(a.size());
	for (auto x : a)
		printf("%d ", x);
	printf("\n");
	writeln(b.size());
	for (auto x : b)
		printf("%d ", x);
	printf("\n");
	return 0;
}