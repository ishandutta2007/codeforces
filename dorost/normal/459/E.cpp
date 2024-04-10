/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 301234;
vector <pair <pair <int, int>, int>> a;
int dp[N], dpt[N];

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		u--, v--;
		a.push_back({{w, u}, v});
	}
	sort(a.begin(), a.end());
	vector <int> v;
	for (int i = 0; i < m; i++) {
		int x = a[i].F.F;
		int y = a[i].F.S;
		int z = a[i].S;
		dpt[z] = max(dpt[z], dp[y] + 1);
		v.push_back(z);
		if (i == m - 1 || (a[i].F.F != a[i + 1].F.F)) {
			for (auto xx : v) {
				dp[xx] = dpt[xx];
			}
			v.clear();
		}
	}
	cout << *max_element(dp, dp + N);
}