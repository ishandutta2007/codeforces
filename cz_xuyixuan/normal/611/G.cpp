#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
const int P = 1e9 + 7;
typedef long long ll;
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
struct point {int x, y; };
point operator + (point a, point b) {return (point) {a.x + b.x, a.y + b.y}; }
point operator - (point a, point b) {return (point) {a.x - b.x, a.y - b.y}; }
point operator * (point a, int b) {return (point) {a.x * b, a.y * b}; }
long long operator * (point a, point b) {return 1ll * a.x * b.y - 1ll * a.y * b.x; }
point a[MAXN]; int prex[MAXN], prey[MAXN], uses[MAXN], f[MAXN], g[MAXN]; ull pres[MAXN];
void update(int &x, int y) {
	x += y;
	if (x >= P) x -= P;
}
ull area(int l, int r) {
	return pres[r - 1] - pres[l - 1] + a[r] * a[l];
}
int main() {
	int n; read(n);
	for (int i = 1, j = n; i <= n; i++, j--) {
		read(a[j].x), read(a[j].y);
		a[j + n] = a[j];
	}
	ull sum = 0;
	for (int i = 1; i <= n; i++)
		sum += a[i] * a[i + 1];
	a[2 * n + 1] = a[1];
	for (int i = 1; i <= 2 * n; i++) {
		pres[i] = pres[i - 1] + a[i] * a[i + 1];
		prex[i] = prex[i - 1] + a[i].x;
		if (prex[i] < 0) prex[i] += P;
		if (prex[i] >= P) prex[i] -= P;
		prey[i] = prey[i - 1] + a[i].y;
		if (prey[i] < 0) prey[i] += P;
		if (prey[i] >= P) prey[i] -= P;
	}
	int ans = 0, pos = 1;
	for (int i = 1; i <= n; i++) {
		while (area(i, pos + 1) * 2 < sum) pos++;
		int cnt = pos - i - 1, res = 0;
		update(res, 1ll * a[i].y * (prex[pos] - prex[i] + P) % P);
		update(res, 1ll * a[i].x * (prey[i] - prey[pos] + P) % P);
		update(f[i], cnt + 1), update(g[i + 1], P - 1), update(g[pos + 1], 1);
		update(ans, sum % P * cnt % P), update(ans, (P - 2ll * res % P) % P);
	}
	for (int i = 1; i <= 2 * n; i++) {
		update(g[i], g[i - 1]);
		update(f[i], f[i - 1]);
		update(f[i], g[i]);
		update(ans, (P - a[i] * a[i + 1] % P * 2ll * f[i] % P) % P);
	}
	cout << ans << endl;
	return 0;
}