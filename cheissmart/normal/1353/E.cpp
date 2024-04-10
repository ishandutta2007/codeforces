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

const int INF = 1e9 + 7, N =1e6 + 7;

int dp[N];

signed main()
{
	IO_OP;
	
	int t;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		string s;
		cin >> s;
		vi cnt(n);
		cnt[0] = s[0] - '0';
		for(int i = 1; i < n; i++) cnt[i] = cnt[i - 1] + s[i] - '0';
		int mn = INF;
		for(int i = 0; i < n; i++) {
			if(i < k) {
				dp[i] = (i ? cnt[i - 1] : 0) + (s[i] == '0');
			} else {
				int j = i - k;
				dp[i] = dp[j] + cnt[i - 1] - cnt[j] + (s[i] == '0');
			}
			dp[i] = min(dp[i], cnt[i]);
			mn = min(mn, dp[i] + cnt[n - 1] - cnt[i]);
		}
		cout << mn << '\n';
		for(int i = 0; i < n; i++) dp[i] = 0;
	}	
	
}