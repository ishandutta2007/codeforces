#include <bits/stdc++.h>
#define cat(x) cerr << #x << " = " << x << "\n";
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
typedef long long ll;
using namespace std;

int ask(string s, int x, int y) {
	cout << s << ' ' << x << ' ' << y << endl;
	cin >> x;
	return x;
}

const int N = 1e4 + 50;
int And[N], Or[N], n, O, a[N], k;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> n >> k;
	rep(i, 2, n + 1) {
		And[i] = ask("and", 1, i);
		Or[i] = ask("or", 1, i);
	}
	O = ask("or", 2, 3);

	rep(b, 0, 30) {

		int type = 0;
		rep(i, 2, n + 1) {
			if (And[i] >> b & 1)
				type = 1;
			if (!(Or[i] >> b & 1))
				type = 2;
		}

		int p = 1 << b;
		if (type == 1) {
			rep(i, 2, n + 1)
				a[i] += p * (And[i] >> b & 1);
			a[1] += p;
			continue;
		}
		if (type == 2) {
			rep(i, 2, n + 1)
				a[i] += p * (Or[i] >> b & 1);
			continue;
		}
		int s = 0;
		rep(i, 2, n + 1)
			s += (Or[i] >> b & 1);
		if (s == 0)
			continue;
		if (s < n - 1) {
			rep(i, 2, n + 1)
				a[i] += p * (Or[i] >> b & 1);
			continue;
		}
		if (O >> b & 1) {
			rep(i, 2, n + 1)
				a[i] += p;
		}
		else
			a[1] += p;
	}
	sort(a + 1, a + n + 1);
	cout << "finish " << a[k] << '\n';

	return 0;
}