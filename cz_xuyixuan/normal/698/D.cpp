#include<bits/stdc++.h>
using namespace std;
const int MAXN = 15;
const int MAXM = 1005;
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
long long moo(point a) {return 1ll * a.x * a.x + 1ll * a.y * a.y; }
point a[MAXM], p[MAXM]; bool flg, visa[MAXN], visp[MAXM];
int n, m, top, res[MAXN], nxt[MAXN][MAXM];
pair <point, int> b[MAXM];
void work(int depth) {
	if (top > n) return;
	if (depth > top) {
		flg = true;
		return;
	}
	for (int i = 1; i <= n; i++)
		if (!visa[i]) {
			visa[i] = true;
			int old = top, pos = nxt[i][res[depth]];
			while (pos != 0 && top <= n) {
				if (!visp[pos]) {
					visp[pos] = true;
					res[++top] = pos;
				}
				pos = nxt[i][pos];
			}
			work(depth + 1);
			while (top > old) visp[res[top--]] = false;
			visa[i] = false;
		}
}
bool where(point a) {
	return a.x > 0 || (a.x == 0 && a.y > 0);
}
bool cmp(pair <point, int> a, pair <point, int> b) {
	if (where(a.first) == where(b.first)) {
		if (a.first * b.first == 0) return moo(a.first) > moo(b.first);
		else return a.first * b.first > 0;
	} else return where(a.first) < where(b.first);
}
int main() {
	read(n), read(m);
	for (int i = 1; i <= n; i++)
		read(a[i].x), read(a[i].y);
	for (int i = 1; i <= m; i++)
		read(p[i].x), read(p[i].y);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			b[j] = make_pair(p[j] - a[i], j);
		sort(b + 1, b + m + 1, cmp);
		for (int j = 1; j <= m - 1; j++)
			if (where(b[j].first) == where(b[j + 1].first) && b[j].first * b[j + 1].first == 0)
				nxt[i][b[j].second] = b[j + 1].second;
	}
	int ans = 0;
	for (int i = 1; i <= m; i++) {
		flg = false;
		visp[i] = true;
		res[top = 1] = i;
		work(1), ans += flg;
		visp[i] = false;
	}
	printf("%d\n", ans);
	return 0;
}