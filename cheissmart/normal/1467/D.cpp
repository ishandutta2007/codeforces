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

const int INF = 1e9 + 7, N = 5005, M = 1e9 + 7;

int a[N], c[N];
int n, k, q;

int dp[N][N];

signed main()
{
	IO_OP;

	cin >> n >> k >> q;

	for(int i = 0; i < n; i++) dp[0][i] = 1;
	for(int i = 1; i <= k; i++) {
		for(int j = 0; j < n; j++) {
			if(j - 1 >= 0) dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]);
			dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % M;
		}
	}

	for(int i = 0; i < n; i++) {
		for(int j = 0; j <= k; j++)
			c[i] = (c[i] + (ll) dp[j][i] * dp[k - j][i] % M) % M;
	}

	for(int i = 0; i < n; i++) cin >> a[i];

	int ans = 0;
	for(int i = 0; i < n; i++)
		ans = (ans + (ll) a[i] * c[i] % M) % M;
	while(q--) {
		int i, x;
		cin >> i >> x;
		i--;
		ans = (ans - (ll) a[i] * c[i] % M + M) % M;
		a[i] = x;
		ans = (ans + (ll) a[i] * c[i] % M) % M;
		cout << ans << endl;
	}
}