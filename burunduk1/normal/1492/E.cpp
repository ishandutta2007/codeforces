/**
 * Sergey Kopeliovich (burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);

	int h, w;
	while (cin >> h >> w) {
		vector<vector<int>> a(h, vector<int>(w));
		forn(i, h)
			forn(j, w)
				cin >> a[i][j];

		vector<int> ans;
		function<void(vector<int>, int)> go = [&](vector<int> v, int dep) {
			if (dep >= 3)
				return;
			vector<int> pos;
			forn(i, h) {
				pos.clear();
				forn(j, w)
					if (a[i][j] != v[j])
						pos.push_back(j);
				if (pos.size() >= 3U) {
					if (pos.size() < 5U)
						for (int p : pos) {
							int tmp = v[p];
							v[p] = a[i][p];
							go(v, dep + 1);
							v[p] = tmp;
						}
					return;
				}
			}
			ans = v;
		};
		go(a[0], 0);
		if (ans.size()) {
			cout << "Yes\n";
			for (int x : ans)
				cout << x << " ";
			cout << endl;
		} else {
			cout << "No\n";
		}
	}
}
//     1111111111111
//     1111111112222
// ans 1111111111122