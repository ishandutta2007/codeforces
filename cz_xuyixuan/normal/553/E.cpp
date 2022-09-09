#include<bits/stdc++.h>
using namespace std;
const int MAXN = 55;
const int MAXM = 32768;
const double INF = 1e18;
const double pi = acos(-1);
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
struct point {double x, y; };
point operator + (point a, point b) {return (point) {a.x + b.x, a.y + b.y}; }
point operator - (point a, point b) {return (point) {a.x - b.x, a.y - b.y}; }
point operator * (point a, point b) {return (point) {a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x}; }
point operator / (point a, double x) {return (point) {a.x / x, a.y / x}; }
int n, m, t, fine;
vector <pair <int, int> > e;
double dist[MAXN][MAXN], edge[MAXN][MAXN];
vector <double> dp[MAXN], trans[MAXN][MAXN], p[MAXN][MAXN];
int N, Log, home[MAXM]; point a[MAXM], b[MAXM], c[MAXM];
void FFT(point *a, int mode) {
	for (int i = 0; i < N; i++)
		if (home[i] > i) swap(a[i], a[home[i]]);
	for (int len = 2; len <= N; len <<= 1) {
		point delta = (point) {cos(2 * pi / len * mode), sin(2 * pi / len * mode)};
		for (int i = 0; i < N; i += len) {
			point now = (point) {1, 0};
			for (int j = i, k = i + len / 2; k < i + len; j++, k++) {
				point tmp = a[j], tnp = a[k];
				a[j] = tmp + tnp * now;
				a[k] = tmp - tnp * now;
				now = now * delta;
			}
		}
	}
	if (mode == -1) {
		for (int i = 0; i < N; i++)
			a[i] = a[i] / N;
	}
}
void transfer(int l, int mid, int r, vector <double> &dp, vector <double> &p, vector <double> &res) {
	N = 1, Log = 0;
	while (N <= (r - l) + (r - mid)) {
		N <<= 1;
		Log++;
	}
	for (int i = 0; i < N; i++) {
		int tmp = i, res = 0;
		for (int j = 1; j <= Log; j++) {
			res <<= 1;
			res += tmp & 1;
			tmp >>= 1;
		}
		home[i] = res;
	}
	for (int i = 0; i < N; i++)
		a[i] = b[i] = (point) {0, 0};
	for (int i = mid + 1; i <= r; i++)
		a[r - i].x = dp[i];
	for (int i = 0; i <= r - l; i++)
		b[i].x = p[i];
	FFT(a, 1), FFT(b, 1);
	for (int i = 0; i < N; i++)
		c[i] = a[i] * b[i];
	FFT(c, -1);
	for (int i = l; i <= mid; i++)
		res[i] += c[r - i].x;
}
void work(int l, int r) {
	if (l == r) {
		for (int i = 1; i <= n - 1; i++)
			dp[i][l] = INF;
		for (auto x : e) {
			int i = x.first, j = x.second;
			chkmin(dp[i][l], trans[i][j][l] + edge[i][j]);
		}
		return;
	}
	int mid = (l + r) / 2;
	work(mid + 1, r);
	for (auto x : e) {
		int i = x.first, j = x.second;
		transfer(l, mid, r, dp[j], p[i][j], trans[i][j]);
	}
	work(l, mid);
}
int main() {
	read(n), read(m), read(t), read(fine);
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= n; j++)
		if (i == j) dist[i][j] = 0;
		else dist[i][j] = INF;
	for (int i = 1; i <= n; i++)
		dp[i].resize(t + 1);
	for (int i = 1; i <= m; i++) {
		int x, y, z;
		read(x), read(y), read(z);
		e.emplace_back(x, y);
		dist[x][y] = z;
		edge[x][y] = z;
		p[x][y].push_back(0);
		trans[x][y].resize(t + 1);
		for (int j = 1; j <= t; j++) {
			int val; read(val);
			p[x][y].push_back(val * 0.00001);
		}
	}
	for (int k = 1; k <= n; k++)
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= n; j++)
		chkmin(dist[i][j], dist[i][k] + dist[k][j]);
	for (auto x : e) {
		int i = x.first, j = x.second;
		double res = 1;
		for (int k = t; k >= 0; k--) {
			res -= p[i][j][t - k];
			trans[i][j][k] = res * (dist[j][n] + fine);
		}
	}
	work(0, t);
	printf("%.10lf\n", dp[1][0]);
	return 0;
}