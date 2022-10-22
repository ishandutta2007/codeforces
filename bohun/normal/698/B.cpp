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

using namespace std;

const int nax = 2e5 + 111;

int n;
int p[nax];

vector <int> good, bad;

int odw[nax];
bool cycle = 0;

void dfs(int u) {
	odw[u] = 1;
	if (!cycle && odw[p[u]] == 1) {
		cycle = 1;
		if (p[u] == u) good.pb(u);
		else bad.pb(u);
	}
	if (odw[p[u]] == 0)
		dfs(p[u]);
	odw[u] = 2;
}

int main() {	
	scanf ("%d", &n);
	rep(i, 1, n) scanf ("%d", p + i);
	
	rep(i, 1, n) if (!odw[i]) {
		cycle = 0;
		dfs(i);
	}
	
	if (ss(good) == 0) {
		printf ("%d\n", ss(bad));
		for (auto it : bad) p[it] = bad[0];
	}
	else {
		printf ("%d\n", ss(bad) + ss(good) - 1);
		for (auto it : bad) p[it] = good[0];
		for (auto it : good) p[it] = good[0];
	}
	rep(i, 1, n) printf ("%d ", p[i]);
	
	return 0;
}