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
		int t[3]; 
		cin >> t[0] >> t[1] >> t[2];
		sort(t, t + 3);
		int m;
		cin >> m;
		cout << (t[2] - 1 - t[0] - t[1] <= m && m <= t[0] + t[1] + t[2] - 3 ? "YES\n" : "NO\n");
	}

	return 0;
}