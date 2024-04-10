#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define all(x) x.begin(), x.end()
#define ull unsigned long long

using namespace std;

const int N = 1e6 + 100;

int n, a;
int sito[N];
vector <int> p;
vector <int> g[N];
int ans = 1e9;

int dis[N];
int par[N];
int t[N];

int solve(int v) {
	rep(i, 1, N - 1) {
		dis[i] = 1e9;
		par[i] = -1;
	}
	dis[v] = 0;
	int l = 0, r = 1;
	t[l] = v;
	while (l < r) {
		int u = t[l++];
		for (auto it : g[u]) {
			if (dis[it] != 1e9 && par[u] != it) {
				return dis[u] + dis[it] + 1;
			}
			if (dis[it] == 1e9) {
				t[r++] = it;
				dis[it] = dis[u] + 1;
				par[it] = u;
			}
		}
	}
	return 1e9;
}

map <pair<int, int>, int> q;

int main() {
	p.pb(1);
	rep(i, 2, N - 1)
		if (!sito[i]) {
			if (i <= 1000) p.pb(i);
			for (int j = i; j < N; j += i)
				sito[j] = i;
		}
	scanf ("%d", &n);
	rep(i, 1, n) {
		scanf ("%d", &a);
		map <int, int> cnt;
		vector <int> v, f;
		while (a > 1) {
			v.pb(sito[a]);
			cnt[sito[a]]++;
			a /= sito[a];
		}
		sort(all(v));
		v.erase(unique(all(v)), v.end());
		for (auto it : v)
			if (cnt[it] % 2 == 1) f.pb(it);
		while (ss(f) < 2) f.pb(1);
		g[f[0]].pb(f[1]);
		g[f[1]].pb(f[0]);
		q[{f[0], f[1]}]++;
		q[{f[1], f[0]}]++;
		if (f[0] == 1 && f[1] == 1) {
			printf ("1\n");
			return 0;
		}
	}
	for (auto it : q)
		if (it.se > 1) 
			return printf ("2\n"), 0;
	for (auto it : p)
		ans = min(ans, solve(it));
	if (ans == 1e9) ans = -1;
	printf ("%d\n", ans);
    return 0;
}