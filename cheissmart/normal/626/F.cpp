#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 202, K = 1003, M = 1e9 + 7;

int dp[N][N][K];
int a[N];

void add(int &a, int b) {
	a += b;
	if(a >= M) a -= M;
}

signed main()
{
	IO_OP;
	
	int n, k;
	cin >> n >> k;
	for(int i = 0; i < n; i++) cin >> a[i];
	sort(a, a+n);
	dp[0][1][0] = dp[0][0][0] = 1;
	for(int i = 0; i < n - 1; i++) {
		for(int j = 0; j <= n; j++) {
			for(int kk = 0; kk <= k; kk++) {
				if(dp[i][j][kk] == 0) continue;
				int val = kk + (a[i + 1] - a[i]) * j;
				if(val > k) continue;
				// create and close a new set
				add(dp[i + 1][j][val], dp[i][j][kk]);
				// create new open set
				add(dp[i + 1][j + 1][val], dp[i][j][kk]);
				// close old open set
				if(j > 0) {
					add(dp[i + 1][j - 1][val], (ll)j * dp[i][j][kk] % M);
				}
				// join old open set
				if(j > 0) {
					add(dp[i + 1][j][val], (ll)j * dp[i][j][kk] % M);
				}
			}
		}
	}
	int ans = 0;
	for(int i = 0; i <= k; i++)
		add(ans, dp[n-1][0][i]);
	cout << ans << endl;
}