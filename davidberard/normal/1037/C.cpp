#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int NMAX = 1000005;

int dp[NMAX];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int N;
	cin >> N;
	string s, t;
	cin >> s >> t;
	for(int i=0;i<N;++i) {
		dp[i+1] = dp[i]+(s[i]!=t[i]);
		if(i >= 1 && s[i] != s[i-1] && s[i]!=t[i] && s[i-1] != t[i-1]) {
			dp[i+1] = min(dp[i+1], dp[i-1]+1);
		}
	}
	cout << dp[N] << endl;
 
	return 0;
}