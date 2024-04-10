//vsp
#include <bits/stdc++.h>
#define cat(x) cerr << #x << " = " << x << "\n";
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define per(i, a, b) for (int i = (b) - 1; (a) <= i; i--)
#define FOR(i, n) for (int i = 0; i < n; i++)
#define sz(x) int(x.size())
using ll = long long;
using namespace std;

const int N = 100100;
int n, p[N], dp[N], children[N], cnt[N];

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> n;
	rep(i, 2, n + 1) {
		cin >> p[i];
		children[p[i]]++;
	}

	per(i, 1, n + 1) {
		if (!children[i])
			dp[i]++;
		cnt[dp[i]]++;
		dp[p[i]] += dp[i];
	}

	rep(i, 1, n + 1)
		cnt[i] += cnt[i - 1];

	rep(i, 1, n + 1)
		cout << (lower_bound(cnt + 1, cnt + n + 1, i) - cnt) << ' ';

	return 0;
}