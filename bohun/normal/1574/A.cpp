//vsp
#include<bits/stdc++.h>
#define cat(x) cerr << #x << " = " << x << "\n";
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define per(i, a, b) for (int i = (b) - 1; (a) <= i; i--)
#define FOR(i, n) for (int i = 0; i < (n); i++)
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
		rep(i, 1, n + 1) {
			FOR(q, i) cout << '(';
			FOR(q, i) cout << ')';
			FOR(q, n - i) cout << '(';
			FOR(q, n - i) cout << ')';
			cout << '\n';
		}
	}

	return 0;
}