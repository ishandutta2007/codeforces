#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(x) (int) x.size()
#define cat(x) cerr << #x << " = " << x << endl
#define all(x) x.begin(), x.end()
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
// c0 3f
using ll = long long;
using ld = long double;
using namespace std;

const int N = 1010;
const int M = 1e6;

int T, n, m;
vector <int> g[2];
bitset <2*M+5> B[2][N];

bool cmp0(pair<int, int> p, pair<int, int> q) {
	return 1LL * p.fi * q.se - 1LL * p.se * q.fi < 0;
}
bool cmp1(pair<int, int> p, pair<int, int> q) {
	return 1LL * p.fi * q.se - 1LL * p.se * q.fi > 0;
}
int sign(int x) {
	return (x > 0) - (x < 0);
}

void solve() {
	g[0].clear(); g[1].clear();
	scanf ("%d", &n);
	g[0].resize(n);
	for (auto &x : g[0])
		scanf ("%d", &x);
	scanf ("%d", &m);
	g[1].resize(m);
	for (auto &x : g[1])
		scanf ("%d", &x);
	if (n != m) 
		return printf ("No\n"), void(0);
		
	B[0][0][M] = B[1][0][M] = 1;
	rep(j, 0, 1)
		rep(i, 1, n)
			B[j][i] = (B[j][i - 1] << g[j][i - 1]) | (B[j][i - 1] >> g[j][i - 1]);
	if (B[0][n][M] == 0 || B[1][n][M] == 0) 
		return printf ("No\n"), void(0);
		
	vector <int> pos[2], neg[2];
	rep(j, 0, 1) {
		int s = M;
		per(i, 1, n) {
			int x = g[j][i - 1];
			if (B[j][i - 1][s - x] == 1) {
				pos[j].pb(x);
				s -= x;
			}
			else {
				neg[j].pb(-x);
				s += x;
			}
		}
	}
	vector <int> e[2];
	rep(i, 0, 1) {
		e[i] = pos[i];
		e[i].insert(e[i].end(), all(neg[i]));
	}
	vector <pair<int, int>> st, md, en;
	for (int i = 0; i < n; ++i) {
		int x = e[0][i], y = e[1][i];
		if (x > 0 && y > 0)
			st.pb(mp(x, y));
		if (sign(x) != sign(y)) 
			md.pb(mp(x, y));
		if (x < 0 && y < 0)
			en.pb(mp(x, y));
	}
	if (sz(pos[0]) < sz(pos[1])) {
		sort(all(st), cmp1);
		sort(all(md), cmp0);
		sort(all(en), cmp1);
	}
	else {
		sort(all(st), cmp0);
		sort(all(md), cmp1);
		sort(all(en), cmp0);
	}
	printf ("Yes\n");
	st.insert(st.end(), all(md));
	st.insert(st.end(), all(en));
	int x = 0, y = 0;
	assert(sz(st) == n);
	for (int i = 0; i < n; ++i) {
		if (sz(pos[0]) < sz(pos[1])) {
			x += st[i].fi;
			printf ("%d %d\n", x, y);
			y += st[i].se;
			printf ("%d %d\n", x, y);
		}
		else {
			y += st[i].se;
			printf ("%d %d\n", x, y);
			x += st[i].fi;
			printf ("%d %d\n", x, y);
		}
	}
}

int main() {
	scanf ("%d", &T);
	while (T--)
		solve();
}