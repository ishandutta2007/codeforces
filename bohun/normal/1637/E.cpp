#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
#define cat(x) cerr << #x << " = " << x << endl

using ll = long long;
using namespace std;

const int N = 500500;
int t, n, m;
map<pair<int, int>, int> bad;
map<int, int> cnt;
vector<int> v[N];

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> t;
	while (t--) {
		cnt.clear();
		bad.clear();
		cin >> n >> m;
		rep(i, 1, n) v[i].clear();
		rep(i, 1, n) {
			int x;
			cin >> x;
			cnt[x]++;
		}
		rep(i, 1, m) {
			int x, y;
			cin >> x >> y;
			bad[{x, y}] = 1;
			bad[{y, x}] = 1;
		}
		for (auto [x, y] : cnt)
			v[y].push_back(x);

		ll res = 0;
		rep(i, 1, n) {
			if (v[i].empty())
				continue;
			rep(j, 1, n) {
				if (v[j].empty())
					continue;
				for (auto x : v[i]) {
					int z = int(v[j].size()) - 1;
					while (z >= 0 && (x == v[j][z] || bad.count(make_pair(x, v[j][z]))))
						z--;
					if (z >= 0) {
						res = max(res, ll(i + j) * (x + v[j][z]));
					}
				}
			}
		}
		cout << res << "\n";
	}

	return 0;
}