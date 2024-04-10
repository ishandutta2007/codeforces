#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
#define cat(x) cerr << #x << ": " << x << endl
using ll = long long;
using namespace std;

int T, n;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> T;
	while (T--) {
		cin >> n;
		map<int, int> c;
		rep(i, 1, n) {
			int x;
			cin >> x;
			c[x]++;
		}

		int a = 0, b = 0;
		for (auto [x, y] : c) {
			if (y > 1) {
				a++;
			}
			else {
				b++;
			}
		}
		if (b > 0) {
			a++;
			b--;
		}
		cout << a + b / 2 << endl;
	}

	return 0;
}