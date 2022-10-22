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

using namespace std;

const int N = 2e5 + 100;

int T;
int n, k;
char s[N];
vector <int> g[N];
bool odw[N];
int a[26];

void dfs(int v) {
	a[s[v] - 'a']++;
	odw[v] = 1;
	for (auto it : g[v])
		if (!odw[it])
			dfs(it);
}

void solve() {
	scanf ("%d%d", &n, &k);
	scanf ("%s", s + 1);
	rep(i, 1, n) {
		g[i].clear();
		odw[i] = 0;
	}
	rep(i, 1, n / 2) {
		int j = n - i + 1;
		g[i].pb(j);
		g[j].pb(i);
	}
	int p = n - k;
	rep(i, 1, p) {
		int j = n - p + i;
		g[i].pb(j);
		g[j].pb(i);
	}
	int res = 0;
	rep(i, 1, n) {
		if (odw[i]) continue;
		rep(i, 0, 25) a[i] = 0;
		dfs(i);
		int s = 0;
		int m = 0;
		rep(i, 0, 25) {
			s += a[i];
			m = max(m, a[i]);
		}
		res += s - m;
	}
	printf ("%d\n", res);
}

int main() {
	scanf ("%d", &T);
	while (T--) {
		solve();
	}
	
    return 0;
}