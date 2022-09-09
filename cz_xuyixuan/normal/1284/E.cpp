#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
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
struct point {int x, y; };
point operator + (point a, point b) {return (point) {a.x + b.x, a.y + b.y}; }
point operator - (point a, point b) {return (point) {a.x - b.x, a.y - b.y}; }
point operator * (point a, int b) {return (point) {a.x * b, a.y * b}; }
long long operator * (point a, point b) {return 1ll * a.x * b.y - 1ll * a.y * b.x; }
long long dist(point a) {return 1ll * a.x * a.x + 1ll * a.y * a.y; }
point a[MAXN], b[MAXN];
bool where(point a) {
	return a.y > 0 || (a.y == 0 && a.x > 0);
}
bool cmp(point a, point b) {
	if (where(a) == where(b)) return a * b > 0;
	else return where(a) < where(b);
}
ll binom(ll x, int y) {
	ll ans = 1;
	for (int i = 1; i <= y; i++) {
		ans *= x - i + 1;
		ans /= i;
	}
	return ans;
}
ll solve(int n) {
	sort(a + 1, a + n + 1, cmp);
	int tmp = n, pos = 0;
	ll ans = binom(n, 4);
	for (int i = 1; i <= n; i++) {
		a[++tmp] = a[i];
		chkmax(pos, i);
		while (a[i] * a[pos + 1] > 0) pos++;
		ans -= binom(pos - i, 3);
	}
	return ans;
}
int main() {
	int n; read(n);
	for (int i = 1; i <= n; i++)
		read(b[i].x), read(b[i].y);
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		int m = 0;
		for (int j = 1; j <= n; j++)
			if (i != j) a[++m] = b[j] - b[i];
		ans += solve(n - 1);
	}
	cout << ans << endl;
	return 0;
}