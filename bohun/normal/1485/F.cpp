#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define per(i, a, b) for (int i = b; i >= a; --i)
#define all(x) x.begin(), x.end()
 
using ll = long long;
using namespace std;

const int N = 1 << 20;
const int P = 1e9 + 7;

int n;
ll b[N], dp[N][2];

void solve() {
	scanf("%d", &n);
	rep(i, 1, n) scanf("%lld", b + i);
	dp[0][1] = 1;
	map<ll, ll> M;
	ll sum = 0;
	rep(i, 1, n) {
		ll s = b[i - 1] - sum;
		M[s] = (M[s] + dp[i - 1][1]) % P;
		dp[i][0] = dp[i][1] = (dp[i - 1][0] + dp[i - 1][1]) % P;
		dp[i][1] = (dp[i][1] - M[-sum] + P) % P;
		sum += b[i];
	}
	printf("%lld\n", (dp[n][0] + dp[n][1]) % P);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
	return 0;
}