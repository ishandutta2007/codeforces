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
		int x, y, p, q;
		cin >> x >> p >> y >> q;

		double a = log(x) + p * log(10);
		double b = log(y) + q * log(10);
		double eps = 1e-9;

		if (a > b + eps) {
			cout << ">\n";
		}
		else if (b > a + eps) {
			cout << "<\n";
		}
		else {
			cout << "=\n";
		}
	}


	return 0;
}