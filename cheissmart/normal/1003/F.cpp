#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

string s[303];
bool eq[303][303];
int dp[303][303], len[303];

int main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int i=0;i<n;i++) {
		cin >> s[i];
		len[i] = s[i].size();
		if(i) len[i] += len[i-1];
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(s[i] == s[j])
				eq[i][j] = true;
	for(int i=n-1;i>=0;i--) {
		for(int j=n-1;j>=0;j--) {
			if(eq[i][j]) {
				dp[i][j] = 1;
				if(i < n-1 && j < n-1)
					dp[i][j] = 1 + dp[i+1][j+1];
				if(dp[i][j] > abs(j-i))
					dp[i][j] = abs(j - i);
			}
		}
	}
	int tlen = len[n-1] + n - 1, ans = tlen;
	for(int i=0;i<n;i++) {
		for(int j=i;j<n;j++) {
			int ct = 1;
			for(int k=j+1;k+j-i<n;k++) {
				if(dp[i][k] >= j-i+1) {
					ct++;
					k = k+j-i;
				}
			}
			if(ct > 1) {
				ans = min(ans, tlen - (len[j]-len[i-1]-1) * ct);
			}
		}
	}
	cout << ans << endl;
	
}