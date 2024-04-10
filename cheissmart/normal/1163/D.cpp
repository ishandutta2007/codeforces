#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

int dp[1005][55][55], f0[55][26], f1[55][26];

int main()
{
	IO_OP;
	
	string c, s, t;
	cin >> c >> s >> t;
	for (int i = 0; i < 1005; i++)
		for (int j = 0; j < 55; j++)
			for (int k = 0; k < 55; k++)
				dp[i][j][k] = -INF;
	for(int i=0;i<=s.size();i++) {
		for(int j=0;j<26;j++) {
			string u=s.substr(0,i) + (char)('a' + j);
			for(int k=0;k<=min(u.size(), s.size());k++)
				if(s.substr(0, k) == u.substr(u.size()-k))
					f0[i][j] = k;
		}
	}
	for(int i=0;i<=t.size();i++) {
		for(int j=0;j<26;j++) {
			string u=t.substr(0,i) + (char)('a' + j);
			for(int k=0;k<=min(u.size(), t.size());k++) {
				if(t.substr(0, k) == u.substr(u.size()-k))
					f1[i][j] = k;
			}
		}
	}
	dp[0][0][0] = 0;
	int ans = -INF;
	for(int i=0;i<c.size();i++) {
		for(int j=0;j<=s.size();j++) {
			for(int k=0;k<=t.size();k++) {
				if(c[i] == '*') {
					for (int x = 0; x < 26; x++) {
						int l = f0[j][x], r = f1[k][x];
						dp[i+1][l][r] = max(dp[i+1][l][r], dp[i][j][k] + (l==s.size()) - (r==t.size()));
					}
				} else {
					int x = c[i]-'a';
					int l = f0[j][x], r = f1[k][x];
					dp[i+1][l][r] = max(dp[i+1][l][r], dp[i][j][k] + (l==s.size()) - (r==t.size()));
				}
			}
		}
	}
	for(int i=0;i<=s.size();i++)
		for(int j=0;j<=t.size();j++)
			ans = max(ans, dp[c.size()][i][j]);
	cout << ans << endl;
}