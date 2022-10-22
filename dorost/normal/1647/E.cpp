/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 101234;
int vis[N], p[N], a[N], ans[N];
vector <int> cy;
vector <int> g[N], c[N], v[N];
int cnt = 0, t = 0;
pair <int, int> cc[N];
bool f[N];
pair <int, int> dp[N];
bool q[N];
vector <int> top;
int bans[N];

void dfs(int v) {
	vis[v] = 1;
	if (vis[p[v]] == 0)
		dfs(p[v]);
	else if (vis[p[v]] == 1)
		cy.push_back(v);
	vis[v] = 2;
}

pair <int, int> fsd (int v) {
	if (cc[v].F > 0) {
		return dp[v] = make_pair(v, 0);
	}
	if (dp[v].F != 0) 
		return dp[v];
	pair <int, int> ans = fsd(p[v]);
	return dp[v] = make_pair(ans.F, ans.S + 1);
}

void sfd(int v) {
	if (q[v]) {
		if (t == 0) {
			ans[v] = v;
		} else {
			assert((int)top.size() >= t);
			ans[v] = top[(int)top.size() - t];
		}
	}
	top.push_back(v);
	for (auto u : g[v]) {
		sfd(u);
	}
	top.pop_back();
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> p[i], cc[i] = make_pair(-i, 0), f[p[i]] = true;
	for (int i = 1; i <= n; i++) {
		if (!f[i])
			cnt++;
	}
	int mx = 0;
	for (int i = 1; i <= n; i++)
		cin >> a[i], mx = max(mx, a[i]);
	t = (mx - n) / cnt;
	assert((mx - n) % cnt == 0);
	for (int i = 1; i <= n; i++)
		if (vis[i] == 0)
			dfs(i);
	for (auto x : cy) {
		c[x].push_back(x);
		cc[x] = make_pair(x, 0);
		int y = p[x];
		while (y != x) {
			cc[y] = make_pair(x, c[x].size());
			c[x].push_back(y);
			y = p[y];
		}
	}
	for (int i = 1; i <= n; i++) {
		if (cc[i].F > 0 && cc[p[i]].F > 0 && cc[i].F == cc[p[i]].F)
			continue;
		g[p[i]].push_back(i);
	}
	for (int i = 1; i <= n; i++)
		fsd(i);
	for (int i = 1; i <= n; i++) {
		if (dp[i].S <= t) {
			int k = t - dp[i].S;
			int s = dp[i].F;
			ans[i] = c[cc[s].F][(cc[s].S + k) % ((int)c[cc[s].F].size())];
		} else {
			q[i] = true;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (cc[i].F > 0) {
			sfd(i);
		}
	}
	//	cout << t << '\n';
	//	for (int i = 1; i <= n; i++)
	//		cout << i << ' ' << ans[i] << '\n';
	for (int i = 1; i <= n; i++) {
		assert(a[ans[i]] <= n);
		v[ans[i]].push_back(i);
	}
	set <int> st;
	for (int i = 1; i <= n; i++)
		st.insert(i);
	for (int i = 1; i <= n; i++) {
		if (v[i].empty())
			continue;
		bans[v[i][0]] = a[i];
		st.erase(a[i]);
	}
	for (int i = 1; i <= n; i++) {
		if (bans[i] != 0)
			continue;
		int mn = a[ans[i]];
		auto bn = st.lower_bound(mn);
		assert(bn != st.end());
		bans[i] = *bn;
		st.erase(bn);
	}
	for (int i = 1; i <= n; i++)
		cout << bans[i] << ' ';
}