/**
 * Sergey Kopeliovich (burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()

int solve() {
	int n;
	cin >> n;
	vector<tuple<int, int, int>> es;
	forn(i, n) {
		int l, r;
		cin >> l >> r;
		es.push_back({l, -1, i});
		es.push_back({r, 1, i});
	}
	sort(all(es));

	int cnt_l = 0, cnt_r = 0;
	vector<int> ans(n);
	for (auto [x, type, i] : es) {
		if (type == -1)
			ans[i] += cnt_r;
		else
			ans[i] += n - cnt_l;
		(type == -1 ? cnt_l : cnt_r) += 1;
	}
	return *min_element(all(ans));
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	int tn;
	cin >> tn;
	while (tn--)
		cout << solve() << "\n";
}