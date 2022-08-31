#include <bits/stdc++.h>
#define int long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

int intersect(int a, int b, int c, int d) {
	a = max(a, c);
	b = min(b, d);
	if (a>b) return -1;
	return b;
}

main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	for (int i = 0; i < t; ++i) {
		int a, b, m;
		cin >> a >> b >> m;
		if (a==b) {
			cout << "1 " << a << endl;
			continue;
		}
		vector<pair<int, int> > v;
		v.push_back({a, a});

		bool decl = false;

		int L = b-m, R = b-1;

		while (true) {
			if (intersect(L, R, v.back().first, v.back().second) != -1) break;
			if (R < v.back().first) {
				cout << "-1\n";
				decl = true;
				break;
			}
			v.push_back({v.back().first * 2 + 1, v.back().second * 2 + m});
		}

		if (decl) continue;
		int sum = intersect(L, R, v.back().first, v.back().second);
		vector<int> sums;

		sums.push_back(sum);
		for (int j = ((int) v.size()) - 2; j >= 0; j--) {
			int last = sums.back();
			int left = v[j].first, right = v[j].second;

			int cand;
			if (last % 2 == 0) {
				cand = (last-2)/2;
			}
			else cand = (last - 1)/2;

			if (cand > right) {
				int delta = cand-right;
				cand -= delta;
			}

			sums.push_back(cand);
		}

		reverse(sums.begin(), sums.end());
		cout << sums.size() + 1 << " ";
		cout << a << " ";
		for (int j = 1; j < sums.size(); ++j) {
			cout << sums[j] - sums[j-1] << " ";
		}
		cout << b << "\n";


	}

}