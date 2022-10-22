#include <bits/stdc++.h>
#define cat(x) cerr << #x << " = " << x << "\n";
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
typedef long long ll;
using namespace std;

int t, c[3];

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> t;
	while (t--) {
		cin >> c[0] >> c[1] >> c[2];

		rep(i, 0, 5) {
			int a;
			cin >> a;
			if (i < 3)
				c[i] -= a;
			else {
				int id = i - 3;
				int b = max(0, min(c[id], a));
				c[id] -= b;
				c[2] -= a - b;
			}
		}

		cout << (*min_element(c, c + 3) >= 0 ? "YES\n" : "NO\n");
	}

	return 0;
}