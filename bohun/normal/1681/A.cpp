#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
#define cat(x) cerr << #x << ": " << x << endl
using ll = long long;
using namespace std;

void solve() {
	int n;
	cin >> n;
	int a = 0, b = 0;
	rep(i, 1, n) {
		int x; cin >> x;
		a = max(a, x);
	}
	cin >> n;
	rep(i, 1, n) {
		int x; cin >> x;
		b = max(b, x);
	}
	cout << (a >= b ? "Alice\n" : "Bob\n");
	cout << (a <= b ? "Bob\n" : "Alice\n");
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int T;
	cin >> T;
	while (T--) solve();

	return 0;
}