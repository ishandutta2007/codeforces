#include<bits/stdc++.h>
using namespace std;
const int MAXN = 4e5 + 5;
const long double eps = 1e-9;
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
bool operator < (point a, point b) {
	if (a.y == b.y) return a.x < b.x;
	else return a.y < b.y;
}
long long dist(point a) {return 1ll * a.x * a.x + 1ll * a.y * a.y; }
int n, m, q;
point a[MAXN], b[MAXN], fp;
long double val[MAXN], vbl[MAXN];
bool solve() {
	if (n != m) return false;
	n--, m--;
	long double px = 0, py = 0;
	for (int i = 1; i <= n; i++) {
		px += a[i].x;
		py += a[i].y;
	}
	px /= n, py /= n;
	for (int i = 1; i <= n; i++) {
		val[2 * i - 1] = sqrt((px - a[i].x) * (px - a[i].x) + (py - a[i].y) * (py - a[i].y));
		val[2 * i] = sqrt(1ll * (a[i + 1].x - a[i].x) * (a[i + 1].x - a[i].x) + 1ll * (a[i + 1].y - a[i].y) * (a[i + 1].y - a[i].y));
	}
	for (int i = 1; i <= 2 * n; i++)
		val[i + 2 * n] = val[i];
	px = 0, py = 0;
	for (int i = 1; i <= m; i++) {
		px += b[i].x;
		py += b[i].y;
	}
	px /= m, py /= m;
	for (int i = 1; i <= m; i++) {
		vbl[2 * i - 1] = sqrt((px - b[i].x) * (px - b[i].x) + (py - b[i].y) * (py - b[i].y));
		vbl[2 * i] = sqrt(1ll * (b[i + 1].x - b[i].x) * (b[i + 1].x - b[i].x) + 1ll * (b[i + 1].y - b[i].y) * (b[i + 1].y - b[i].y));
	}
	int la = n * 4;
	int lb = m * 2;
	static int nxt[MAXN];
	for (int i = 2; i <= lb; i++) {
		int p = nxt[i - 1];
		while (p && fabs(vbl[p + 1] - vbl[i]) > eps)
			p = nxt[p];
		if (fabs(vbl[p + 1] - vbl[i]) <= eps) p++;
		nxt[i] = p;
	}
	int pos = 0, ans = 0;
	for (int i = 1; i <= la; i++) {
		if (fabs(val[i] - vbl[pos + 1]) <= eps) {
			pos++;
			if (pos == lb) {
				ans++;
				pos = nxt[lb];
			}
		} else {
			while (pos && fabs(val[i] - vbl[pos + 1]) > eps)
				pos = nxt[pos];
			if (fabs(val[i] - vbl[pos + 1]) <= eps) pos++;
		}
	}
	return ans != 0;
}
bool cmp(point a, point b) {
	long long tmp = (a - fp) * (b - fp);
	if (tmp == 0) return dist(a - fp) < dist(b - fp);
	else return tmp > 0;
}
bool online(point *a, int n) {
	point tmp = a[n] - a[1];
	for (int i = 2; i <= n - 1; i++)
		if (tmp * (a[i] - a[1]) != 0) return false;
	return true;
}
int main() {
	read(n), read(m);
	for (int i = 1; i <= n; i++)
		read(a[i].x), read(a[i].y);
	for (int i = 2; i <= n; i++)
		if (a[i] < a[1]) swap(a[i], a[1]);
	fp = a[1];
	sort(a + 2, a + n + 1, cmp);
	for (int i = 1; i <= m; i++)
		read(b[i].x), read(b[i].y);
	for (int i = 2; i <= m; i++)
		if (b[i] < b[1]) swap(b[i], b[1]);
	fp = b[1];
	sort(b + 2, b + m + 1, cmp);
	if (online(a, n) && online(b, m)) {
		if (dist(a[n] - a[1]) == dist(b[m] - b[1])) printf("YES\n");
		else printf("NO\n");
		return 0;
	}
	a[++n] = a[1];
	int top = 1;
	for (int i = 2; i <= n; i++) {
		while (top >= 2 && (a[top] - a[top - 1]) * (a[i] - a[top - 1]) <= 0) top--;
		a[++top] = a[i];
	}
	n = top;
	b[++m] = b[1]; top = 1;
	for (int i = 2; i <= m; i++) {
		while (top >= 2 && (b[top] - b[top - 1]) * (b[i] - b[top - 1]) <= 0) top--;
		b[++top] = b[i];
	}
	m = top;
	if (solve()) printf("YES\n");
	else printf("NO\n");
	return 0;
}