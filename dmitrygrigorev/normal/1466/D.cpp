#include <bits/stdc++.h>
#define int long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;


void solve() {
	
	int n;
	cin >> n;

	vector<int> v(n);
	for (auto &x : v) cin >> x;

	vector<int> deg(n, -1);
	for (int i = 0; i < n-1; ++i) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		deg[u]++, deg[v]++;
	}	

	int sum = 0;
	for (auto x : v) sum += x;

	vector<int> t;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < deg[i]; ++j) {
			t.pb(v[i]);
		}
	} 

	sort(all(t), greater<int>());

	cout << sum << " ";
	for (int i = 0; i < n-2; ++i) {
		sum += t[i];
		cout << sum << " ";

	}

	cout << '\n';

}

main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	for (int i = 0; i <t ; ++i) solve();

}