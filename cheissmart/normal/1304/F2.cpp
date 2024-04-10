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

const int INF = 1e9 + 7, N = 52, M = 2e4 + 7;

int a[N][M], dp[N][M];

signed main()
{
	IO_OP;
	
	int n, m, k;
	cin >> n >> m >> k;
	for(int i = 0; i < n; i++)
		for(int j = 1; j <= m; j++)
			cin >> a[i][j];
	vi p(m + 1);
	for(int j = 1; j <= m; j++) {
		p[j] = a[0][j] + a[1][j], p[j] += p[j - 1];
		if(j >= k) dp[0][j - k + 1] = p[j] - p[j - k];
	}
	for(int i = 1; i < n; i++) {
		vi p(m + 1), pp(m + 1);
		for(int j = 1; j <= m; j++) p[j] = a[i][j] + a[i + 1][j], p[j] += p[j - 1];
		for(int j = 1; j <= m; j++) pp[j] = a[i][j], pp[j] += pp[j - 1];
		{
			int mx = 0, add = 0;
			deque<pi> dk;
			for(int j = 1; j <= m - k + 1; j++) {
				while(dk.size() && j -dk.front().S >= k) dk.pop_front();
				add += a[i][j - 1];
				if(j > k) mx = max(mx, dp[i - 1][j - k]);
				int cur = p[j + k - 1] - p[j - 1];
				int nw = dp[i - 1][j] - (pp[j + k - 1] - pp[j - 1]) - add;
				while(dk.size() && dk.back().F < nw) dk.pop_back();
				dk.EB(nw, j);
				dp[i][j] = max(dp[i][j], cur + max(dk.front().F + add, mx));
			}
		}
		{
			int mx = 0, add = 0;
			deque<pi> dk;
			for(int j = m - k + 1; j >= 1; j--) {
				while(dk.size() && dk.front().S - j >= k) dk.pop_front();
				add += a[i][j + k];
				mx = max(mx, dp[i - 1][j + k]);
				int cur = p[j + k - 1] - p[j - 1];
				int nw = dp[i - 1][j] - (pp[j + k - 1] - pp[j - 1]) - add;
				while(dk.size() && dk.back().F < nw) dk.pop_back();
				dk.EB(nw, j);
				dp[i][j] = max(dp[i][j], cur + max(dk.front().F + add, mx));
			}
		}
	}
	int mx = 0;
	for(int j = 1; j <= m - k + 1; j++) mx = max(mx, dp[n - 1][j]);
	cout << mx << endl;
}