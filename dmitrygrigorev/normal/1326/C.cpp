#include <bits/stdc++.h>
#define int long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int mod = 998244353;

main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	vector<int> v(n);

	for (int i = 0; i < n; ++i) cin >> v[i];

	int ans = 0;
	for (int i = 0; i < k; ++i) ans += n-i;
	cout << ans << " ";

	vector<int> pos(k);
	int u = 0;
	for (int i = 0; i < n; ++i) {
		if (v[i] > n - k) pos[u++] = i;
	}

	int res = 1;
	for (int i = 0; i+1 < k; ++i) {
		int W = pos[i+1] - pos[i];
		res = (res *W) % mod;
	}
	cout << res;

}