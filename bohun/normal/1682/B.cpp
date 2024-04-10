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
		int res = (1 << 30) - 1;
		rep(i, 0, n - 1) {
			int x;
			cin >> x;
			if (i != x)
				res &= x;
		}
		cout << res << endl;
	}

	return 0;
}