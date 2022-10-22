#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; a <= i; i--)
#define cat(x) cerr << #x << " = " << x << '\n';
using ll = long long;
using namespace std;
 
int main() {
	cin.tie(0)->sync_with_stdio(0);
 
	int t;
	cin >> t; 
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<int> x(n);
		for (int i = 0; i < n; i++)
			cin >> x[i];
		vector<string> s(n);
		for (int i = 0; i < n; i++)
			cin >> s[i];
 
		ll best = 0;
		vector<int> res(m);
		for (int mask = 0; mask < (1 << n); mask++) {
			ll cur = 0;
			vector<int> coef(m);
			for (int i = 0; i < n; i++) {
				cur += (mask >> i & 1) ? -x[i] : x[i];
				for (int j = 0; j < m; j++) {
					if (s[i][j] == '1')
						coef[j] += ((mask >> i & 1) ? 1 : -1);
				}
			}
			vector<int> ord(m);
			iota(ord.begin(), ord.end(), 0);
			sort(ord.begin(), ord.end(), [&](int a, int b) { return coef[a] < coef[b]; });
			vector<int> v(m);
			for (int i = 0; i < m; i++) {
				cur += (i + 1) * coef[ord[i]];
				v[ord[i]] = i;
			}
			if (best <= cur) {
				best = cur;
				res = v;
			}
		}
 
		for (auto x : res)
			cout << x + 1 << ' ';
		cout << '\n';
	}
	return 0;
}