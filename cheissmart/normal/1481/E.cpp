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

const int INF = 1e9 + 7, N = 5e5 + 7;

int a[N], dp[N];
vi G[N];

signed main()
{
	IO_OP;

	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) {
	 	cin >> a[i];
	 	G[a[i]].PB(i);
	}
	int mn = INF;
	for(int i = 1; i <= n; i++) {
		if(G[a[i]].back() != i) {
			dp[i] = dp[i - 1];
		} else {
			dp[i] = max(dp[i - 1], int(G[a[i]].size()) + dp[G[a[i]][0] - 1]);
			for(int j = 0; j < G[a[i]].size(); j++) {
				int keep = G[a[i]].size() - j + dp[G[a[i]][j] - 1];
				mn = min(mn, n - keep);
			}
		}
	}
	cout << mn << endl;

}