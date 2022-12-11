#include <bits/stdc++.h>

const int mod = 1e9 + 7;
typedef unsigned long long LL;

struct _ {
	int A[20][20];
	friend _ operator * (_ a, _ b) {
		_ r;
		for (int i = 0; i != 20; ++i)
			for (int j = 0; j != 20; ++j) {
				LL t = 0;
				for (int k = 0; k != 10; ++k)
					t += (LL) a.A[i][k] * b.A[k][j];
				t %= mod;
				for (int k = 10; k != 20; ++k)
					t += (LL) a.A[i][k] * b.A[k][j];
				r.A[i][j] = t % mod;
			}
		return r;
	}
} ;
int mat[20][20];
int can[20];
int n, m;
void pow(_ a, int b, _ & r) {
	for (; b; b >>= 1, a = a * a)
		if (b & 1) r = a * r;
}
_ get() {
	_ r; memset(&r, 0, sizeof r);
	for (int i = 0; i != n; ++i)
		for (int j = 0; j != m; ++j) {
			const int u = mat[i][j];
			if (!can[u]) continue;
			r.A[u][u] = 1;
			static const int dx[4] = {1, -1, 0, 0};
			static const int dy[4] = {0, 0, 1, -1};
			for (int k = 0; k != 4; ++k) {
				int x = i + dx[k], y = j + dy[k];
				if (x < 0 || y < 0 || x >= n || y >= m)
					continue;
				if (!can[mat[x][y]]) continue;
				r.A[u][mat[x][y]] = 1;
			}
		}
	return r;
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	int Q; 
	std::cin >> n >> m >> Q;
	for (int i = 0, t = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			can[mat[i][j] = t++] = true;
	int lst = 1;
	_ v; memset(&v, 0, sizeof v);
	v.A[mat[0][0]][0] = 1;
	while (Q --> 0) {
		int opt, x, y, tim;
		std::cin >> opt >> x >> y >> tim;
		--x, --y;
		pow(get(), tim - lst, v);
		lst = tim;
		if (opt == 1) {
			std::cout << v.A[mat[x][y]][0] << '\n';
		} else if (opt == 2) {
			can[mat[x][y]] = false;
		} else {
			can[mat[x][y]] = true;
		}
	}
	return 0;
}