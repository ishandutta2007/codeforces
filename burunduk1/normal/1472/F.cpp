/**
 * Sergey Kopeliovich (burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	int tn;
	cin >> tn;
	while (tn--) {
		int n, m;
		cin >> n >> m;
		vector<pair<int, int>> a(m);
		for (auto &[c, r] : a) cin >> r >> c, r--, c--;
		a.push_back({n, 0});
		a.push_back({n, 1});
		sort(all(a));

		auto check = [&]() {
			vector<int> end(2);
			for (auto [c, r] : a) {
				auto fwd = [&](int &x, int y) {
					if (x < y)
						x += (y - x) / 2 * 2;
				};
				fwd(end[r ^ 1], end[r]);
				fwd(end[r], min(c, end[r ^ 1]));
				if ((end[r] - c) % 2 && end[0] == end[1])
					end[0]++, end[1]++;
				if ((end[r] - c) % 2)
					return 0;
				end[r] = c + 1;
			}
			return 1;
		};
		cout << (check() ? "YES\n" : "NO\n");
	}
}