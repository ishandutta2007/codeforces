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

int dp[404][404], nxt[404][26];

bool go(string x, string y, string s) {
	memset(dp, 0x3f, sizeof dp);
	for(int i = 0; i <= x.size(); i++) {
		for(int j = 0; j <= y.size(); j++) {
			if(i == 0 && j == 0) {
				dp[i][j] = 0;
			} else {
				if(j && dp[i][j-1] <= s.size()) {
					dp[i][j] = min(dp[i][j], nxt[dp[i][j-1]][y[j-1]-'a'] + 1);
				}
				if(i && dp[i-1][j] <= s.size()) {
					dp[i][j] = min(dp[i][j], nxt[dp[i-1][j]][x[i-1]-'a'] + 1);
				}
			}
		}
	}
	return dp[x.size()][y.size()] <= s.size();
}

signed main()
{
	IO_OP;
	
	int tt;
	cin >> tt;
	while(tt--) {
		string s, t;
		cin >> s >> t;
		memset(nxt, 0x3f, sizeof nxt);
		for(int i = s.size()-1; i >= 0; i--) {
			for(int j = 0; j < 26; j++) nxt[i][j] = nxt[i+1][j];
			nxt[i][s[i]-'a'] = i;
		}
		string x, y;
		bool ok = false;
		for(int i = 0; i < t.size(); i++) {
			x = t.substr(0, i), y = t.substr(i);
			ok |= go(x, y, s);
		}
		cout << (ok ? "YES" : "NO") << endl;
	}

}