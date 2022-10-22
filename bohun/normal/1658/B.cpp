#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= int(b); i++)
#define per(i, a, b) for (int i = b; i >= int(a); i--)
#define cat(x) cerr << #x << ": " << x << endl
#define sz(x) int(x.size())
using namespace std;
using ll = long long;

const int P = 998244353;
int n;

void solve() {
	cin >> n;
	int res = 1;
	rep(i, 1, n / 2)
		res = 1ll * res * i % P;
	if (n % 2) res = 0;
	cout << 1ll * res * res % P << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T = 1;
	cin >> T;
	while (T--) solve();
	return 0;
}