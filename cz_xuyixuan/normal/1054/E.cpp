#include<bits/stdc++.h>
using namespace std;
const int MAXN = 305;
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
int n, m;
string a[MAXN][MAXN], b[MAXN][MAXN];
vector <pair <int, int> > from, to;
void moveto(int sx, int sy, int tx, int ty) {
	if (sx == tx && sy == ty) return;
	if (sx != tx) {
		from.emplace_back(sx, sy);
		to.emplace_back(tx, sy);
		moveto(tx, sy, tx, ty);
	} else {
		from.emplace_back(sx, sy);
		to.emplace_back(sx, ty);
		moveto(sx, ty, tx, ty);
	}
}
bool valid(int x, int y) {
	if (x == 1 && y == m) return true;
	if (x == n && y == 1) return true;
	return false;
}
void Moveto(int sx, int sy, int tx, int ty) {
	if (sx == tx && sy == ty) return;
	if (sx != tx && valid(tx, sy)) {
		from.emplace_back(sx, sy);
		to.emplace_back(tx, sy);
		Moveto(tx, sy, tx, ty);
	} else if (sy != ty && valid(sx, ty)) {
		from.emplace_back(sx, sy);
		to.emplace_back(sx, ty);
		Moveto(sx, ty, tx, ty);
	} else moveto(sx, sy, tx, ty);
}
int main() {
	read(n), read(m);
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= m; j++) {
		cin >> a[i][j];
		reverse(a[i][j].begin(), a[i][j].end());
	}
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= m; j++) {
		cin >> b[i][j];
		reverse(b[i][j].begin(), b[i][j].end());
	}
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= m; j++) {
		if (i == 1 && j == m) continue;
		if (i == n && j == 1) continue;
		if (i == 1 || j == m) {
			a[1][m] += a[i][j];
			for (auto x : a[i][j]) moveto(i, j, 1, m);
			a[i][j].clear();
		} else if (i == n || j == 1) {
			a[n][1] += a[i][j];
			for (auto x : a[i][j]) moveto(i, j, n, 1);
			a[i][j].clear();
		}
	}
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= m; j++) {
		for (auto x : a[i][j])
			if (x == '0') moveto(i, j, 1, 1);
			else moveto(i, j, n, m);
	}
	for (int i = 2; i <= n - 1; i++)
	for (int j = 2; j <= m - 1; j++) {
		for (auto x : b[i][j])
			if (x == '0') moveto(1, 1, i, j);
			else moveto(n, m, i, j);
		b[i][j].clear();
	}
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= m; j++) {
		if (i == 1 && j == 1) continue;
		if (i == n && j == 1) continue;
		if (i == 1 && j == m) continue;
		if (i == n && j == m) continue;
		for (auto x : b[i][j])
			if (x == '0') Moveto(1, 1, i, j);
			else Moveto(n, m, i, j);
		b[i][j].clear();
	}
	for (auto x : b[1][1])
		if (x == '0') moveto(1, 1, 1, m), moveto(1, m, 1, 1);
		else moveto(n, m, 1, 1);
	for (auto x : b[n][m])
		if (x == '0') moveto(1, 1, n, m);
		else moveto(n, m, 1, m), moveto(1, m, n, m);
	for (auto x : b[1][m])
		if (x == '0') moveto(1, 1, 1, m);
		else moveto(n, m, 1, m);
	for (auto x : b[n][1])
		if (x == '0') moveto(1, 1, n, 1);
		else moveto(n, m, n, 1);
	writeln(from.size());
	for (unsigned i = 0; i < from.size(); i++)
		printf("%d %d %d %d\n", from[i].first, from[i].second, to[i].first, to[i].second);
	return 0;
}