#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
#define cat(x) cerr << #x << ": " << x << endl
using ll = long long;
using namespace std;

int n, a[200200];

void solve() {
	cin >> n;
	rep(i, 0, n - 1) cin >> a[i];
	ll m, s = 0;
	cin >> m;
	rep(i, 1, m) {
		int x; cin >> x;
		s += x;
	}
	cout << a[s % n] << endl;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int T;
	cin >> T;
	while (T--) solve();

	return 0;
}