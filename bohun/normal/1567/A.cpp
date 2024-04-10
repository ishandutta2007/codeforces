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

		string s;
		cin >> s;

		for (auto x : s) {
			if (x == 'U')
				cout << 'D';
			else if (x == 'D')
				cout << 'U';
			else
				cout << x;
		}
		cout << '\n';
	}

	return 0;
}