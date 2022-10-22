#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define all(x) x.begin(), x.end()

using namespace std;	

const int N = 1e5 + 101;

int n, x, y;
int b[N], ans[N];
vector <int> G[N];
set <pair<int, int>> S;

void solve() {
	scanf ("%d%d%d", &n, &x, &y);
	rep(i, 1, n + 1) G[i].clear();
	S.clear();
	rep(i, 1, n) {
		scanf ("%d", b + i);
		G[b[i]].pb(i);
		ans[i] = 0;
	}
	rep(i, 1, n + 1) S.insert(mp(ss(G[i]), i));
	int X = x;
	while (X--) {
		auto it = S.end();
		it--;
		int v = it->se;
		S.erase(it);
		ans[G[v].back()] = v;
		G[v].pop_back();
		S.insert(mp(ss(G[v]), v));
	}
	
	int all = 0, mx = 0, color = -1;
	vector <int> xd;
	rep(i, 1, n + 1) {
		if (ss(G[i]) == 0) color = i;
		all += ss(G[i]);
		mx = max(mx, ss(G[i]));
	}
	
	bool done = false;
	rep(i, 1, n + 1) {
		if (ss(G[i]) == mx && !done) {
			while (2 * ss(G[i]) > all) {
				G[i].pop_back();
				all--;
			}
			done = true;
		}
		for (auto it : G[i])
			xd.pb(it);
	}
	
	if (ss(xd) < y - x) {
		printf ("NO\n");
		return;
	}
	
	printf ("YES\n");
	int sz = all / 2;
	
	rep(i, 0, ss(xd) - 1) {
		ans[xd[i]] = b[xd[(i + sz) % all]];
	}
	
	int del = ss(xd) - (y - x);
	for (auto it : xd) {
		if (del) {
			del--;
			ans[it] = color;
		}
	}
	
	rep(i, 1, n) {
		if (!ans[i]) ans[i] = color;
		printf ("%d ", ans[i]);
	}
	printf ("\n");
}

int main() {	
	int T;
	scanf ("%d", &T);
	while (T--)
		solve();
	
	return 0;
}