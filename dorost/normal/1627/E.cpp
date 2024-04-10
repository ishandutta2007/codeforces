/* 	* In the name of GOD  */

#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 100010;
const ll INF = 1000LL * 1000LL * 1000LL * 1000LL * 1000LL * 100LL;
ll dp[2 * N];
int x[N], a[N], b[N], c[N], d[N], h[N];
vector <pair <int, int>> vo[2 * N];

inline void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	vector <pair <int, int>> v;
	v.push_back(make_pair(1, 1));
	v.push_back(make_pair(n, m));
	for (int i = 0; i < n; i++)
		cin >> x[i];
	for (int i = 0; i < k; i++) {
		cin >> a[i] >> b[i] >> c[i] >> d[i] >> h[i];
		v.push_back(make_pair(a[i], b[i]));
		v.push_back(make_pair(c[i], d[i]));
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for (int i = 0; i < v.size(); i++) {
		vo[i].clear();
		dp[i] = 0;
	}
	for (int i = 0; i < k; i++) {
		int in1 = lower_bound(v.begin(), v.end(), make_pair(a[i], b[i])) - v.begin();
		int in2 = lower_bound(v.begin(), v.end(), make_pair(c[i], d[i])) - v.begin();
		assert(in1 != (int)v.size());
		assert(in2 != (int)v.size());
		assert(v[in1].F == a[i]);
		assert(v[in1].S == b[i]);
		assert(v[in2].F == c[i]);
		assert(v[in2].S == d[i]);
		vo[in2].push_back(make_pair(in1, h[i]));
	}
	dp[0] = 0;
	int lst = 0;
	for (int i = 1; i < v.size(); i++) {
		dp[i] = INF;
		for (auto [x, h] : vo[i]) {
		    if (dp[x] == INF)
		        continue;
			dp[i] = min(dp[i], dp[x] - h);
		}
		if (v[i - 1].F == v[i].F) {
			dp[i] = min(dp[i], ((ll)(v[i].S - v[i - 1].S) * (ll)x[v[i].F - 1]) + dp[i - 1]);
		}
		if (i == (int)v.size() - 1 || v[i].F != v[i + 1].F) {
			for (int j = i - 1; j > lst; j--) {
				dp[j] = min(dp[j], dp[j + 1] + (ll)((v[j + 1].S - v[j].S) * (ll)x[v[j].F - 1]));
				assert(v[j].F == v[j + 1].F);
			}
			lst = i;
		}
	}
	if (dp[(int)v.size() - 1] == INF)
		cout << "NO ESCAPE\n";
	else
		cout << dp[(int)v.size() - 1] << '\n';
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}