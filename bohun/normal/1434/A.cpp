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

const int N = 1e5 + 50;

int a[6], n, b[N], c[N], ans = 1 << 30;
set <pair<int, int>> S;

void solve(int k) {
	S.clear();
	rep(i, 1, n) {
		c[i] = 5;
		S.insert({b[i] - a[5], i});
	}
	rep(i, 1, n) {
		int val = b[i] - a[k];
		while (S.begin()->fi < val) {
			int id = S.begin()->se;
			S.erase(S.begin());
			c[id]--;
			if (c[id] == -1) return;
			S.insert({b[id] - a[c[id]], id});
		}
		//~ cat(prev(S.end())->fi);
		//~ cat(val);
		ans = min(ans, prev(S.end())->fi - val);
	}
}	

int main() {
	rep(i, 0, 5) scanf ("%d", a + i);
	scanf ("%d", &n);
	rep(i, 1, n) scanf ("%d", b + i);
	sort(a, a + 6);
	sort(b + 1, b + n + 1);
	rep(i, 0, 5)
		solve(i);
	printf ("%d\n", ans);
	return 0;
}