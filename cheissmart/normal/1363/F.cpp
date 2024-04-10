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

const int INF = 1e9 + 7, N = 2003;

int dp[N][N], cnt_s[N][26], cnt_t[N][26];

void solve() {
	memset(cnt_t, 0, sizeof cnt_t);
	memset(cnt_s, 0, sizeof cnt_s);
	int n;
	string s, ss, t, tt;
	cin >> n >> s >> t;
	ss = s, tt = t;
	sort(ALL(ss)), sort(ALL(tt));
	if(ss != tt) {
		cout << -1 << endl;
		return;
	}
	s = ' ' + s, t = ' ' + t;
	for(int i = n; i >= 1; i--) {
		for(int j = 0; j < 26; j++) cnt_s[i][j] = cnt_s[i + 1][j], cnt_t[i][j] = cnt_t[i + 1][j];
		cnt_s[i][s[i]-'a']++;
		cnt_t[i][t[i]-'a']++;
	}
	for(int i = 0; i <= n; i++) for(int j = 0; j <= n; j++) dp[i][j] = INF;
	for(int j = 0; j <= n; j++) dp[0][j] = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = i; j <= n; j++) {
			dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
			if(cnt_s[i + 1][t[j]-'a'] > cnt_t[j + 1][t[j]-'a']) {
				dp[i][j] = min(dp[i][j], dp[i][j - 1]);
			}
			if(s[i] == t[j]) dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
		}
	}
	cout << dp[n][n] << '\n';
}

signed main()
{
	IO_OP;
	
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
	
}