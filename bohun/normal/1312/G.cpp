#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep2(i, j, n) for (LL i = j; i <= n; ++i)
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define boost cin.tie(0);ios_base::sync_with_stdio(0);
#define vi vector <int>
#define ull unsigned long long

using namespace std;

const int N = 1e6 + 1000;

int n, a, k;
char c;
int to[N][26];
int d[N];
int e[N];
int h[N];
int f[N];

int cnt;
int ans[N];

void dfs(int u) {
	f[u] = cnt;
	if (e[u]) cnt++;
	rep(i, 0, 25)
		if (to[u][i]) {
			h[to[u][i]] = h[u] + 1;
			dfs(to[u][i]);
		}
}

multiset <int> s1, s2;

void solve(int u) {
	//printf ("node = %d %d\n", u, f[u]);
	//for (auto it : s2) cat(it);
	if (!u) ans[u] = 0;
	else {
		ans[u] = n + 10;
		ans[u] = min(ans[u], h[u] + *s1.begin());
		if (e[u]) ans[u] = min(ans[u], 1 + f[u] + *s2.begin());
	}
	s1.insert(ans[u] - h[u]);
	s2.insert(ans[u] - f[u]);
	rep(i, 0, 25) 
		if (to[u][i]) 
			solve(to[u][i]);
	s1.erase(s1.find(ans[u] - h[u]));
	s2.erase(s2.find(ans[u] - f[u]));
}
	

int main() {
	scanf ("%d", &n);
	rep(i, 1, n) {
		scanf ("%d %c", &a, &c);
		to[a][c - 'a'] = i;
	}
	scanf ("%d", &k);
	rep(i, 1, k) {
		scanf ("%d", d + i);
		e[d[i]] = 1;
	}
	dfs(0);
	solve(0);
	rep(i, 1, k) printf ("%d ", ans[d[i]]);

	return 0;
}