#include<bits/stdc++.h>
using namespace std;
const int MAXN = 505;
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
namespace MaximumMatching {
	const int MAXN = 505;
	vector <int> a[MAXN];
	int n, f[MAXN], match[MAXN];
	int type[MAXN], father[MAXN];
	int find(int x) {
		if (f[x] == x) return x;
		else return f[x] = find(f[x]);
	}
	int lca(int x, int y) {
		static int timer, col[MAXN]; timer++;
		while (x != 0) {
			x = find(x);
			col[x] = timer;
			x = father[find(match[x])];
		}
		while (y != 0) {
			y = find(y);
			if (col[y] == timer) return y;
			y = father[find(match[y])];
		}
		assert(false);
		return -1;
	}
	void shrink(int x, int y, int lca, int *q, int &r) {
		while (find(x) != lca) {
			father[x] = y;
			y = match[x];
			if (type[y] == 1) {
				type[y] = 2;
				q[++r] = y;
			}
			if (find(x) == x) f[x] = lca;
			if (find(y) == y) f[y] = lca;
			x = father[y];
		}
	}
	bool augment(int s) {
		for (int i = 1; i <= n; i++) {
			f[i] = i;
			type[i] = 0;
			father[i] = 0;
		}
		static int q[MAXN];
		int l = 0, r = 0;
		q[0] = s, type[s] = 2;
		while (l <= r) {
			int pos = q[l++];
			for (auto x : a[pos]) {
				if (find(x) == find(pos)) continue;
				if (type[x] == 0) {
					type[x] = 1, father[x] = pos;
					if (!match[x]) {
						while (x != 0) {
							int y = father[x], z = match[y];
							match[x] = y, match[y] = x;
							x = z;
						}
						return true;
					}
					type[match[x]] = 2;
					q[++r] = match[x];
				}
				if (type[x] == 2) {
					int y = lca(x, pos);
					shrink(x, pos, y, q, r);
					shrink(pos, x, y, q, r);
				}
			}
		}
		return false;
	}
	void init(int x) {
		n = x;
		for (int i = 1; i <= n; i++) {
			a[i].clear();
			match[i] = 0;
		}
	}
	void addedge(int x, int y) {
		a[x].push_back(y);
		a[y].push_back(x);
	}
	int work() {
		int ans = 0;
		for (int i = 1; i <= n; i++)
			if (!match[i] && augment(i)) {
				ans++;
			}
		return ans;
	}
}
char s[MAXN];
int main() {
	int T; read(T);
	while (T--) {
		int n, m; read(n), read(m);
		MaximumMatching :: init(2 * n + m);
		for (int i = 1, now = m; i <= n; i++, now += 2) {
			int x = now + 1, y = now + 2;
			MaximumMatching :: addedge(x, y);
			scanf("\n%s", s + 1);
			for (int j = 1; j <= m; j++) {
				if (s[j] == '1') {
					MaximumMatching :: addedge(x, j);
					MaximumMatching :: addedge(y, j);
				}
			}
		}
		writeln(MaximumMatching :: work() - n);
	}
	return 0;
}