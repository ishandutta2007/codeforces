#include<bits/stdc++.h>
using namespace std;
const int MAXN = 205;
const double eps = 1e-12;
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
int operator * (point a, point b) {return a.x * b.y - a.y * b.x; }
int n, p; point a[MAXN];
double mat[MAXN][MAXN][MAXN];
vector <int> line[MAXN * MAXN]; int tot;
double calc(int from, int to, int timer) {
	chkmin(timer, p);
	if (timer == 0) {
		if (from == to) return 1;
		else return 0;
	} else return mat[timer][from][to];
}
bool cmp(int x, int y) {
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= n; j++)
		if (fabs(mat[x][i][j] - mat[y][i][j]) > eps) return false;
	return true;
}
int main() {
	read(n);
	for (int i = 1; i <= n; i++)
		read(a[i].x), read(a[i].y);
	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			bool flg = true;
			for (int k = 1; k <= j - 1; k++)
				if (i != k && (a[k] - a[i]) * (a[k] - a[j]) == 0) flg = false;
			cnt += flg;
			if (flg && i < j) {
				tot++;
				for (int k = 1; k <= n; k++)
					if ((a[k] - a[i]) * (a[k] - a[j]) == 0) line[tot].push_back(k);
			} 
		}
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			bool flg = true;
			for (int k = 1; k <= j - 1; k++)
				if (i != k && (a[k] - a[i]) * (a[k] - a[j]) == 0) flg = false;
			if (!flg) continue;
			int cmt = 0;
			for (int k = 1; k <= n; k++)
				if ((a[k] - a[i]) * (a[k] - a[j]) == 0) cmt++;
			for (int k = 1; k <= n; k++)
				if ((a[k] - a[i]) * (a[k] - a[j]) == 0) mat[1][i][k] += 1.0 / cnt / cmt;
		}
	}
	for (p = 2; true; p++) {
		for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		for (int k = 1; k <= n; k++)
			mat[p][i][j] += mat[1][i][k] * mat[p - 1][k][j];
		if (cmp(p, p - 1)) break;
	}
	cerr << p << endl;
	int sum = 0;
	for (int i = 1; i <= tot; i++)
		sum += line[i].size();
	cerr << sum << endl;
	int q; read(q);
	while (q--) {
		int to, m; read(to), read(m);
		double ans = 0;
		for (int i = 1; i <= n; i++)
			chkmax(ans, calc(i, to, m));
		for (int i = 1; i <= tot; i++) {
			double now = 0;
			for (auto x : line[i])
				now += calc(x, to, m - 1);
			chkmax(ans, now / line[i].size());
		}
		printf("%.10lf\n", ans);
	}
	return 0;
}