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
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

const int N = 1e5 + 50;

int n, a, x;
vector <tuple<int, int, int>> res;

void solve(vector <int> &x) {
	if (sz(x) == 3) {
		res.pb({x[0], x[1], x[2]});
		return;
	}
	vector <int> now;
	rep(i, 1, 3) {
		now.pb(x.back());
		x.pop_back();
	}
	now.pb(x.back());
	res.pb({now[0], now[1], now[2]});
	x.pb(now[0]);
	solve(x);
	res.pb({now.back(), now[1], now[2]});
}
	
void print() {
	printf ("YES\n");
	printf ("%d\n", sz(res));
	for (auto [x, y, z] : res)
		printf ("%d %d %d\n", x + 1, y + 1, z + 1);
	exit(0);
}

int main() {
	scanf ("%d", &n);
	rep(i, 1, n) {
		scanf ("%d", &a);
		x ^= a;
	}
	if (n & 1) {
		vector <int> ord(n);
		iota(all(ord), 0);
		solve(ord);
		print();
	}
	if (x) return !printf ("NO\n");
	vector<int> ord(n - 1);
	iota(all(ord), 0);
	solve(ord);
	print();
	return 0;
}