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

const int N = 2e5 + 500;
const int V = 100;

int n, a[N], pref[N][V+1], res;
vector <int> b[N];

inline int sum(int l, int r, int c) {
	return pref[r][c] - pref[l - 1][c];
}

int second_max(const int l, const int r, const int c) {
	int best = 0;
	rep(i, 1, V)
		if ((!best || sum(l, r, i) > sum(l, r, best)) && i != c)
			best = i;
	return best;
}

int solve(int p) {
	int best = 0;
	rep(i, 1, V)
		if (!best || sum(p, n, i) > sum(p, n, best))
			best = i;
	int r = n, e = -1;
	while (true) {
		//~ cout << p << " " << res << " " << best << endl;
		if (r < p) return 0;
		if (r - p + 1 <= res) return 0;
		int id = second_max(p, r, best);
		if (id == 0) return 0;
		int diff = sum(p, r, best) - sum(p, r, id);
		if (!diff) return r - p + 1;
		e += diff;
		if (e >= sz(b[best])) return 0;
		r = b[best][e] - 1;
	}
	return 0;
}			
	
int main() {
	scanf("%d", &n);
	rep(i, 1, n) {
		scanf("%d", a + i);
		rep(j, 1, V)
			pref[i][j] = pref[i - 1][j];
		pref[i][a[i]]++;
	}
	per(i, 1, n) b[a[i]].pb(i);
	vector <int> ord(n);
	iota(all(ord), 1);
	random_shuffle(all(ord));
	for (auto p : ord)
		res = max(res, solve(p));
	printf ("%d\n", res);
	return 0;
}