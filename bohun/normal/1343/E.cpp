#include <bits/stdc++.h>
#define ll long long
#define ld long double
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

const int nax = 4e5 + 100;

int n, m, a1, a2, a3;
int a, b;
vector <int> g[nax];

ll cost[nax];
int b1[nax], b2[nax], b3[nax];

int q[nax];

void bfs(int *t, int s) {
	rep(i, 1, n)
		t[i] = 1e9;
	t[s] = 0;
	int l = 0, r = 1;
	q[0] = s;
	while (l < r) {
		int v = q[l++];
		for (auto it : g[v]) {
			if (t[v] + 1 < t[it]) {
				t[it] = t[v] + 1;
				q[r++] = it;
			}
		}
	}
}
	

int main() {
	int t;
	scanf ("%d", &t);
	while (t--) {
		scanf ("%d%d%d%d%d", &n, &m, &a1, &a2, &a3);
		rep(i, 1, n) g[i].clear();
		rep(i, 1, m) {
			int d;
			scanf ("%d", &d);
			cost[i] = d;
		}
		sort(cost + 1, cost + m + 1);
		rep(i, 1, m) {
			scanf ("%d%d", &a, &b);
			g[a].pb(b);
			g[b].pb(a);
		}
		bfs(b1, a1);
		bfs(b2, a2);
		bfs(b3, a3);
		rep(i, 1, m) cost[i] += cost[i - 1];
		ll ans = 1e18;
		rep(i, 1, n) {
			int s1 = b2[i];
			int s2 = b1[i] + b3[i];
			if (s1 + s2 > m) continue;
			ans = min(ans, cost[s1] * 2 + cost[s1 + s2] - cost[s1]);
		}
		printf ("%lld\n", ans);	
		
	}
	
	return 0;
}