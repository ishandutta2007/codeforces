#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
const int MAXLOG = 20;
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
int n, l[MAXLOG][MAXN], r[MAXLOG][MAXN], u[MAXLOG][MAXN], d[MAXLOG][MAXN], col[MAXN];
pair <int, int> a[MAXN], b[MAXN];
bool cmpl(int x, int y) {
	return a[x].first < a[y].first;
}
bool cmpr(int x, int y) {
	return a[x].second > a[y].second;
}
bool cmpd(int x, int y) {
	return b[x].first < b[y].first;
}
bool cmpu(int x, int y) {
	return b[x].second > b[y].second;
}
bool solve(vector <int> p, int c, int depth) {
	for (auto x : p) col[x] = c;
	if (p.size() == 1) return true;
	sort(p.begin(), p.end(), cmpl), l[depth][p.back()] = 0, l[depth][c] = p[0];
	for (unsigned i = 1; i < p.size(); i++) l[depth][p[i - 1]] = p[i];
	sort(p.begin(), p.end(), cmpr), r[depth][p.back()] = 0, r[depth][c] = p[0];
	for (unsigned i = 1; i < p.size(); i++) r[depth][p[i - 1]] = p[i];
	sort(p.begin(), p.end(), cmpd), d[depth][p.back()] = 0, d[depth][c] = p[0];
	for (unsigned i = 1; i < p.size(); i++) d[depth][p[i - 1]] = p[i];
	sort(p.begin(), p.end(), cmpu), u[depth][p.back()] = 0, u[depth][c] = p[0];
	for (unsigned i = 1; i < p.size(); i++) u[depth][p[i - 1]] = p[i];
	auto nxt = [&] (int x, int *a) {
		while (a[x] != 0 && col[a[x]] != c) a[x] = a[a[x]];
		return a[x];
	};
	while (nxt(nxt(c, l[depth]), l[depth]) != 0) {
		int pl = c, pr = c, pd = c, pu = c;
		int vl = a[nxt(pl, l[depth])].second;
		int vr = a[nxt(pr, r[depth])].first;
		int vd = b[nxt(pd, d[depth])].second;
		int vu = b[nxt(pu, u[depth])].first;
		while (true) {
			pl = nxt(pl, l[depth]);
			if (pl == 0) return false;
			if (vl <= a[pl].first) {
				vector <int> q; int x = c;
				if (pl == 19)
					cerr << pl << endl;
				while (nxt(x, l[depth]) != pl) {
					x = nxt(x, l[depth]);
					q.push_back(x);
				}
				if (!solve(q, c + 1, depth + 1)) return false;
				break;
			} else chkmax(vl, a[pl].second);
			
			pr = nxt(pr, r[depth]);
			if (pr == 0) return false;
			if (vr >= a[pr].second) {
				vector <int> q; int x = c;
				while (nxt(x, r[depth]) != pr) {
					x = nxt(x, r[depth]);
					q.push_back(x);
				}
				if (!solve(q, c + 1, depth + 1)) return false;
				break;
			} else chkmin(vr, a[pr].first);
			
			pd = nxt(pd, d[depth]);
			if (pd == 0) return false;
			if (vd <= b[pd].first) {
				vector <int> q; int x = c;
				while (nxt(x, d[depth]) != pd) {
					x = nxt(x, d[depth]);
					q.push_back(x);
				}
				if (!solve(q, c + 1, depth + 1)) return false;
				break;
			} else chkmax(vd, b[pd].second);
			
			pu = nxt(pu, u[depth]);
			if (pu == 0) return false;
			if (vu >= b[pu].second) {
				vector <int> q; int x = c;
				while (nxt(x, u[depth]) != pu) {
					x = nxt(x, u[depth]);
					q.push_back(x);
				}
				if (!solve(q, c + 1, depth + 1)) return false;
				break;
			} else chkmin(vu, b[pu].first);
		}
	}
	return true;
}
int main() {
	read(n); vector <int> x;
	for (int i = 1; i <= n; i++) {
		x.push_back(i);
		read(a[i].first), read(b[i].first);
		read(a[i].second), read(b[i].second);
	}
	if (solve(x, n + 1, 0)) puts("YES");
	else puts("NO");
	return 0;
}