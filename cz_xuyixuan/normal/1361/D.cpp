#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 5;
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
point a[MAXN];
int where(point a) {
	if (a.x == 0 && a.y == 0) return -1;
	else return (a.x > 0) || (a.x == 0 && a.y > 0);
}
ll moo(point a) {
	return 1ll * a.x * a.x + 1ll * a.y * a.y;
}
bool cmp(point a, point b) {
	if (where(a) == where(b)) {
		if (a * b == 0) return moo(a) < moo(b);
		else return a * b > 0;
	} else return where(a) < where(b);
}
int n, k, cnt[MAXN]; double depth[MAXN];
int main() {
	read(n), read(k);
	for (int i = 1; i <= n; i++)
		read(a[i].x), read(a[i].y);
	sort(a + 1, a + n + 1, cmp);
	int Min = n;
	for (int i = n; i >= 2; i--) {
		if (i != n && where(a[i]) == where(a[i + 1]) && a[i] * a[i + 1] == 0) cnt[i] = cnt[i + 1] + 1;
		else cnt[i] = 1; depth[i] = sqrt(moo(a[i]));
		chkmin(Min, n - cnt[i]);
	}
	if (k == n || k >= Min * 2) {
		double ans = 0;
		for (int i = 2; i <= n; i++) {
			int x = cnt[i], y = n - cnt[i];
			if (x > y) swap(x, y);
			double len = depth[i];
			if (cnt[i - 1] == cnt[i] + 1) len -= depth[i - 1];
			if (x * 2 <= k) ans += len * x * (k - x);
			else ans += len * (k / 2) * ((k + 1) / 2);
		}
		printf("%.10lf\n", ans);
		return 0;
	}
	static double inc[MAXN];
	for (int i = 2; i <= n; i++)
		inc[i] = depth[i] * (k + 1 - cnt[i] * 2);
	sort(inc + 2, inc + n + 1);
	double ans = 0;
	for (int i = n; i >= 2 && k--; i--)
		ans += inc[i];
	printf("%.10lf\n", ans);
	return 0;
}