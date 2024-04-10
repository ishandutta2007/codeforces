//vsp
#include <bits/stdc++.h>
#define cat(x) cerr << #x << " = " << x << "\n";
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
#define FOR(i, n) for (int i = 0; i < n; i++)
#define sz(x) int(x.size())
using ll = long long;
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		vector<int> d[2];
		int p = 0;
		while (n) {
			d[p].push_back(n % 10);
			n /= 10;
			p ^= 1;
		}

		vector<ll> res;
		FOR(j, 2) {
			reverse(d[j].begin(), d[j].end());
			ll curr = 0;
			for (auto i : d[j])
				curr = 10 * curr + i;
			res.push_back(curr);
		}
			
		cout << (res[0] + 1) * (res[1] + 1) - 2 << '\n';
	}

	return 0;
}