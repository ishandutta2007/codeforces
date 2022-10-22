#include <bits/stdc++.h>
#define cat(x) cerr << #x << " = " << x << "\n";
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
typedef long long ll;
using namespace std;

const int N = 5000000;

int n, P, dp[N], s[N];

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> n >> P;
	dp[n] = 1;
	s[n] = 1;

	per(i, 1, n) {
		dp[i] = s[i + 1];
		rep(j, 2, n / i + 1) {
			dp[i] = (dp[i] + ll(s[i * j])) % P;
			int x = i * j + j;
			if (x < N)
				dp[i] = (dp[i] + P - s[x]) % P;
		}
		s[i] = (dp[i] + s[i + 1]) % P;
	}
	cout << dp[1] << '\n';
	return 0;
}