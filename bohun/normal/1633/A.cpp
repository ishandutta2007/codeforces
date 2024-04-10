#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
#define sz(x) int(x.size())
#define cat(x) cerr << #x << " = " << x << endl

using ll = long long;
using namespace std;

void solve() {
	int n;
	cin >> n;
	if (n % 7 == 0) {
		cout << n << endl;
		return;
	}
	n -= n % 100 - n % 10;
	rep(i, 1, 7) {
		if ((n + i * 10) % 7 == 0) {
			cout << n + i * 10 << endl;
			return;
		}
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int T;
	cin >> T;
	while (T--) solve();
	return 0;
}