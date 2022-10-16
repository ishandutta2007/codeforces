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

const int INF = 1e9 + 7, N = 1e4 + 3;

int lst[N], dp[N][N];

signed main()
{
	IO_OP;
	
	string s, t;
	cin >> s >> t;
	s = ' ' + s, t = ' ' + t;
	memset(lst, -1, sizeof lst);
	for(int i = 1; i < s.size(); i++) {
		if(s[i] == '.') continue;
		int bal = 0;
		for(int j = i; j < s.size(); j++) {
			if(s[j] == '.') bal--;
			else bal++;
			if(bal == 0) {
				lst[j] = i - 1;
				break;
			}
		}
	}
	memset(dp, 0x3f ,sizeof dp);
	dp[0][0] = 0;
	for(int i = 1; i < s.size(); i++) {
		for(int j = 0; j < t.size(); j++) {
			dp[i][j] = min(dp[i][j], dp[i-1][j] + 1);
			if(s[i] == t[j]) dp[i][j] = min(dp[i][j], dp[i-1][j - 1]);
			if(lst[i] != -1) dp[i][j] = min(dp[i][j], dp[lst[i]][j]);
		}
	}
	cout << dp[s.size() - 1][t.size() - 1] << endl;
	
}