#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

void solve() {

	int n, m, k;
	cin >> n >> m >> k;
	k = min(k, m-1);

	vector<int> v(n);

	for (int i = 0; i < n; ++i) cin >> v[i];

	int ans = -2e9;

	for (int take=0; take <= k; ++take) {
		int here = 2e9;
		for (int i = 0; i <= m-1-k; ++i) {
			int left = i+take;
			int right = m-1-left;
			here = min(here, max(v[left], v[n-right-1]));
		}
		ans = max(ans, here);
	}

	cout << ans << "\n";

}

int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	for (int i = 0; i < t; ++i) solve();

}