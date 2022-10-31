#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < n; i++)
#define sz(a) (int)a.size()
#define re return
#define fi first
#define se second
#define mp(a, b) make_pair(a, b)

typedef long long ll;
typedef vector<int> vi;
typedef long double ld;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n;
ll dp[1000 * 1000 * 10 + 100], x, y;
int main() {
	iostream::sync_with_stdio(0), cin.tie(0);
	//freopen("a.in", "r", stdin);
	//freopen(".out", "w", stdout);
	cin >> n >> x >> y;
	dp[1] = x;
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + x;
		if (i % 2 == 0)
			dp[i] = min(dp[i], dp[i / 2] + y);
		if (i % 2)
			dp[i] = min(dp[i], min(dp[(i - 1) / 2], dp[(i + 1) / 2]) + x + y);
	}
	cout << dp[n];
	re 0;
}