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

const int INF = 1e9 + 7, N = 2e5 + 7, M = 998244353;

int a[N], b[N], dp[N], cnt[N];

signed main()
{
	IO_OP;
	
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++) cin >> a[i];	
	for(int i = 0; i < m; i++) cin >> b[i];
	int mn = INF;
	for(int i = n - 1; i >= 0; i--) {
		mn = min(mn, a[i]);
		int j = lower_bound(b, b+m, mn) - b;
		if(!(j < m && b[j] == mn)) continue;
		if(j == m - 1) {
			dp[i] = 1;
		} else {
			dp[i] = cnt[j + 1];
		}
		cnt[j] = (cnt[j] + dp[i]) % M;
	}
	if(mn != b[0]) {
		cout << 0 << endl;
		return 0;
	}
	cout << dp[0] << endl;
	
}