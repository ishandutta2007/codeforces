#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
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
bool res[MAXN];
vector <int> a[MAXN];
int n, m, depth[MAXN];
pair <int, int> dp[MAXN];
int rnd() {
	return (rand() ^ (rand() << 15)) % n + 1;
}
pair <int, int> operator + (pair <int, int> a, int b) {
	if (depth[b] < depth[a.first]) {
		a.second = a.first;
		a.first = b;
	} else if (depth[b] < depth[a.second]) a.second = b;
	return a;
}
bool ans, instack[MAXN], vis[MAXN];
void dfs(int pos) {
	vis[pos] = instack[pos] = true;
	for (auto x : a[pos])
		if (!vis[x]) dfs(x);
		else ans &= instack[x];
	instack[pos] = false;
}
bool check(int pos) {
	ans = true;
	for (int i = 1; i <= n; i++)
		vis[i] = false;
	dfs(pos);
	return ans;
}
void work(int pos, int fa) {
	vis[pos] = true;
	depth[pos] = depth[fa] + 1;
	dp[pos] = make_pair(pos, pos);
	for (auto x : a[pos])
		if (!vis[x]) {
			work(x, pos);
			dp[pos] = dp[pos] + dp[x].first;
			dp[pos] = dp[pos] + dp[x].second;
		} else dp[pos] = dp[pos] + x;
	if (dp[pos].second == pos) res[pos] = true;
}
void getans(int pos, int fa) {
	vis[pos] = true;
	if (fa != 0) res[pos] &= res[dp[pos].first];
	for (auto x : a[pos]) if (!vis[x]) getans(x, pos);
}
int main() {
	srand('X' + 'Y' + 'X');
	int T; read(T);
	while (T--) {
		read(n), read(m);
		for (int i = 1; i <= n; i++) {
			res[i] = false;
			a[i].clear();
		}
		for (int i = 1; i <= m; i++) {
			int x, y; read(x), read(y);
			a[x].push_back(y);
		}
		int L = 100;
		while (L--) {
			int pos = rnd();
			if (check(pos)) {
				for (int i = 1; i <= n; i++)
					vis[i] = res[i] = false, depth[i] = 0;
				res[pos] = true;
				work(pos, 0);
				for (int i = 1; i <= n; i++)
					vis[i] = false;
				getans(pos, 0);
				break;
			}
		}
		int cnt = 0;
		for (int i = 1; i <= n; i++)
			cnt += res[i];
		if (cnt * 5 < n) puts("-1");
		else {
			for (int i = 1; i <= n; i++)
				if (res[i]) printf("%d ", i);
			printf("\n");
		}
	}
	return 0;
}