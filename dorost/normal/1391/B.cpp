/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 102;
string s[N];
int dp[N][N];

int32_t main(){
	int t = 1;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < n; i++)
			cin >> s[i];
		int ans = 0;
		for (int i = 0; i < n - 1; i++) {
			if (s[i][m - 1] == 'R')
				ans++;
		}
		for (int i = 0; i < m - 1; i++) {
			if (s[n - 1][i] == 'D')
				ans++;
		}
		cout << ans << endl;
	}
}