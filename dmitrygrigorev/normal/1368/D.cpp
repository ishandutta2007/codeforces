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
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> v(20);

	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;

		for (int j = 0; j < 20; ++j) {
			if ((1LL<<j)&x) v[j]++;
		}
	}

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		int kek = 0;
		for (int j = 0; j < 20; ++j) {
			if (v[j]) {
				kek += (1LL<<j);
				v[j]--;
			}
		}

		ans += kek*kek;
	}

	cout << ans;

}