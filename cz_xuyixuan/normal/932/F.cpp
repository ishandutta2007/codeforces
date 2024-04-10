#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
const long double INF = 1e99;
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
struct point {long long x, y; };
point operator + (point a, point b) {return (point) {a.x + b.x, a.y + b.y}; }
point operator - (point a, point b) {return (point) {a.x - b.x, a.y - b.y}; }
long long operator * (point a, point b) {return a.x * b.y - a.y * b.x; }
bool operator < (point a, point b) {
	if (a.x == b.x) return a.y < b.y;
	else return a.x < b.x;
}
struct line {point pos; mutable long double k; };
bool mode = false;
bool operator < (line a, line b) {
	if (mode) return a.k < b.k;
	else return a.pos < b.pos;
}
struct Tree : multiset<line> {
	void init() {clear(); }
	long double div(long double a, long double b) {return a / b; }
	bool update(iterator x, iterator y) { //Update *x.k && check and return if y needs to be erased.
		if (y == end()) {(*x).k = INF; return false;}
		if ((*x).pos.x == (*y).pos.x) {erase(y); return true; };
		(*x).k = div((*y).pos.y - (*x).pos.y, (*y).pos.x - (*x).pos.x);
		if ((*x).k >= (*y).k) {erase(y); return true; }
		else return false;
	}
	void ins(point x) {
		iterator p = insert((line) {x, 0}), q, r;
		for (q = p, q++; update(p, q); q = p, q++);
		if (p == begin()) return;
		q = p, q--; if (update(q, p)) {p = q, p++, update(q, p); return; };
		for (q = p, q--, r = q; q != begin() && update(--r, q) && p != begin(); q = p, q--, r = q) update(r, p);
	}
	long long query(long long x) {
		mode = true;
		iterator tmp = lower_bound((line) {(point) {0, 0}, (long double) (-x)});
		mode = false;
		return (*tmp).pos.y + x * (*tmp).pos.x;
	}
};
vector <int> e[MAXN];
long long a[MAXN], b[MAXN], f[MAXN];
int size[MAXN], son[MAXN];
void dfs(int pos, int fa) {
	size[pos] = 1;
	for (unsigned i = 0; i < e[pos].size(); i++)
		if (e[pos][i] != fa) {
			dfs(e[pos][i], pos);
			size[pos] += size[e[pos][i]];
			if (size[e[pos][i]] > size[son[pos]]) son[pos] = e[pos][i];
		}
}
void work(int pos, int fa, Tree &t) {
	if (fa != 0 && e[pos].size() == 1) {
		f[pos] = 0;
		t.ins((point) {b[pos], f[pos]});
		return;
	}
	work(son[pos], pos, t);
	for (unsigned i = 0; i < e[pos].size(); i++) {
		if (e[pos][i] == fa || e[pos][i] == son[pos]) continue;
		Tree tmp; tmp.init();
		work(e[pos][i], pos, tmp);
		for (Tree :: iterator j = tmp.begin(); j != tmp.end(); j++)
			t.ins((*j).pos);
	}
	f[pos] = t.query(a[pos]);
	t.ins((point) {b[pos], f[pos]});
}
int main() {
	int n; read(n);
	for (int i = 1; i <= n; i++)
		read(a[i]);
	for (int i = 1; i <= n; i++)
		read(b[i]);
	for (int i = 1; i <= n - 1; i++) {
		int x, y; read(x), read(y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	dfs(1, 0);
	Tree tmp; tmp.init();
	work(1, 0, tmp);
	for (int i = 1; i <= n; i++)
		printf("%I64d ", f[i]);
	return 0;
}