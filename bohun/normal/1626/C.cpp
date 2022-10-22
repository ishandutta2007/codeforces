#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
#define cat(x) cerr << #x << " = " << x << "\n";
#define sz(x) int(x.size())
using ll = long long;
using namespace std;

const int N = 105;
int t, n, k[N], h[N];

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> t;
	while (t--) {
		cin >> n;
		rep(i, 1, n) cin >> k[i];
		rep(i, 1, n) cin >> h[i];
		vector<pair<int, int>> v;
		rep(i, 1, n) v.push_back({k[i] - h[i] + 1, k[i]});
		sort(v.begin(), v.end());
		ll res = 0;
		for (int i = 0; i < n; ) {
			int rmax = v[i].second;
			int j = i;
			while (j < n && v[j].first <= rmax) {
				rmax = max(rmax, v[j++].second);
			}
			int cnt = rmax - v[i].first + 1;
			res += 1ll * cnt * (cnt + 1) / 2;
			i = j;
		}
		cout << res << endl;
	}

	return 0;
}