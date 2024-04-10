#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long

int32_t main(){
	string s;
	cin >> s;
	int n = s.size();
	int dp[n];
	dp[0] = 0;
	for (int i = 1; i < n; i++){
		dp[i] = dp[i - 1] + (s[i] == s[i - 1]);
	}
	int q;
	cin >> q;
	while (q--){
		int l, r;
		cin >> l >> r;
		cout << dp[r - 1] - dp[l - 1] << endl;
	}
}