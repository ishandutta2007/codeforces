#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
const int MAXM = 405;
const int P = 1e9 + 7;
typedef long long ll;
typedef bitset <32> info;
template <typename T> void chkmax(T &x, T y) {x = max(x, y); }
template <typename T> void chkmin(T &x, T y) {x = min(x, y); } 
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
unordered_set <info> st;
unordered_map <info, int> home;
vector <pair <int, int>> a[MAXN];
info q[MAXN]; int l, r, trans[MAXM][32];
int x[MAXN], y[MAXN], z[MAXN], f[MAXN];
int sum[MAXN], from[MAXN];
vector <int> v[MAXN][2];
int find(int x) {
	if (f[x] == x) return x;
	else return f[x] = find(f[x]);
}
void dfs(int pos, int fa, int f, int s) {
	sum[pos] = s, from[pos] = f;
	for (auto x : a[pos])
		if (x.first != fa) {
			dfs(x.first, pos, f, s ^ x.second);
		}
}
void update(int &x, int y) {
	x += y;
	if (x >= P) x -= P;
}
int main() {
	q[l = r = 1] = 1;
	st.insert(q[1]);
	while (l <= r) {
		info tmp = q[l++];
		for (int i = 0; i <= 31; i++) {
			info res = tmp;
			for (int j = 0; j <= 31; j++)
				res[i ^ j] = (res[i ^ j] | tmp[j]);
			if (st.count(res) == 0) {
				st.insert(res);
				q[++r] = res;
			}
		}
	}
	for (int i = 1; i <= r; i++)
		home[q[i]] = i;
	for (int t = 1; t <= r; t++) {
		info tmp = q[t];
		for (int i = 0; i <= 31; i++) {
			info res = tmp;
			for (int j = 0; j <= 31; j++)
				res[i ^ j] = (res[i ^ j] | tmp[j]);
			if (res.count() == tmp.count() * 2) trans[t][i] = home[res];
			else trans[t][i] = 0;
		}
	}
	int n, m; read(n), read(m);
	for (int i = 1; i <= n; i++)
		f[i] = i;
	static int p[MAXN];
	for (int i = 1; i <= m; i++) {
		read(x[i]), read(y[i]), read(z[i]), p[i] = i;
	}
	sort(p + 1, p + m + 1, [&] (int a, int b) {return ((x[a] == 1) || (y[a] == 1)) < ((x[b] == 1) || (y[b] == 1)); });
	static bool vis[MAXN], key[MAXN];
	for (int i = 1; i <= m; i++) {
		int pos = p[i];
		if (find(x[pos]) != find(y[pos])) {
			f[find(x[pos])] = find(y[pos]);
			a[x[pos]].emplace_back(y[pos], z[pos]);
			a[y[pos]].emplace_back(x[pos], z[pos]);
		} else vis[pos] = true;
	}
	for (auto x : a[1]) {
		dfs(x.first, 1, x.first, x.second);
		key[x.first] = true;
	}
	for (int i = 1; i <= m; i++)
		if (vis[i]) {
			int len = sum[x[i]] ^ sum[y[i]] ^ z[i];
			if (from[x[i]] == from[y[i]]) {
				v[from[x[i]]][0].push_back(len);
			} else {
				assert(from[x[i]] == 0 || from[y[i]] == 0);
				if (from[x[i]] == 0) v[from[y[i]]][1].push_back(len);
				else v[from[x[i]]][1].push_back(len);
			}
		}
	static int dp[MAXN][MAXM]; dp[0][1] = 1;
	for (int i = 1; i <= n; i++)
		if (!key[i]) memcpy(dp[i], dp[i - 1], sizeof(dp[i - 1]));
		else {
			if (v[i][1].size()) {
				for (int j = 1; j <= r; j++) {
					update(dp[i][j], dp[i - 1][j]);
					int res = j;
					for (auto x : v[i][0])
						res = trans[res][x];
					if (res != 0) update(dp[i][res], 2ll * dp[i - 1][j] % P);
					for (auto x : v[i][1])
						res = trans[res][x];
					if (res != 0) update(dp[i][res], dp[i - 1][j]);
				}
			} else {
				for (int j = 1; j <= r; j++) {
					update(dp[i][j], dp[i - 1][j]);
					int res = j;
					for (auto x : v[i][0])
						res = trans[res][x];
					if (res != 0) update(dp[i][res], dp[i - 1][j]);
				}
			}
		}
	int ans = 0;
	for (int i = 1; i <= r; i++)
		update(ans, dp[n][i]);
	cout << ans << endl;
	return 0;
}