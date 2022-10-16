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

const int INF = 1e9 + 7;

signed main()
{
	IO_OP;
	
	int n, m;
	cin >> n >> m;
	V<vi> v(n, vi(m));
	for(int i = 0; i < n; i++) {
	 	int k;
	 	cin >> k;
	 	for(int j = 0; j < k; j++) {
	 		int l, r;
	 		cin >> l >> r;
	 		l--, r--;
	 		for(int ii = l; ii <= r; ii++)
	 			v[i][ii] = j;
	 	}
	}	
	V<vi> dp(m, vi(m));
	for(int len = 1; len <= m; len++) {
		for(int l = 0; l + len - 1 < m; l++) {
			int r = l + len - 1;
			if(len == 1) {
				int cnt = 0;
				for(int i = 0; i < n; i++)
					if((l == m - 1 || v[i][l + 1] != v[i][l]) && (l == 0 || v[i][l - 1] != v[i][l]))
						cnt++;
				dp[l][r] = cnt * cnt;
			} else {
				for(int mid = l; mid <= r; mid++) {
					int cnt = 0;
					for(int i = 0; i < n; i++) {
						if((r == m - 1 || v[i][r + 1] != v[i][mid]) && (l == 0 || v[i][l - 1] != v[i][mid]))
							cnt++;
					}
					dp[l][r] = max(dp[l][r], cnt * cnt + (l <= mid - 1 ? dp[l][mid - 1] : 0) + (mid + 1 <= r ? dp[mid + 1][r] : 0));
				}
			}
		}
	}
	cout << dp[0][m - 1] << endl;
	
}