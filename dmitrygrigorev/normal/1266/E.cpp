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
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i=0; i < n; ++i) {
		cin >> arr[i];
	}

	int ans = 0;
	for (int i=0;i<n;++i) ans += arr[i];
	map<pair<int, int>, int> kek;
	
	int q;
	cin >> q;
	for (int i=0;i<q;++i) {
		int u, v, w;
		cin >> u >> v >> w;
		u--, w--;
		if (!kek.count({u, v})) {
			if (w!=-1) {
				arr[w]--;
				if (arr[w] >= 0) ans--;
				kek[{u, v}] = w;
			}
		}
		else{
			int old = kek[{u, v}];
			kek.erase(kek.find({u, v}));
			arr[old]++;
			if (arr[old] > 0) ans++;

			if (w != -1) {
				arr[w]--;
				if (arr[w] >= 0) ans--;
				kek[{u, v}] = w;
			}
		}
		cout << ans << "\n";
	}



}