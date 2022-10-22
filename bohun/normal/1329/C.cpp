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
#define pc(x) __builtin_popcount(x)

using namespace std;

const int N = (1 << 22) + 5;	

int t;
int n, g;
int a[N];
int lol[N];
int val[N];

multiset <pair<int, int>> setol;

bool good(int v) {
	return (v <= (1 << n) - 1 && a[v] > 0);
}

int cost(int v) {
	if (!good(2 * v) && !good(2 * v + 1)) {
		if (lol[v] <= g) return 0;
		return v;
	}
	if (a[2 * v] > a[2 * v + 1]) return cost(2 * v);
	return cost(2 * v + 1);
}

void change(int v) {
	if (!good(2 * v) && !good(2 * v + 1)) {
		a[v] = 0;
		return ;
	}
	if (a[2 * v] > a[2 * v + 1]) {
		a[v] = a[2 * v];
		change(2 * v);
	}
	else {
		a[v] = a[2 * v + 1];
		change(2 * v + 1);
	}
}

LL ans = 0;
vector <int> res;
	
void solve(int v) {
	if (!good(v)) return;
	while (lol[cost(v)] > g) {
		ans -= a[v];
		res.pb(v);
		change(v);
	}
	solve(2 * v);
	solve(2 * v + 1);
}

void solve() {
	res.clear();
	setol.clear();
	scanf ("%d%d", &n, &g);
	ans = 0;
	rep(i, 1, (1 << n) - 1) {
		scanf ("%d", a + i);
		lol[i] = 1 + lol[i / 2];
		ans += a[i];
	}
	solve(1);
	printf ("%lld\n", ans);
	for (auto it : res) printf ("%d ", it);
	printf ("\n");
}
	

int main() {
	scanf ("%d", &t);
	while (t--) solve();
	
    return 0;
}