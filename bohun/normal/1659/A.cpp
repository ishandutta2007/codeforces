#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
#define cat(x) cout << #x << ": " << x << endl

using ll = long long;
using namespace std;

int T, n, r, b;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> T;
	while (T--) {
		cin >> n >> r >> b;
		rep(i, 0, b) {
			if (i > 0) {
				cout << "B";
			}
			rep(j, 1, r / (b + 1) + (i < (r % (b + 1))))
				cout << "R";
		}
		cout << "\n";
	}

	return 0;
}