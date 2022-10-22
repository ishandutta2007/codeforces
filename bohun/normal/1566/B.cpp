//vsp
#include <bits/stdc++.h>
#define cat(x) cerr << #x << " = " << x << "\n";
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define per(i, a, b) for (int i = (b) - 1; (a) <= i; i--)
#define FOR(i, n) for (int i = 0; i < n; i++)
#define sz(x) int(x.size())
using ll = long long;
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;

		int n = s.length();
		int x = 0;
		FOR(i, n - 1)
			x += s[i] != s[i + 1];

		if (x == 0 && s[0] == '1')
			cout << 0 << '\n';
		else if (x <= 1 || (x == 2 && s[0] == '1'))
			cout << 1 << '\n';
		else
			cout << 2 << '\n';
	}
	return 0;
}