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
		int n;
		cin >> n;

		string s;
		cin >> s;

		int p = count(s.begin(), s.end(), '0') / 2;
		if (n % 2 == 1 && s[n / 2] == '0')
			cout << (p ? "ALICE\n" : "BOB\n");
		else
			cout << (p ? "BOB\n" : "DRAW\n");
	}
	return 0;
}