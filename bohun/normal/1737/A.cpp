#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
#define cat(x) cout << #x << ": " << x << endl

using namespace std;
using ll = long long;

int n, k;
string s;

void solve() {
	cin >> n >> k >> s;
	int cnt[26] = {};
	for (auto c : s) {
		cnt[c - 'a']++;
	}

	rep(i, 1, k) {
		int c = 0;
		while (cnt[c] && c < n / k) {
			cnt[c++]--;
		}
		cout << (char) ('a' + c);
	}
	cout << "\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int T = 1;
	cin >> T;
	while (T--) solve();

	return 0;
}