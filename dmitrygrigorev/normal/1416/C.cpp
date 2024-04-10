#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

struct Element {
	int pref;
	int cur;
	int index;
};

bool cmp(Element &a, Element &b) {
	if (a.pref != b.pref) return (a.pref < b.pref);
	return (a.index < b.index);
}

void solve() {
	int n;
	cin >> n;

	vector<int> v(n);
	
	for (auto &x : v) cin >> x;

	ll ans = 0;
	int opt = 0;

	for (int i = 29; i >= 0; i--) {
		vector<Element> val;
		for (int j = 0; j < n; ++j) {
			int Q = v[j] & (1<<i);

			val.pb({(v[j] >> (i+1)), (Q>0), j});
		}

		sort(all(val), cmp);

		int start = 0;
		ll dop_quo = 0, dop_ch = 0;

		while (start < n) {
			int finish = start;
			while (finish < n && val[finish].pref == val[start].pref) finish++;

			int zero = 0, one = 0;
			for (int i = start; i < finish; ++i) {
				if (val[i].cur == 0) {
					dop_quo += one;
					zero++;
				}
				else {
					dop_ch += zero;
					one++;
				}
			}

			//cout << start << " " << finish << " " << zero << " " << one << endl;

			start = finish;

		}

		if (dop_quo <= dop_ch) ans += dop_quo;
		else {
			ans += dop_ch;
			opt += (1<<i);
		}

	}

	cout << ans << " " << opt << endl;

}

main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t = 1;

	for (int i = 0; i < t; ++i) solve();

}