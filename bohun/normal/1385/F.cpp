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

const int N = 2e5 + 10;

int n, k;
vector <int> G[N], L[N];
set <pair<int, int>> S;
bool dead[N];
int xd[N];

void solve() {
	scanf ("%d%d", &n, &k);
	rep(i, 1, n) G[i].clear(), L[i].clear(), dead[i] = 0, xd[i] = 0;
	rep(i, 2, n) {
		int u, v;
		scanf ("%d%d", &u, &v);
		G[u].pb(v);
		G[v].pb(u);
	}
	rep(i, 1, n)
		if (ss(G[i]) == 1)
			L[G[i][0]].pb(i);
	S.clear();
	rep(i, 1, n)
		S.insert(mp(ss(L[i]), i));
	int ans = 0;
	while (!S.empty()) {
		auto it = S.end(); it--;
		int v = it->se;
		S.erase(it);
		if (dead[v]) continue;
		if (ss(L[v]) < k) break;
		while (ss(L[v]) >= k) {
			int g = k;
			while (g--) {
				dead[L[v].back()] = 1;
				L[v].pop_back();
				xd[v]++;
			}
			ans++;
		}
		if (xd[v] + 1 != ss(G[v])) S.insert(mp(ss(L[v]), v));
		else { // xd[v] + 1 == ss(G[v])
			for (auto it : G[v]) 
				if (!dead[it]) {
					S.erase(mp(ss(L[it]), it));
					L[it].pb(v);
					S.insert(mp(ss(L[it]), it));
					break;
				}
		}
	}
	printf ("%d\n", ans);	
}

int main() {
	int T;
	scanf ("%d", &T);
	while (T--) {
		solve();
	}
	return 0;
}