#include <bits/stdc++.h>
#define cat(x) cerr << #x << " = " << x << "\n";
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
typedef long long ll;
using namespace std;

const int N = 200200;

int n, m, k, p[N];

int find(int x) {
	return x == p[x] ? x : p[x] = find(p[x]);
}

void solve() {
	cin >> n >> m >> k;

	vector<tuple<long long, int, int>> e;
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		a--; b--;
		e.push_back({c, a, b});
	}

	iota(p, p + n, 0);
	sort(e.begin(), e.end());
	
	int comp = n;
	long long res = 1e18, sum = 0;
	for (auto t : e) {
		auto [c, a, b] = t;
		if (find(a) != find(b)) {
			p[find(a)] = find(b);
			comp--;
			sum += max(0ll, c - k);
		}

		if (comp == 1) {
			if (c <= k)
				res = min(res, k - c);
		}
	}

	if (sum == 0) 
		sum = get<0>(*lower_bound(e.begin(), e.end(), make_tuple(k, 0, 0))) - k;

	if (get<0>(e.back()) > k)
		res = min(res, sum);

	cout << res << "\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}