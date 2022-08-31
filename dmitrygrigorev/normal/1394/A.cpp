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

	int n, d, m;

	cin >> n >> d >> m;

	vector<int> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];

	sort(all(a));

	vector<int> pref;
	pref.pb(0);

	for (int i = 0; i < n; ++i) {
		pref.pb(pref[i] + a[i]);
	}

	int have = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i] <= m) have++;
	}

	int ans = 0;
	for (int take = 0; take <= have; ++take) {
		int rem = n - take;
		int can = (rem + d) / (d+1);

		can = min(can, n - have);
		ans = max(ans, (pref[have] - pref[have - take]) + (pref[n] - pref[n-can]));

	}

	cout << ans;

}