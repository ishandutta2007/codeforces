#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= int(b); i++)
#define per(i, a, b) for (int i = b; i >= int(a); i--)
#define cat(x) cerr << #x << ": " << x << "\n";
#define sz(x) int(x.size())
using namespace std;
using ll = long long;

ll n;

void solve() {
	cin >> n;
	int cnt = 1;
	while (n % 2 == 0) {
		cnt++;
		n /= 2;
	}
	if ((n >= (1LL << cnt) + 1)) {
		cout << (1LL << cnt) << "\n";
	}
	else if (n > 1 && ((1LL << cnt) >= n + 1)) {
		cout << n << "\n";
	}
	else {
		cout << "-1\n";
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int T = 1;
	cin >> T;
	while (T--) solve();

    return 0;
}