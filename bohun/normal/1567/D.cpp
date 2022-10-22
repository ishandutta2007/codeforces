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
		int s, n;
		cin >> s >> n;

		vector<int> res(n);
		int p = 0, zeros = n;

		per(j, 0, 10) {
			int x = pow(10, j);
			while (max(0, zeros - 1) <= s - x) {
				zeros = max(0, zeros - 1);
				res[p] += x;
				s -= x;
				p = (p + 1) % n;
			}
		}

		for (auto x : res)
			cout << x << ' ';
		cout << '\n';
	}
	return 0;
}