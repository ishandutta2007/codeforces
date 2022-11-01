//batch scheduling 2002
#include <bits/stdc++.h>
#include <vector>
#include <cstdio>
#include <deque>
#include <iostream>
 
using namespace std;
 
#define forn(i, n) for (int i = 0; i < n; i++)
#define re return
#define sz(a) (int)a.size()
#define fi first
#define se second
#define mp(a, b) make_pair(a, b)
typedef long long ll;
typedef double ld;
typedef pair<ld, ld> pld;
typedef vector<ll> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll cnn = 800, sz_g = 200000, pq = 100000000, md = 1000000007, inf = 1000000000LL, mod2 = 5000000, /*mod = inf + 7, */ma = 128 * 1024;

int n, m, p, dp[300][300], du[300][300];
vector<pii> q[300 * 300 + 1];
//set<pair<ll, pii> > c;
deque<pair<int, pii> > c;

int abss(int k) {
	if (k < 0) re -k;
	re k;
}

bool ok(int x, int y) {
	re x >= 0 && x < n && y >= 0 && y < m;
}

int main() {
	iostream::sync_with_stdio(0), cin.tie(0);
	//freopen("sum.in", "r", stdin);
	//freopen("game24.out", "w", stdout);
	cin >> n >> m >> p;
	forn (i, n)
		forn (j, m) {
			int cc;
			cin >> cc;
			q[cc - 1].push_back(mp(i, j));
			dp[i][j] = inf;
			//c.insert(mp(inf, mp(i, j)));
		}
	dp[q[p - 1][0].fi][q[p - 1][0].se] = 0;
	for (int i = p - 1; i > 0; i--) {
		if (sz(q[i]) * sz(q[i - 1]) < n * m)
			for (auto v : q[i])
				for (auto b : q[i - 1])
					dp[b.fi][b.se] = min(dp[b.fi][b.se], dp[v.fi][v.se] + abss(v.fi - b.fi) + abss(b.se - v.se));
		else {
			vector<pair<int, pii> > qq;
			forn (i, n)
				forn (j, m) {
					du[i][j] = inf;
				}
			for (auto v : q[i])
				qq.push_back(mp(dp[v.fi][v.se], v)), du[v.fi][v.se] = dp[v.fi][v.se];
			sort(qq.begin(), qq.end());
			reverse(qq.begin(), qq.end());
			c.clear(); 
			c.push_back(qq[sz(qq) - 1]);
			qq.pop_back();
			while (!c.empty() || !qq.empty()) {
				while (!qq.empty() && (c.empty() || qq[sz(qq) - 1].fi <= c.front().fi)) {
					c.push_front(qq[sz(qq) - 1]);
					qq.pop_back();
				}
				pii a = c.front().se;
				int k = c.front().fi;
				c.pop_front();				
				if (ok(a.fi - 1, a.se) && du[a.fi - 1][a.se] > k + 1) {
					du[a.fi - 1][a.se] = k + 1;
					c.push_back(mp(k + 1, mp(a.fi - 1, a.se)));
				}
				if (ok(a.fi, a.se - 1) && du[a.fi][a.se - 1] > k + 1) {
					du[a.fi][a.se - 1] = k + 1;
					c.push_back(mp(k + 1, mp(a.fi, a.se - 1)));
				}
				if (ok(a.fi + 1, a.se) && du[a.fi + 1][a.se] > k + 1) {
					du[a.fi + 1][a.se] = k + 1;
					c.push_back(mp(k + 1, mp(a.fi + 1, a.se)));
				}
				if (ok(a.fi, a.se + 1) && du[a.fi][a.se + 1] > k + 1) {
					du[a.fi][a.se + 1] = k + 1;
					c.push_back(mp(k + 1, mp(a.fi, a.se + 1)));
				}
			}
			for (auto v : q[i - 1])
				dp[v.fi][v.se] = du[v.fi][v.se];
		}
	}
	int ans = inf;
	for (auto v : q[0])
		ans = min(ans, dp[v.fi][v.se] + v.fi + v.se);
	cout << ans;
	re 0;
}