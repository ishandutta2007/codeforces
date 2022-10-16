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

const int INF = 1e9 + 7, N = 3003;

int a[N], dp[N][N];

void solve() {
	int n;
	cin >> n;
	vi v;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		v.PB(a[i]);
	}
	sort(ALL(v));
	for(int i = 0; i < n; i++) {
		a[i] = lower_bound(ALL(v), a[i]) - v.begin();
	}
	int mx = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			dp[i][j] = 0;
			if(i) dp[i][j] = dp[i-1][j];
			if(a[i] == j) {
				dp[i][j] = max(dp[i][j], 1);
				if(i) {
					dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
				}
			}
			mx = max(mx, dp[i][j]);
		}
	}
	cout << n - mx << endl;
}

signed main()
{
	IO_OP;
	
	int t;
	cin >> t;
	while(t--) solve();
	
}