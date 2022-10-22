#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= int(b); i++)
#define per(i, a, b) for (int i = b; i >= int(a); i--)
#define cat(x) cerr << #x << ": " << x << endl
#define sz(x) int(x.size())
using namespace std;
using ll = long long;

int n;
string s;

void solve() {
	cin >> n >> s;
	int res = 0;
	rep(i, 0, n - 2)
		if (s[i] == '0' && s[i + 1] == '0')
			res += 2;
	rep(i, 1, n - 2)
		if (s[i] == '1' && s[i - 1] == '0' && s[i + 1] == '0')
			res += 1;
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T = 1;
	cin >> T;
	while (T--) solve();
	return 0;
}