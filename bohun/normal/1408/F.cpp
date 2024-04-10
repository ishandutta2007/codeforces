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
 
using ll = long long;
using ld = long double;
using namespace std;

const int N = 15005;

int n;
vector <int> a[N], b[N], c[N];
vector <pair<int, int>> ans;

vector<int> solve(vector <int> x, vector <int> y) {
	if (sz(x) > sz(y)) swap(x, y);
	int s = sz(x);
	rep(i, 0, s - 1)
		ans.pb(mp(x[i], y[i]));
	vector<int> z;
	for (auto p : x)
		z.pb(p);
	for (auto p : y)	
		z.pb(p);
	return z;
}

void work() {
	printf ("%d\n", sz(ans));
	for (auto [a, b] : ans)
		printf ("%d %d\n", a, b);
	exit(0);
}

int main() {
	scanf ("%d", &n);
	int sz = n;
	rep(i, 1, n)
		a[i] = {i};
	int id = 0;
	while (1) {
		int nsz = 0;
		if (sz & 1) 
			c[id] = a[sz];
		if (sz == 1) break;
		for (int i = 1; i + 1 <= sz; i += 2) {
			nsz++;
			b[nsz] = solve(a[i], a[i + 1]);
		}
		rep(i, 1, nsz)
			a[i] = b[i];
		sz = nsz;
		id++;
	}
	int start = -1, end = -1, cnt = 0;
	rep(i, 0, 30) {
		if (!sz(c[i])) continue;
		if (start == -1) start = i;
		end = i;
		cnt++;
	}
	
	if (cnt <= 2) work();
	
	rep(i, start, end - 1) {
		if (sz(c[i])) continue;
		int ile = 1 << i;
		while (sz(c[i]) < ile) {
			int x = c[end].back();
			c[end].pop_back();
			c[i].pb(x);
		}
	}
	
	vector <int> Q;
	
	int ile = (1 << start);
	while (sz(Q) < ile) {
		int x = c[end].back();
		c[end].pop_back();
		Q.pb(x);
	}
	
	auto elo = solve(Q, c[start]);
	rep(i, start + 1, end) 
		elo = solve(elo, c[i]);
	work();
		
	
	return 0;
}