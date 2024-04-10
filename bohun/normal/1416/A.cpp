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

const int N = 3e5 + 100;
 
int n, a;
vector <int> val[N];
int gap[N], ans[N];
 
int main() {
	int T;
	scanf ("%d", &T);
	while (T--) {
		scanf ("%d", &n);
		rep(i, 1, n) val[i].clear();
		rep(i, 1, n) val[i].pb(0);
		rep(i, 1, n) {
			scanf ("%d", &a);
			val[a].pb(i);
		} 
		rep(i, 1, n) val[i].pb(n + 1), ans[i] = 1e9;
		rep(i, 1, n) {
			gap[i] = 0;
			rep(j, 1, sz(val[i]) - 1)
				gap[i] = max(gap[i], val[i][j] - val[i][j - 1] - 1);
			ans[gap[i] + 1] = min(ans[gap[i] + 1], i);
		}
		rep(i, 2, n)
			ans[i] = min(ans[i], ans[i - 1]);
		rep(i, 1, n) if (ans[i] == 1e9) ans[i] = -1;
		rep(i, 1, n) printf ("%d ", ans[i]);
		puts("");
	}
	
	return 0;
}