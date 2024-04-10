#include<bits/stdc++.h>
using namespace std;
const int MAXN = 55;
const int MAXM = 805;
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
int n, m, f[MAXM]; char s[MAXN][MAXN];
int cntp, point[MAXN][MAXN], limd[MAXM];
int cnte; pair <int, int> a[MAXM]; bool res[MAXM];
int find(int x) {
	if (f[x] == x) return x;
	else return f[x] = find(f[x]);
}
namespace MatroidIntersection {
	const int INF = 1e9 + 7;
	void work() {
		for (int i = 1; i <= cnte; i++)
			res[i] = false;
		while (true) {
			static int d[MAXM];
			for (int i = 1; i <= cntp; i++)
				d[i] = 0, f[i] = i;
			for (int i = 1; i <= cnte; i++)
				if (res[i]) {
					int x = a[i].first;
					int y = a[i].second;
					d[x]++, d[y]++;
					f[find(x)] = find(y);
				}
			static bool s[MAXM], t[MAXM];
			for (int i = 1; i <= cnte; i++)
				s[i] = t[i] = false;
			bool found = false;
			for (int i = 1; i <= cnte; i++)
				if (!res[i]) {
					int x = a[i].first;
					int y = a[i].second;
					if (d[x] + 1 <= limd[x] && d[y] + 1 <= limd[y]) s[i] = true;
					if (find(x) != find(y)) t[i] = true;
					if (s[i] && t[i]) {
						found = true;
						res[i] = true;
						break;
					}
				}
			if (found) continue;
			static bool e[MAXM][MAXM];
			for (int i = 1; i <= cnte; i++)
			for (int j = 1; j <= cnte; j++)
				e[i][j] = false;
			for (int i = 1; i <= cnte; i++)
				if (res[i]) {
					for (int j = 1; j <= cntp; j++)
						d[j] = 0, f[j] = j;
					for (int j = 1; j <= cnte; j++)
						if (res[j] && i != j) {
							int x = a[j].first;
							int y = a[j].second;
							d[x]++, d[y]++;
							f[find(x)] = find(y);
						}
					for (int j = 1; j <= cnte; j++)
						if (!res[j]) {
							int x = a[j].first;
							int y = a[j].second;
							if (d[x] + 1 <= limd[x] && d[y] + 1 <= limd[y]) e[i][j] = true;
							if (find(x) != find(y)) e[j][i] = true;
						}
				}
			int l = 0, r = -1;
			static int dist[MAXM], home[MAXM], q[MAXM];
			for (int i = 1; i <= cnte; i++) {
				home[i] = 0;
				if (s[i]) dist[i] = 0, q[++r] = i;
				else dist[i] = INF;
			}
			while (l <= r) {
				int tmp = q[l++];
				for (int i = 1; i <= cnte; i++)
					if (e[tmp][i] && dist[i] == INF) {
						dist[i] = dist[tmp] + 1;
						home[i] = tmp;
						q[++r] = i;
					}
			}
			int Min = INF, pos = 0;
			for (int i = 1; i <= cnte; i++)
				if (t[i] && dist[i] < Min) Min = dist[i], pos = i;
			if (pos == 0) break;
			while (pos != 0) {
				res[pos] ^= true;
				pos = home[pos];
			}
		}
	}
}
int main() {
	int T; read(T);
	while (T--) {
		read(n), read(m);
		for (int i = 1; i <= n; i++)
			scanf("\n%s", s[i] + 1);
		cntp = 0, cnte = 0;
		int goal = 0;
		for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			if (s[i][j] == 'O') {
				point[i][j] = ++cntp;
				if ((i + j) % 2 == 0 && i + j >= 4) limd[point[i][j]] = 2, goal++;
				else limd[point[i][j]] = 4;
				if (i + j >= 4 && s[i - 1][j] == 'O') a[++cnte] = make_pair(point[i][j], point[i - 1][j]);
				if (i + j >= 4 && s[i][j - 1] == 'O') a[++cnte] = make_pair(point[i][j], point[i][j - 1]);
			} else point[i][j] = -1;
		}
		MatroidIntersection :: work();
		int cnt = 0;
		for (int i = 1; i <= cnte; i++)
			cnt += res[i];
		if (cnt != 2 * goal) {
			puts("NO");
			continue;
		}
		puts("YES");
		for (int i = 1; i <= cntp; i++)
			f[i] = i;
		for (int i = 1; i <= cnte; i++)
			if (res[i]) {
				int x = a[i].first;
				int y = a[i].second;
				f[find(x)] = find(y);
			}
		if (s[1][2] == 'O') a[++cnte] = make_pair(point[1][2], point[1][1]), res[cnte] = false;
		if (s[2][1] == 'O') a[++cnte] = make_pair(point[2][1], point[1][1]), res[cnte] = false;
		for (int i = 1; i <= cnte; i++)
			if (!res[i]) {
				int x = a[i].first;
				int y = a[i].second;
				if (find(x) != find(y)) {
					f[find(x)] = find(y);
					res[i] = true;
				}
			}
		static char ans[MAXN][MAXN];
		for (int i = 1; i <= n * 2 - 1; i++) {
			for (int j = 1; j <= m * 2 - 1; j++)
				ans[i][j] = ' ';
			ans[i][m * 2] = 0;
		}
		for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			ans[i * 2 - 1][j * 2 - 1] = s[i][j];
		for (int i = 1; i <= n; i++)
		for (int j = 2; j <= m; j++) {
			pair <int, int> e = make_pair(point[i][j], point[i][j - 1]);
			bool used = false;
			for (int k = 1; k <= cnte; k++)
				if (a[k] == e) used = res[k];
			if (used) ans[i * 2 - 1][j * 2 - 2] = 'O';
		}
		for (int i = 2; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			pair <int, int> e = make_pair(point[i][j], point[i - 1][j]);
			bool used = false;
			for (int k = 1; k <= cnte; k++)
				if (a[k] == e) used = res[k];
			if (used) ans[i * 2 - 2][j * 2 - 1] = 'O';
		}
		for (int i = 1; i <= 2 * n - 1; i++)
			puts(ans[i] + 1);
	}
	return 0;
}