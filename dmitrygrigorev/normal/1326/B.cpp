#include <bits/stdc++.h>
#define int long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; ++i) cin >> v[i];

	vector<int> ans(n);

	int mx = 0;
	for (int i = 0; i < n; ++i) {
		ans[i] = mx + v[i];
		mx = max(mx, ans[i]);
	}

	for (int i = 0; i < n; ++i) cout << ans[i] << " ";

}