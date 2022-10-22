#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
#define cat(x) cout << #x << ": " << x << endl

using namespace std;
using ll = long long;

const int N = 100100;
int n, k;
ll s[N];

void solve() {
	cin >> n >> k;
	rep(i, n - k + 1, n) cin >> s[i];

	rep(i, n - k + 1 + 1, n - 1) {
		if (s[i] - s[i - 1] > s[i + 1] - s[i]) {
			cout << "NO\n";
			return;
		}
	}

	ll sum = s[n - k + 1];
	int cnt = n - k + 1;
	ll x = sum / cnt;
	if (sum > 0 && sum % cnt != 0) {
		x++;
	}

	cout << ((k == 1 || x <= (s[n - k + 2] - s[n - k + 1])) ? "YES\n" : "NO\n");
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int T;
	cin >> T;
	while (T--) solve();

	return 0;
}