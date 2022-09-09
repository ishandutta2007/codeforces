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
int n, a[MAXN], b[MAXN], x[MAXN];
int func(int a, int b, int x) {
	if (a == b) return a;
	else if (a == 0) return 0;
	else return 1 - x;
}
bool tryans(int f) {
	x[1] = f;
	for (int i = 1; i <= n - 1; i++)
		x[i + 1] = func(a[i] / 2, b[i] / 2, x[i] / 2) * 2 + func(a[i] % 2, b[i] % 2, x[i] % 2);
	for (int i = 1; i <= n - 1; i++) {
		if ((x[i] | x[i + 1]) != a[i]) return false;
		if ((x[i] & x[i + 1]) != b[i]) return false;
	}
	return true;
}
void answer() {
	printf("YES\n");
	for (int i = 1; i <= n; i++)
		printf("%d ", x[i]);
	exit(0);
}
int main() {
	read(n);
	for (int i = 1; i <= n - 1; i++)
		read(a[i]);
	for (int i = 1; i <= n - 1; i++)
		read(b[i]);
	if (tryans(0)) answer();
	if (tryans(1)) answer();
	if (tryans(2)) answer();
	if (tryans(3)) answer();
	printf("NO\n");
	return 0;
}