#include<bits/stdc++.h>
using namespace std;
const int MAXN = 8e5 + 5;
const int INF  = 1e5;
typedef long long ll;
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
long long dist(point a) {return 1ll * a.x * a.x + 1ll * a.y * a.y; }
bool operator < (point a, point b) {
	if (a.y == b.y) return a.x < b.x;
	else return a.y < b.y;
}
int n, m;
point a[MAXN];
bool cmp(point x, point y) {
	if ((x - a[1]) * (y - a[1]) == 0) return dist(x - a[1]) < dist(y - a[1]);
	else return (x - a[1]) * (y - a[1]) > 0;
}
int main() {
	read(n);
	for (int i = 1; i <= n; i++) {
		point pos; int v;
		read(pos.x), read(pos.y), read(v);
		if (pos.x + v <= INF) a[++m] = (point) {pos.x + v, pos.y};
		else {
			a[++m] = (point) {INF, min(pos.y + v - (INF - pos.x), INF)};
			a[++m] = (point) {INF, max(pos.y + (INF - pos.x) - v, 0)};
		}
		if (pos.y + v <= INF) a[++m] = (point) {pos.x, pos.y + v};
		else {
			a[++m] = (point) {min(pos.x + v - (INF - pos.y), INF), INF};
			a[++m] = (point) {max(pos.x + (INF - pos.y) - v, 0), INF};
		}
		if (pos.x >= v) a[++m] = (point) {pos.x - v, pos.y};
		else {
			a[++m] = (point) {0, min(pos.y + v - pos.x, INF)};
			a[++m] = (point) {0, max(pos.y - v + pos.x, 0)};
		}
		if (pos.y >= v) a[++m] = (point) {pos.x, pos.y - v};
		else {
			a[++m] = (point) {min(pos.x + v - pos.y, INF), 0};
			a[++m] = (point) {max(pos.x - v + pos.y, 0), 0};
		}
	}
	for (int i = 1; i <= m; i++)
		if (a[i] < a[1]) swap(a[i], a[1]);
	sort(a + 2, a + m + 1, cmp), a[m + 1] = a[1];
	int top = 1;
	for (int i = 2; i <= m + 1; i++) {
		while (top >= 2 && (a[i] - a[top - 1]) * (a[top] - a[top - 1]) >= 0) top--;
		a[++top] = a[i];
	}
	point p, q, r; double ans = 0; a[top + 1] = a[2];
	for (int i = 2; i <= top; i++) {
		point x = a[i + 1] - a[i], y = a[i - 1] - a[i], z = a[i + 1] - a[i - 1];
		double cur = sqrt(dist(x)) * sqrt(dist(y)) * sqrt(dist(z)) / (x * y);
		if (cur > ans) {
			ans = cur;
			p = a[i - 1], q = a[i], r = a[i + 1];
		}
	}
	printf("%d %d\n%d %d\n%d %d\n", p.x, p.y, q.x, q.y, r.x, r.y);
	return 0;
}