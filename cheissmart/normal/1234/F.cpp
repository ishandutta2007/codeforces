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

int dp[1<<20];

int32_t main()
{
	IO_OP;
	
	string s;
	cin >> s;
	for(int i=0;i<s.size();i++) {
		int m = 0;
		for(int j=i;j>=0;j--) {
			int t = s[j] - 'a';
			if(m >> t & 1) break;
			m ^= 1 << t;
			dp[m] = __builtin_popcount(m);
		}
	}
	for(int i=0;i<(1<<20);i++) 
		for(int j=0;j<20;j++) if(i>>j&1)
			dp[i] = max(dp[i], dp[i^(1<<j)]);
	int ans = 0;
	for(int i=0;i<(1<<20);i++)
		ans = max(ans, dp[i] + dp[(1<<20)-1-i]);
	cout << ans << endl;
}