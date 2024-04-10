#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define per(i, a, b) for (int i = b; i >= a; --i)
#define all(x) x.begin(), x.end()
 
using ll = long long;
using namespace std;
 
int n;
vector<int> g[2];
 
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		g[0].clear(); g[1].clear();
		scanf("%d", &n);
		rep(i, 1, n) 
			rep(j, 0, 1) {
				int x;
				scanf("%d", &x);
				g[j].pb(x);
			}
		ll ans = 1;
		rep(i, 0, 1)
			if (n % 2 == 0) {
				sort(all(g[i]));
				ans *= (g[i][n / 2] - g[i][n / 2 - 1] + 1);
			}
		printf("%lld\n", ans);	
	}
	return 0;
}