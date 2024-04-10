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
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<pair<int, int> > v;
	for (int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		v.push_back({2*x, 2*y});
	}

	sort(v.begin(), v.end());
	int a = (v[0].first + v.back().first) / 2;
	int b = (v[0].second + v.back().second) / 2;

	set<pair<int, int> > tet;
	for (int i = 0; i < n; ++i) {
		int x = v[i].first, y = v[i].second;
		int c = 2*a - x, d = 2*b - y;
		if (tet.count({c, d})) tet.erase(tet.find({c, d}));
		else tet.insert({x, y});
	}

	if (!tet.size()) cout << "YES";
	else cout << "NO";

}