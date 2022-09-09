#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
const int INF  = 1e9 + 7;
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
vector <int> b[MAXN], e[2], pointsII;
int n, m, f[MAXN], s[MAXN], Max[2];
bool vis[MAXN][2], vise[MAXN], cole[MAXN], used[MAXN];
struct edge {int x, y, n, c, t; } a[MAXN];
int find(int x) {
	if (f[x] == x) return x;
	else return f[x] = find(f[x]);
}
void dfs(int pos, bool c) {
	chkmax(Max[c], a[pos].t);
	e[c].push_back(pos);
	vise[pos] = true, cole[pos] = c;
	pointsII.push_back(a[pos].x);
	pointsII.push_back(a[pos].y);
	for (auto x : b[a[pos].x])
		if (!vise[x]) dfs(x, c ^ true);
		else if (pos != x && cole[pos] == cole[x]) Max[0] = Max[1] = INF;
	for (auto x : b[a[pos].y])
		if (!vise[x]) dfs(x, c ^ true);
		else if (pos != x && cole[pos] == cole[x]) Max[0] = Max[1] = INF;
}
bool check(int x) {
	for (int i = 1; i <= n; i++)
		f[i] = i, s[i] = 0, used[i] = false;
	for (int i = 1; i <= m; i++)
		vise[i] = false;
	for (int i = 1, nxt; i <= m; i = nxt + 1) {
		nxt = i; while (nxt + 1 <= m && a[nxt + 1].c == a[i].c) nxt++;
		vector <int> points;
		for (int j = i; j <= nxt; j++) {
			points.push_back(a[j].x);
			points.push_back(a[j].y);
		}
		sort(points.begin(), points.end());
		points.erase(unique(points.begin(), points.end()), points.end());
		for (auto x : points) {
			vis[x][0] = vis[x][1] = false;
			b[x].clear();
		}
		for (int j = i; j <= nxt; j++) {
			b[a[j].x].push_back(j);
			b[a[j].y].push_back(j);
			
		}
		for (auto x : points)
			if (b[x].size() >= 3) return false;
		for (int j = i; j <= nxt; j++)
			if (!vise[j]) {
				Max[0] = Max[1] = 0;
				e[0].clear();
				e[1].clear();
				pointsII.clear();
				dfs(j, false);
				if (Max[0] > x && Max[1] > x) return false;
				if (Max[0] > x) {
					for (auto x : e[1]) {
						if (used[a[x].x] || used[a[x].y]) return false;
						used[a[x].x] = used[a[x].y] = true;
					}
				} else if (Max[1] > x) {
					for (auto x : e[0]) {
						if (used[a[x].x] || used[a[x].y]) return false;
						used[a[x].x] = used[a[x].y] = true;
					}
				} else {
					if (e[0].size() > e[1].size()) swap(e[0], e[1]);
					if (e[0].size() < e[1].size()) {
						for (auto x : e[0]) {
							if (used[a[x].x] || used[a[x].y]) return false;
							used[a[x].x] = used[a[x].y] = true;
						}
					} else {
						int tx = 0, ty = 0;
						for (auto x : e[0]) vis[a[x].x][0] = vis[a[x].y][0] = true;
						for (auto x : e[1]) vis[a[x].x][1] = vis[a[x].y][1] = true;
						sort(pointsII.begin(), pointsII.end());
						pointsII.erase(unique(pointsII.begin(), pointsII.end()), pointsII.end());
						for (auto x : pointsII) {
							if (vis[x][0] && !vis[x][1]) {
								assert(tx == 0);
								tx = x;
							}
							if (vis[x][1] && !vis[x][0]) {
								assert(ty == 0);
								ty = x;
							}
							if (vis[x][1] && vis[x][0]) {
								if (used[x]) return false;
								used[x] = true;
							}
						}
						if (tx != 0) {
							tx = find(tx), ty = find(ty);
							if (tx != ty) f[tx] = ty, s[ty] += s[tx] + 1;
							else s[tx]++;
						}
					}
				}
			}
	}
	for (int i = 1; i <= n; i++)
		if (!used[i]) s[find(i)]--;
	for (int i = 1; i <= n; i++)
		if (s[find(i)] > 0) return false;
	return true;
}
vector <int> ans;
vector <pair <int, pair <vector <int>, vector <int>>>> c[MAXN];
void getans(int pos, int fa) {
	for (auto x : c[pos])
		if (x.first != fa) {
			if (!used[x.first]) getans(x.first, pos);
			if (!used[x.first]) {
				used[x.first] = true;
				for (auto y : x.second.first) ans.push_back(a[y].n);
			} else {
				assert(!used[pos]), used[pos] = true;
				for (auto y : x.second.second) ans.push_back(a[y].n);
			}
		}
}
void printans(int x) {
	for (int i = 1; i <= n; i++)
		f[i] = i, s[i] = 0, used[i] = false;
	for (int i = 1; i <= m; i++)
		vise[i] = false;
	for (int i = 1, nxt; i <= m; i = nxt + 1) {
		nxt = i; while (nxt + 1 <= m && a[nxt + 1].c == a[i].c) nxt++;
		vector <int> points;
		for (int j = i; j <= nxt; j++) {
			points.push_back(a[j].x);
			points.push_back(a[j].y);
		}
		sort(points.begin(), points.end());
		points.erase(unique(points.begin(), points.end()), points.end());
		for (auto x : points) {
			vis[x][0] = vis[x][1] = false;
			b[x].clear();
		}
		for (int j = i; j <= nxt; j++) {
			b[a[j].x].push_back(j);
			b[a[j].y].push_back(j);
		}
		for (auto x : points)
			if (b[x].size() >= 3) assert(false);
		for (int j = i; j <= nxt; j++)
			if (!vise[j]) {
				Max[0] = Max[1] = 0;
				e[0].clear();
				e[1].clear();
				pointsII.clear();
				dfs(j, false);
				if (Max[0] > x && Max[1] > x) assert(false);
				if (Max[0] > x) {
					for (auto x : e[1]) {
						if (used[a[x].x] || used[a[x].y]) assert(false);
						used[a[x].x] = used[a[x].y] = true;
						ans.push_back(a[x].n);
					}
				} else if (Max[1] > x) {
					for (auto x : e[0]) {
						if (used[a[x].x] || used[a[x].y]) assert(false);
						used[a[x].x] = used[a[x].y] = true;
						ans.push_back(a[x].n);
					}
				} else {
					if (e[0].size() > e[1].size()) swap(e[0], e[1]);
					if (e[0].size() < e[1].size()) {
						for (auto x : e[0]) {
							if (used[a[x].x] || used[a[x].y]) assert(false);
							used[a[x].x] = used[a[x].y] = true;
							ans.push_back(a[x].n);
						}
					} else {
						int tx = 0, ty = 0;
						for (auto x : e[0]) vis[a[x].x][0] = vis[a[x].y][0] = true;
						for (auto x : e[1]) vis[a[x].x][1] = vis[a[x].y][1] = true;
						sort(pointsII.begin(), pointsII.end());
						pointsII.erase(unique(pointsII.begin(), pointsII.end()), pointsII.end());
						for (auto x : pointsII) {
							if (vis[x][0] && !vis[x][1]) {
								assert(tx == 0);
								tx = x;
							}
							if (vis[x][1] && !vis[x][0]) {
								assert(ty == 0);
								ty = x;
							}
							if (vis[x][1] && vis[x][0]) {
								if (used[x]) assert(false);
								used[x] = true;
							}
						}
						if (tx != 0) {
							if (find(tx) != find(ty)) {
								f[find(tx)] = find(ty);
								c[tx].emplace_back(ty, make_pair(e[1], e[0]));
								c[ty].emplace_back(tx, make_pair(e[0], e[1]));
							} else {
								used[tx] = true;
								for (auto x : e[0]) ans.push_back(a[x].n);
							}
						} else for (auto x : e[0]) ans.push_back(a[x].n);
					}
				}
			}
	}
	for (int i = 1; i <= n; i++)
		if (!used[i]) getans(i, 0);
	cout << ans.size() << endl;
	for (auto x : ans)
		printf("%d ", x);
}
int main() {
	read(n), read(m);
	for (int i = 1; i <= m; i++) {
		read(a[i].x), read(a[i].y), a[i].n = i;
		read(a[i].c), read(a[i].t);
	}
	sort(a + 1, a + m + 1, [&] (edge x, edge y) {return x.c < y.c; });
	int l = 0, r = INF;
	while (l < r) {
		int mid = (l + r) / 2;
		if (check(mid)) r = mid;
		else l = mid + 1;
	}
	if (l == INF) puts("No");
	else {
		puts("Yes");
		printf("%d ", l);
		printans(l);
	}
	return 0;
}