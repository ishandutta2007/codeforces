#include <bits/stdc++.h>
#define int long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

bool cmp(vector<int> &a, vector<int> &b) {
	return (a[0] > b[0]);
}

main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int ans = n*n;


	vector<vector<int> > v;

	for (int i = 0; i < n; ++i) {
		int t;
		cin >> t;
		vector<int> kek(t);

		for (int i = 0; i < t; ++i) cin >> kek[i];
		vector<int> tet = kek;
		sort(tet.begin(), tet.end(), greater<int>());
		if (tet==kek) v.push_back(kek);
	}

	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < v.size(); ++i) {
		int x = v[i].back();
		int L = 0, R = v.size() + 1;
		while (R-L>1){
			int M = (L+R)/2;
			int index = v.size() - M;
			if (v[index][0] <= x) L = M;
			else R = M;
		}
		ans -= L;
	}
	cout << ans;

}