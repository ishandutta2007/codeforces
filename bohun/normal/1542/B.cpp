//vsp
#include <bits/stdc++.h>
#define cat(x) cerr << #x << " = " << x << "\n";
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define per(i, a, b) for (int i = (b) - 1; (a) <= i; i--)
#define FOR(i, n) for (int i = 0; i < n; i++)
#define sz(x) int(x.size())
using ll = long long;
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t;
	cin >> t;
	while (t--) {

		int n, a, b;
		cin >> n >> a >> b;

		bool res = 0;
		ll x = 1;
		while (x <= n) {
			res |= (n - x) % b == 0;
			x *= a;
			if (a == 1)
				break;
		}

		cout << (res ? "Yes\n" : "No\n");
	}

	return 0;
}