#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
#define cat(x) cerr << #x << " = " << x << endl

using ll = long long;
using namespace std;

ll t, n, x, y;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> t;
	while (t--) {
		cin >> n >> x >> y;
		while (n--) {
			int z;
			cin >> z;
			x ^= z;
		}
		cout << (x % 2 == y % 2 ? "Alice\n" : "Bob\n");
	}

	return 0;
}