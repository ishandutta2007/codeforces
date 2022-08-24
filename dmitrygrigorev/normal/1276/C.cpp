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
	freopen("I_input.txt", "r", stdin);
	//freopen("I_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> v(n);
	for (int i=0; i < n; ++i) cin >> v[i];

	map<int, int> kek;

	for (int i=0; i < n; ++i) {
		kek[v[i]]++;
	}


	vector<pair<int, int> > inside;
	for (auto it = kek.begin(); it != kek.end(); it++) {
		inside.push_back({(*it).second, (*it).first});
	}
	sort(inside.begin(), inside.end());
	int more = inside.size(), sum = 0;
	int ans = 0, x = 0, y = 0, u = 0;
	for (int i=1; i <= n; ++i) {
		while (u < inside.size() && inside[u].first == i) {
			sum += inside[u].first;
			more--;
			u++;
		}
		int cur = sum + i * more;
		int poss = cur / i;
		if (poss < i) continue;
		if (i*poss > ans) {
			ans = i*poss, x = i, y = poss;
		}
	}

	vector<int> take;
	for (int i=inside.size() - 1; i >= 0; i--) {
		for (int j=0; j < min(inside[i].first, x); ++j) {
			if (take.size() != ans) {
				take.push_back(inside[i].second);
			}
		}
	}

	cout << ans << "\n";
	cout << x << " " << y << "\n";
	vector<vector<int> > matrix(x);
	for (int i=0; i < x; ++i) {
		vector<int> t(y);
		matrix[i] = t;
	}

	int tet=0;

	for (int i=0; i < y; ++i) {
		int A = 0, B = i;
		for (int j=0; j < x; ++j) {
			matrix[A][B] = take[tet++];
			A = (A+1) % x;
			B = (B+1) % y;
		}
	}

	for (int i=0;i<x;++i) {
		for (int j=0;j<y;++j) cout << matrix[i][j] << " ";
		cout << "\n";
	}

}