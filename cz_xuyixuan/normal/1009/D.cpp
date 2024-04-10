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
int gcd(int x, int y) {
	if (y == 0) return x;
	else return gcd(y, x % y);
}
int tot, x[MAXN], y[MAXN];
int main() {
	int n, m; read(n), read(m);
	if (m < n - 1) {
		printf("Impossible\n");
		return 0;
	}
	for (int i = 1; i <= n; i++)
	for (int j = i + 1; j <= n; j++)
		if (gcd(i, j) == 1) {
			tot++; x[tot] = i, y[tot] = j;
			if (tot == m) {
				printf("Possible\n");
				for (int k = 1; k <= m; k++)
					printf("%d %d\n", x[k], y[k]);
				return 0;
			}
		}
	printf("Impossible\n");
	return 0;
}