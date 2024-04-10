#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

void solve() {
	
	int n, k;
	cin >> n >> k;

	string s;
	cin >> s;

	vector<pair<int, int> > profit;
	int cur = 0;

	int block = 0;

	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == 'L') block++;
		else {
			if (i > 0 && s[i-1] == 'W') cur += 2;
			else cur += 1;

			if (block > 0) {
				int pos = i - block;
				if (pos == 0) profit.pb(mp(1, block));
				else profit.pb(mp(0, block));
			}

			block=0;

		}
	}

	if (k == 0) {
		cout << cur << '\n';
		return;
	}

	if (block == n) {
		block--;
		cur++;
		k--;
	}

	profit.pb(mp(1, block));

	//cout << profit.size() << endl;

	sort(all(profit));

	for (int i = 0; i < profit.size(); ++i) {
		for (int j = 0; j < profit[i].second - 1; ++j) {
			if (k) {
				cur += 2;
				k--;
			}
		}
		if (k && profit[i].second) {
			if (profit[i].first == 0) cur += 3;
			else cur += 2;

			k--;
		}
	}

	cout << cur << '\n';

}

int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	for (int i = 0; i < t; ++i) solve();

}