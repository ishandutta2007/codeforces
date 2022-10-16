// https://codeforces.com/blog/entry/85707?#comment-734342
#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << "Line(" << __LINE__ << ") -> " << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;

int solve(int n, int x, int y) {
	if(int g = gcd(x, y); g != 1)
		return solve(n / g + 1, x / g, y / g) * (n % g) + solve(n / g, x / g, y / g) * (g - n % g);

	assert(gcd(x, y) == 1);
	int p = (x + y);
	vi w(p, n / p);
	for(int i = 0; i < p; i++) {
		int v = i * x % p;
		if(v < n % p) w[i]++;
	}

	int ans = -INF;

	for(int v0 = 0; v0 < 2; v0++) {
		// v0: {0 : don't choose the last, 1 : choose the last}
		array<int, 2> dp = {-INF, -INF};
		dp[v0] = 0;
		for(int v:w) dp = (array<int, 2>) {max(dp[0], dp[1]), dp[0] + v};
		ans = max(ans, dp[v0]);
	}
	return ans;
}

signed main()
{
	IO_OP;
	
	int n, x, y;
	cin >> n >> x >> y;
	cout << solve(n, x, y) << '\n';	

}