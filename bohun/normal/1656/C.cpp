#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= int(b); i++)
#define per(i, a, b) for (int i = b; i >= int(a); i--)
#define cat(x) cerr << #x << ": " << x << "\n";
#define sz(x) int(x.size())
using namespace std;
using ll = long long;

int n, a[200200];

void solve() {
	cin >> n;
	int cnt = 0;
	rep(i, 1, n) cin >> a[i], cnt += a[i] == 1;
	if (cnt == 0) {
		cout << "YES\n";
		return;
	}
	sort(a + 1, a + n + 1);
	rep(i, 1, n - 1) 
		if (a[i] + 1 == a[i + 1]) {
			cout << "NO\n";
			return;
		}
	cout << "YES\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int T = 1;
	cin >> T;
	while (T--) solve();

    return 0;
}