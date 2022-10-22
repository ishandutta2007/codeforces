#include <bits/stdc++.h>
#define ll long long
#define ld long double
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

const int N = 2e5 + 101;

int n, T;
int a[N];
int dp[N];
int L[N], R[N];
vector <int> vec;
vector <int> g[N];

void solve() {
	vec.clear();
	scanf ("%d", &n);
	rep(i, 1, n) {
		scanf ("%d", a + i);
		vec.pb(a[i]);
	}
	sort(all(vec));
	vec.erase(unique(all(vec)), vec.end());
	
	int M = ss(vec);
	rep(i, 1, M + 1)
		g[i].clear();
	rep(i, 1, n) {
		a[i] = (int) (lower_bound(all(vec), a[i]) - vec.begin()) + 1;
		g[a[i]].pb(i);
	}
	int ans = n;
	rep(i, 1, M)
		ans = min(ans, n - ss(g[i]));
	rep(i, 1, M) {
		int s = 0;
		for (auto it : g[i]) {
			s++;
			auto ix = lower_bound(all(g[i + 1]), it) - g[i + 1].begin();
			int sum = s + ss(g[i + 1]) - ix;
			ans = min(ans, n - sum);
		}
	} 
	rep(i, 1, M + 1) {
		dp[i] = 0;
		L[i] = R[i] = 0;
	}
	rep(i, 1, n) {
		R[a[i]] = i;
		if (L[a[i]] == 0)
			L[a[i]] = i;
	}
	//cat(ans);
	per(i, 1, M) {
		//cat(i);
		//cat(L[i]);
		//cat(R[i]);
		dp[i] = ss(g[i]);
		if (R[i] < L[i + 1])
			dp[i] += dp[i + 1];
		else {
			auto ix = lower_bound(all(g[i + 1]), R[i]) - g[i + 1].begin();
			dp[i] += ss(g[i + 1]) - ix;
		}
		int ix = lower_bound(all(g[i - 1]), L[i]) - g[i - 1].begin();
		ans = min(ans, n - dp[i] - ix);
	}
	printf ("%d\n", ans);
		
}

int main() {
	scanf ("%d", &T);
	while (T--) solve();	
	return 0;
}