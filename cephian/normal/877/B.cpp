#include <bits/stdc++.h>

using namespace std;

int dp[5005];
int A[5005],B[5005];

int main() {
	string s;
	cin >> s;
	int n = s.size();
	A[0] = B[0] = 0;
	for(int i = 1; i <= n; ++i) {
		A[i] = A[i-1] + (s[i-1] == 'a');
		B[i] = B[i-1] + (s[i-1] == 'b');
	}	
	for(int l = 1; l <= n; ++l) {
		dp[l] = 0;
		for(int p = 0; p <= l; ++p)	
			dp[l] = max(dp[l],l - (B[p]-B[0]) - (A[l]-A[max(0,p)]));
	}
	int ans = 0;
	for(int s = 0; s <= n; ++s) {
		ans = max(ans,dp[s] + A[n] - A[max(0,s)]);
	}
	cout << ans << "\n";
}