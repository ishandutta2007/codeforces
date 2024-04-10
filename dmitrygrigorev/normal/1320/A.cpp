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
	//freopen("F_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; ++i) cin >> v[i];

	map<int, int> sum;

	for (int i = 0; i < n; ++i) {
		sum[v[i] - i] += v[i];
	}

	int ans = 0;
	for (auto it = sum.begin(); it != sum.end(); it++) {
		ans = max(ans, (*it).second);
	}

	cout << ans;

}