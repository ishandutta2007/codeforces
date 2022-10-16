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

const int INF = 1e9 + 7, N = 3003;

int a[N], dp[N][N];

signed main()
{
	IO_OP;

	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		for(int i = 0; i < n; i++) {
			cin >> a[i];
			a[i] = min(a[i], n - 1 - i);
		}
		for(int i = 0; i < n; i++)
			dp[0][i] = 0;
		for(int i = 1; i < n; i++) {
			for(int j = 0; j < n; j++) dp[i][j] = INF;
			int cnt = 0;
			for(int j = i - 1; j >= 0; j--) {
				if(j + a[j] >= i) {
					dp[i][j + a[j]] = min(dp[i][j + a[j]], dp[j][i - 1] + cnt);
					cnt++;
				}
			}
			for(int j = 1; j < n; j++) dp[i][j] = min(dp[i][j], dp[i][j - 1]);
		}
		cout << dp[n - 1][n - 1] << endl;
	}
	
}