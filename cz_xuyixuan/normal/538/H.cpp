#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
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
int n, m, tot, ans[MAXN];
bool vis[MAXN], col[MAXN];
vector <int> e[MAXN], points[MAXN];
pair <int, int> s, tmp[2], v[MAXN], a[MAXN][2];
void foundAns(int x, int y) {
	assert(s.first <= x + y && x + y <= s.second);
	puts("POSSIBLE");
	printf("%d %d\n", x, y);
	static int ans[MAXN];
	for (int i = 1; i <= tot; i++) {
		if (a[i][0].first <= x && x <= a[i][0].second && a[i][1].first <= y && y <= a[i][1].second) {
			for (auto x : points[i])
				ans[x] = col[x];
		} else if (a[i][0].first <= y && y <= a[i][0].second && a[i][1].first <= x && x <= a[i][1].second) {
			for (auto x : points[i])
				ans[x] = !col[x];
		} else assert(false);
	}
	for (int i = 1; i <= n; i++)
		printf("%d", ans[i] + 1);
	printf("\n");
	exit(0);
}
void solveMin() {
	static pair <pair <int, int>, int> b[MAXN];
	for (int i = 1, j = 0; i <= n; i++) {
		b[++j] = make_pair(a[i][0], i);
		b[++j] = make_pair(a[i][1], i);
	}
	sort(b + 1, b + 2 * tot + 1);
	
	static int pre[MAXN], suf[MAXN];
	pre[0] = suf[2 * tot + 1] = INF;
	for (int i = 2 * tot; i >= 1; i--)
		suf[i] = min(suf[i + 1], b[i].first.second);
	for (int i = 1; i <= 2 * tot; i++)
		pre[i] = min(pre[i - 1], b[i].first.second);
	
	static int cnt[MAXN];
	priority_queue <int, vector <int>, greater <int>> Heap, Delt;
	for (int i = 1; i <= tot; i++)
		Heap.push(max(a[i][0].second, a[i][1].second));
	for (int i = 2 * tot, nxt; i >= 1; i = nxt) {
		nxt = i; while (nxt >= 1 && b[nxt].first.first == b[i].first.first) nxt--;
		while (!Heap.empty() && !Delt.empty() && Heap.top() == Delt.top()) {
			Heap.pop();
			Delt.pop();
		}
		int x = b[i].first.first, y = s.second - x;
		if (!Heap.empty()) chkmin(y, Heap.top());
		chkmin(y, suf[i + 1]);
		if (b[i].first.first <= pre[i] && y >= b[2 * tot].first.first && x + y >= s.first) foundAns(x, y);
		for (int j = nxt + 1; j <= i; j++) {
			if (++cnt[b[j].second] == 2) return;
			else Delt.push(max(a[b[j].second][0].second, a[b[j].second][1].second));
		}
	}
}
bool cmp(pair <pair <int, int>, int> x, pair <pair <int, int>, int> y) {
	return x.first.second > y.first.second;
}
void solveMax() {
	static pair <pair <int, int>, int> b[MAXN];
	for (int i = 1, j = 0; i <= n; i++) {
		b[++j] = make_pair(a[i][0], i);
		b[++j] = make_pair(a[i][1], i);
	}
	sort(b + 1, b + 2 * tot + 1, cmp);
	
	static int pre[MAXN], suf[MAXN];
	pre[0] = suf[2 * tot + 1] = 0;
	for (int i = 2 * tot; i >= 1; i--)
		suf[i] = max(suf[i + 1], b[i].first.first);
	for (int i = 1; i <= 2 * tot; i++)
		pre[i] = max(pre[i - 1], b[i].first.first);
	
	static int cnt[MAXN];
	priority_queue <int> Heap, Delt;
	for (int i = 1; i <= tot; i++)
		Heap.push(min(a[i][0].first, a[i][1].first));
	for (int i = 2 * tot, nxt; i >= 1; i = nxt) {
		nxt = i; while (nxt >= 1 && b[nxt].first.second == b[i].first.second) nxt--;
		while (!Heap.empty() && !Delt.empty() && Heap.top() == Delt.top()) {
			Heap.pop();
			Delt.pop();
		}
		int x = b[i].first.second, y = s.first - x;
		if (!Heap.empty()) chkmax(y, Heap.top());
		chkmax(y, suf[i + 1]);
		if (b[i].first.second >= pre[i] && y <= b[2 * tot].first.second && x + y <= s.second) foundAns(x, y);
		for (int j = nxt + 1; j <= i; j++) {
			if (++cnt[b[j].second] == 2) return;
			else Delt.push(min(a[b[j].second][0].first, a[b[j].second][1].first));
		}
	}
}
void dfs(int pos) {
	vis[pos] = true;
	points[tot].push_back(pos);
	chkmax(tmp[col[pos]].first, v[pos].first);
	chkmin(tmp[col[pos]].second, v[pos].second);
	for (auto x : e[pos])
		if (!vis[x]) {
			col[x] = !col[pos];
			dfs(x);
		} else if (col[pos] == col[x]) {
			puts("IMPOSSIBLE");
			exit(0);
		}
}
int main() {
	read(s.first), read(s.second), read(n), read(m);
	for (int i = 1; i <= n; i++)
		read(v[i].first), read(v[i].second);
	for (int i = 1; i <= m; i++) {
		int x, y; read(x), read(y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			tmp[0] = tmp[1] = make_pair(0, INF);
			tot++, dfs(i);
			if (tmp[0].first > tmp[0].second || tmp[1].first > tmp[1].second) {
				puts("IMPOSSIBLE");
				return 0;
			}
			a[tot][0] = tmp[0];
			a[tot][1] = tmp[1];
		}
	}
	solveMin();
	solveMax();
	puts("IMPOSSIBLE");
	return 0;
}