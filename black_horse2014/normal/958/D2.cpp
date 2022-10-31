#include <bits/stdc++.h>
using namespace std;

struct fraction {
	long long u, d;
	fraction(long long u = 0, long long d = 1) : u(u), d(d) {}
	fraction operator - (fraction b) {
		fraction a = *this;
		fraction c;
		c.d = a.d * b.d;
		assert(c.d > 0);
		c.u = a.u * b.d - b.u * a.d;
		long long g = __gcd(c.d, abs(c.u));
		c.d /= g, c.u /= g;
		return c;
	}
	fraction operator * (fraction b) {
		fraction a = *this;
		fraction c;
		c.u = a.u * b.u;
		c.d = a.d * b.d;
		assert(c.d > 0);
		long long g = __gcd(c.d, abs(c.u));
		assert(g > 0);
		c.d /= g, c.u /= g;
		return c;
	}
	bool operator < (fraction b) {
		fraction c = *this - b;
		return c.u < 0;
	}
};

const int N = 33000;
fraction f[N][10], g[N][100];
int id[N], idx[N], val[N], vv[N];
int D;
int cmp(int i, int j) {
	for (int r = 1; r <= D * D; r++) {
		if (g[i][r] < g[j][r]) return true;
		if (g[j][r] < g[i][r]) return false;
	}
	return i < j;
}
bool same(int i, int j) {
	for (int r = 1; r <= D * D; r++) {
		if (g[i][r] < g[j][r]) return false;
		if (g[j][r] < g[i][r]) return false;
	}
	return true;
}
int main() {
	int m; scanf("%d%d", &m, &D);
	for (int t = 1; t <= m; t++) {
		int n; scanf("%d", &n);
		for (int i = 1; i <= n; i++) 
			for (int j = 1; j <= D; j++) scanf("%lld", &f[i][j].u), f[i][j].d = 1;
		int r = 0;
		for (int j = 1; j <= D; j++) {
			if (r == n) {
				break;
			}
			for (int i = r + 1; i <= n; i++) {
				if (f[i][j].u) {
					for (int k = 1; k <= D; k++) swap(f[i][k], f[r + 1][k]);
					break;
				}
			}
			if (f[r + 1][j].u == 0) continue;
			fraction R(f[r + 1][j].d, f[r + 1][j].u);
			if (f[r + 1][j].u < 0) R = fraction(-f[r + 1][j].d, -f[r + 1][j].u);
			for (int k = 1; k <= D; k++) f[r + 1][k] = f[r + 1][k] * R;
			for (int i = 1; i <= n; i++) {
				R = f[i][j];
				if (i == r + 1) continue;
				for (int k = 1; k <= D; k++) f[i][k] = f[i][k] - R * f[r + 1][k];
			}
			r++;
		}
		for (int i = 1; i <= r; i++) {
			for (int j = 1; j <= D; j++) g[t][(i - 1) * D + j] = f[i][j];
		}
		for (int i = r + 1; i <= D; i++)
			for (int j = 1; j <= D; j++) g[t][(i - 1) * D + j] = fraction(0, 1);
		id[t] = t;
	}
	sort (id + 1, id + m + 1, cmp);
	int c = 1;
	vv[c] = id[1];
	for (int t = 1; t <= m; t++) {
		val[id[t]] = c;
		if (t == m || !same(id[t], id[t + 1])) {
			c++;
			vv[c] = id[t + 1];
		}
	}
	for (int i = 1; i < c; i++) idx[i] = i; 
	sort (idx + 1, idx + c, [](int i, int j) {return vv[i] < vv[j];});
	for (int i = 1; i < c; i++) vv[idx[i]] = i;
	for (int t = 1; t <= m; t++) printf("%d%c", vv[val[t]], " \n"[t == m]);
	return 0;
}