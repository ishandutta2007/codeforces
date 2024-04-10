#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
#define sz(x) int(x.size())
#define cat(x) cerr << #x << " = " << x << endl

using ll = long long;
using namespace std;

void solve() {
	string s;
	cin >> s;
	int cnt[2]{};
	for (auto x : s) cnt[x - '0']++;
	if (cnt[0] != cnt[1])
		cout << min(cnt[0], cnt[1]) << endl;
	else
		cout << cnt[0] - 1 << endl;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int T;
	cin >> T;
	while (T--) solve();
	return 0;
}