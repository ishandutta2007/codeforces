#include<bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 5;
const int MAXV = 1.5e7 + 5;
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
int n, tot, a[MAXN], prime[MAXV], f[MAXV], cnt[MAXV];
void init(int n) {
	for (int i = 2; i <= n; i++) {
		if (f[i] == 0) prime[++tot] = f[i] = i;
		for (int j = 1; j <= tot && prime[j] <= f[i]; j++) {
			int tmp = prime[j] * i;
			if (tmp > n) break;
			f[tmp] = prime[j];
		}
	}
}
int gcd(int x, int y) {
	if (y == 0) return x;
	else return gcd(y, x % y);
}
int main() {
	init(1.5e7);
	int g = 0; read(n);
	for (int i = 1; i <= n; i++) {
		read(a[i]);
		g = gcd(a[i], g);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int tmp = a[i] / g;
		while (tmp != 1) {
			cnt[f[tmp]]++;
			if (cnt[f[tmp]] > ans) ans = cnt[f[tmp]];
			int tnp = f[tmp];
			while (tmp % tnp == 0) tmp /= tnp;
		}
	}
	if (ans == 0) printf("-1\n");
	else printf("%d\n", n - ans);
	return 0;
}