#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
const int MAXM = 4e5 + 5;
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
int n, m, q, res[MAXN];
int tot, point[MAXN][2];
int x[MAXN], y[MAXN];
int f[MAXM], s[MAXM];
int find(int x) {
	if (f[x] == x) return x;
	else return find(f[x]);
}
void work(int xl, int xr, int yl, int yr) {
	if (xl > xr) return;
	vector <pair <int, pair <int, int>>> rev;
	auto merge = [&] (int x, int y) {
		x = find(x), y = find(y);
		if (x == y) return;
		if (s[x] < s[y]) swap(x, y);
		rev.emplace_back(x, make_pair(f[x], s[x]));
		rev.emplace_back(y, make_pair(f[y], s[y]));
		s[x] += s[y], f[y] = x;
		return;
	};
	auto addedge = [&] (int x, int y) {
		merge(point[x][0], point[y][1]);
		merge(point[x][1], point[y][0]);
		return;
	};
	auto check = [&] (int x, int y) {
		return find(point[x][0]) != find(point[y][0]);
	};
	auto clear = [&] () {
		reverse(rev.begin(), rev.end());
		for (auto x : rev) {
			f[x.first] = x.second.first;
			s[x.first] = x.second.second;
		}
		rev.clear();
		return;
	};
	if (yl == yr) {
		for (int i = xl; i <= xr; i++)
			res[i] = yl;
		return;
	}
	bool fail = false;
	int mid = (yl + yr + 1) / 2, divp = 0;
	for (int i = max(yl, 1); i < mid && !fail; i++) {
		fail |= !check(x[m - i + 1], y[m - i + 1]);
		if (!fail) addedge(x[m - i + 1], y[m - i + 1]);
	}
	if (fail) {
		clear();
		work(xl, xr, yl, mid - 1);
		return;
	}
	divp = xl;
	for (int i = xl; i <= xr - 1; i++) {
		if (check(x[i], y[i])) {
			divp++;
			addedge(x[i], y[i]);
		} else break;
	}
	clear();
	for (int i = max(yl, 1); i < mid; i++)
		addedge(x[m - i + 1], y[m - i + 1]);
	work(xl, divp, mid, yr);
	clear(); fail = false;
	for (int i = xl; i <= divp; i++) {
		if (!check(x[i], y[i])) {
			fail = true;
			break;
		}
		addedge(x[i], y[i]);
	}
	if (!fail) work(divp + 1, xr, yl, mid - 1);
	clear();
}
int main() {
	read(n), read(m), read(q);
	for (int i = 1; i <= m; i++)
		read(x[i]), read(y[i]);
	for (int i = 1; i <= n; i++) {
		point[i][0] = ++tot;
		f[tot] = tot, s[tot] = 1;
		point[i][1] = ++tot;
		f[tot] = tot, s[tot] = 1;
	}
	work(1, m, 0, m);
	for (int i = 1; i <= q; i++) {
		int l, r; read(l), read(r);
		if (res[l] >= m - r + 1) puts("NO");
		else puts("YES");
	}
	return 0;
}