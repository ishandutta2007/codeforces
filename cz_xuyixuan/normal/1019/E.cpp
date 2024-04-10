#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
const int MAXM = 1e6 + 5;
const long double one = 1.0;
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
struct point {long long x, y; };
struct edge {int dest; point val; };
point operator + (point a, point b) {return (point) {a.x + b.x, a.y + b.y}; }
point operator - (point a, point b) {return (point) {a.x - b.x, a.y - b.y}; }
point operator * (point a, long long b) {return (point) {a.x * b, a.y * b}; }
long double operator * (point a, point b) {return one * a.x * b.y - one * a.y * b.x; }
vector <edge> a[MAXN], b[MAXN];
vector <point> ans, tmpa, tmpb, res;
int n, m, tot, rootx, rooty, cntcol, weight[MAXN], size[MAXN], col[MAXN];
void rebuild(int pos, int fa) {
	for (unsigned i = 0; i < b[pos].size(); i++)
		if (b[pos][i].dest == fa) {
			b[pos].erase(b[pos].begin() + i);
			break;
		}
	for (unsigned i = 0; i < b[pos].size(); i++)
		rebuild(b[pos][i].dest, pos);
	while (b[pos].size() > 2) {
		tot++; unsigned sz = b[pos].size();
		a[tot].push_back(b[pos][sz - 1]);
		a[b[pos][sz - 1].dest].push_back((edge) {tot, b[pos][sz - 1].val});
		a[tot].push_back(b[pos][sz - 2]);
		a[b[pos][sz - 2].dest].push_back((edge) {tot, b[pos][sz - 2].val});
		b[pos].resize(sz - 2);
		b[pos].push_back((edge) {tot, (point) {0, 0}});
	}
	for (unsigned i = 0; i < b[pos].size(); i++) {
		a[pos].push_back(b[pos][i]);
		a[b[pos][i].dest].push_back((edge) {pos, b[pos][i].val});
	}
}
void calsize(int pos, int fa, int curr) {
	size[pos] = 1;
	col[pos] = cntcol;
	for (unsigned i = 0; i < a[pos].size(); i++)
		if (a[pos][i].dest != fa && col[a[pos][i].dest] == curr) {
			calsize(a[pos][i].dest, pos, curr);
			size[pos] += size[a[pos][i].dest];
		}
}
void getroot(int pos, int fa, int curr, int tot) {
	size[pos] = 1;
	for (unsigned i = 0; i < a[pos].size(); i++)
		if (a[pos][i].dest != fa && col[a[pos][i].dest] == curr) {
			getroot(a[pos][i].dest, pos, curr, tot);
			size[pos] += size[a[pos][i].dest];
		}
	weight[pos] = max(size[pos], tot - size[pos]);
	if (weight[pos] < weight[rootx]) rootx = pos, rooty = fa;
}
bool cmp(point a, point b) {
	if (a.x == b.x) return a.y > b.y;
	else return a.x < b.x;
}
void convexhull(vector <point> &a) {
	sort(a.begin(), a.end(), cmp);
	int top = 1;
	for (unsigned i = 1; i < a.size(); i++) {
		if (a[i].x == a[top - 1].x) continue;
		while (top >= 2 && (a[top - 1] - a[top - 2]) * (a[i] - a[top - 2]) >= 0) top--;
		a[top++] = a[i];
	}
	a.resize(top);
}
void calcsum(vector <point> &a, vector <point> &b, vector <point> &res) {
	int posa = 1, posb = 1;
	res.clear(), res.push_back(a[0] + b[0]);
	while (posa < a.size() || posb < b.size()) {
		if (posa == a.size()) res.push_back(res[res.size() - 1] + b[posb] - b[posb - 1]), posb++;
		else if (posb == b.size()) res.push_back(res[res.size() - 1] + a[posa] - a[posa - 1]), posa++;
		else if ((a[posa] - a[posa - 1]) * (b[posb] - b[posb - 1]) >= 0) res.push_back(res[res.size() - 1] + b[posb] - b[posb - 1]), posb++;
		else res.push_back(res[res.size() - 1] + a[posa] - a[posa - 1]), posa++;
	}
}
void dfs(int pos, int fa, int curr, point sum, vector <point> &tmp) {
	tmp.push_back(sum);
	for (unsigned i = 0; i < a[pos].size(); i++)
		if (a[pos][i].dest != fa && col[a[pos][i].dest] == curr)
			dfs(a[pos][i].dest, pos, curr, sum + a[pos][i].val, tmp);
}
void work(int pos, int tot, int curr) {
	if (tot == 1) return;
	weight[rootx = 0] = tot + 1;
	getroot(pos, 0, curr, tot);
	cntcol++; calsize(rootx, rooty, col[rootx]);
	cntcol++; calsize(rooty, rootx, col[rooty]);
	tmpa.clear(), dfs(rootx, 0, col[rootx], (point) {0, 0}, tmpa), convexhull(tmpa);
	tmpb.clear(), dfs(rootx, 0, col[rooty], (point) {0, 0}, tmpb), convexhull(tmpb);
	calcsum(tmpa, tmpb, res);
	for (unsigned i = 0; i < res.size(); i++)
		ans.push_back(res[i]);
	int tmpx = rootx, tmpy = rooty;
	work(tmpx, size[tmpx], col[tmpx]);
	work(tmpy, size[tmpy], col[tmpy]);
}
int main() {
	read(n), read(m);
	for (int i = 1; i <= n - 1; i++) {
		int x, y, k, a;
		read(x), read(y), read(k), read(a);
		b[x].push_back((edge) {y, (point) {k, a}});
		b[y].push_back((edge) {x, (point) {k, a}});
	}
	tot = n; rebuild(1, 0);
	work(1, tot, 0);
	convexhull(ans);
	int pos = 0;
	for (int i = 0; i <= m - 1; i++) {
		long long now = ans[pos].x * i + ans[pos].y, nxt;
		if (pos < ans.size() - 1) {
			nxt = ans[pos + 1].x * i + ans[pos + 1].y;
			while (pos < ans.size() - 1 && nxt >= now) {
				pos++; now = nxt;
				if (pos < ans.size() - 1) nxt = ans[pos + 1].x * i + ans[pos + 1].y;
			}
		}
		printf("%lld ", now);
	}
	return 0;
}