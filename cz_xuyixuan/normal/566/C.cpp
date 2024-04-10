#include<bits/stdc++.h>
using namespace std;
const int MAXN = 4e5 + 5;
const double eps = 1e-11;
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
int n, tot, w[MAXN], size[MAXN], dist[MAXN];
int belong[MAXN], x[MAXN], y[MAXN], l[MAXN];
vector <pair <int, int>> a[MAXN], b[MAXN];
bool side[MAXN], val[MAXN];
void dfs(int pos, int fa, bool col) {
	size[pos] = val[pos];
	side[pos] = col;
	for (auto x : a[pos])
		if (x.first != fa) {
			dist[x.first] = dist[pos] + x.second;
			dfs(x.first, pos, col);
			size[pos] += size[x.first];
		}
}
bool judge(int x, int y) {
	dist[x] = 0, dfs(x, 0, true);
	double costx = 0, costy = 0;
	for (int i = 1; i <= tot; i++)
		costx += w[i] * sqrt(dist[i]) * dist[i];
	dist[y] = 0, dfs(y, 0, false);
	for (int i = 1; i <= tot; i++)
		costy += w[i] * sqrt(dist[i]) * dist[i];
	if (fabs(costx - costy) / fabs(costx) >= eps) {
		if (costx > costy) return false;
		else return true;
	}
	dist[x] = 0, dfs(x, y, true);
	dist[y] = 0, dfs(y, x, false);
	double derx = 0, dery = 0;
	for (int i = 1; i <= tot; i++)
		if (side[i]) dery += w[i] * sqrt(dist[i]);
		else derx += w[i] * sqrt(dist[i]);
	return derx < dery;
}
void col(int pos, int fa) {
	val[pos] = false;
	for (auto x : a[pos])
		if (x.first != fa) col(x.first, pos);
}
int findans(int cnt) {
	while (cnt != 1) {
		pair <int, int> e; int div = cnt;
		dfs(1, 0, true);
		for (int i = 1; i <= tot; i++)
		for (auto x : a[i]) {
			int tmp = min(size[i], size[x.first]);
			chkmax(tmp, cnt - tmp);
			if (tmp < div) {
				div = tmp;
				e = make_pair(i, x.first);
			}
		}
		if (judge(e.first, e.second)) col(e.second, e.first);
		else col(e.first, e.second);
		cnt = 0;
		for (int i = 1; i <= tot; i++)
			cnt += val[i];
	}
	for (int i = 1; i <= tot; i++)
		if (val[i]) return i;
	assert(false);
	return -1;
}
void addedge(int x, int y, int z) {
	a[x].emplace_back(y, z);
	a[y].emplace_back(x, z);
}
void rebuild(int pos, int fa) {
	int last = 0, len = 0;
	for (auto x : b[pos]) 
		if (x.first != fa) {
			rebuild(x.first, pos);
			if (last == 0) last = x.first, len = x.second;
			else {
				addedge(++tot, last, len);
				addedge(tot, x.first, x.second);
				belong[tot] = pos;
				last = tot, len = 0;
			}
		}
	if (last) addedge(pos, last, len);
}
int main() {
	read(n), tot = n;
	for (int i = 1; i <= n; i++)
		read(w[i]), belong[i] = i;
	for (int i = 1; i <= n - 1; i++) {
		read(x[i]), read(y[i]), read(l[i]);
		b[x[i]].push_back(make_pair(y[i], l[i]));
		b[y[i]].push_back(make_pair(x[i], l[i]));
	}
	rebuild(1, 0);
	for (int i = 1; i <= tot; i++)
		val[i] = true;
	int ans = findans(tot); double bns = 0;
	dist[ans] = 0, dfs(ans, 0, true);
	for (int i = 1; i <= tot; i++)
		bns += w[i] * sqrt(dist[i]) * dist[i];
	printf("%d %.10lf\n", belong[ans], bns);
	return 0;
}