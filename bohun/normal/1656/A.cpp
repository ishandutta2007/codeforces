#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= int(b); i++)
#define per(i, a, b) for (int i = b; i >= int(a); i--)
#define cat(x) cerr << #x << ": " << x << "\n";
#define sz(x) int(x.size())
using namespace std;
using ll = long long;

int n, a[100100];

void solve() {
	cin >> n;
	rep(i, 0, n - 1)
		cin >> a[i];
	cout << min_element(a, a + n) - a + 1 << " " << max_element(a, a + n) - a + 1 << "\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int T = 1;
	cin >> T;
	while (T--) solve();

    return 0;
}