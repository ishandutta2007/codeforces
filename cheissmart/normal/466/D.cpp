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

const int INF = 1e9 + 7, N = 2002, M = 1e9 + 7;

int dp[N][N], a[N];

void add(int &a, int b) {
	a += b;
	if(a >= M) a -= M;
}

signed main()
{
	IO_OP;
	
	int n, h;
	cin >> n >> h;
	for(int i = 0; i < n; i++) cin >> a[i];
	if(a[0] == h) dp[0][0] = 1;
	else if(a[0] + 1 == h) dp[0][0] = dp[0][1] = 1;
	for(int i = 0; i < n - 1; i++) {
		for(int j = 0; j < n; j++) {
			if(a[i+1] + j == h) {
				add(dp[i + 1][j], dp[i][j]); // no
				if(j) add(dp[i + 1][j - 1], (ll) dp[i][j] * j % M); // close
			}
			if(a[i+1] + j + 1 == h) {
				add(dp[i + 1][j], dp[i][j]); // open and close
				add(dp[i + 1][j + 1], dp[i][j]); // open
				add(dp[i + 1][j], (ll) dp[i][j] * j); // close and open
			}
		}
	}
	cout << dp[n - 1][0] << endl;
}