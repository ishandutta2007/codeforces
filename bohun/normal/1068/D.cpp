#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>


#define pb push_back
#define ld long double
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
#define mp make_pair
#define FOR(i, n) for(int i = 1; n >= i; ++i)

using namespace std;
using namespace __gnu_pbds;

const int nax = 200005, inf = 1e9 + 1, mod = 998244353;

int n;
int t[nax];
int dp[nax][205][2];
int pref[205][2];
int suf[205][2];

void add(int &a, int b) {
	a += b;
	if(a > mod)
		a -= mod;
}

int main() {
	
	//cin.tie(0);
	//ios_base::sync_with_stdio(0);
	
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &t[i]);
	}
	dp[0][0][1] = 1;
		
		
	
	for(int i = 1; i <= n; ++i) {
		
		for(int j = 0; j <= 200; ++j) {
			pref[j][1] = 0;
			pref[j][0] = 0;
				if(j) {
				add(pref[j][0], pref[j - 1][0]);
				add(pref[j][1], pref[j - 1][1]);
			}
			add(pref[j][0], dp[i - 1][j][0]);
			add(pref[j][1], dp[i - 1][j][1]);
		}
		for(int j = 200; 0 <= j; --j) {
			suf[j][0] = suf[j][1] = 0;
			add(suf[j][0], suf[j + 1][0] + dp[i - 1][j][0]);
			add(suf[j][1], suf[j + 1][1] + dp[i - 1][j][1]);
		}
		
		
		if(t[i] != -1) {
			add(dp[i][t[i]][0], pref[t[i] - 1][0] + pref[t[i] - 1][1]);
			add(dp[i][t[i]][1], ((ll) suf[t[i] + 1][1] + dp[i - 1][t[i]][0] + dp[i - 1][t[i]][1]) % mod);
		}
		else {
			for(int j = 1; j <= 200; ++j) {
				add(dp[i][j][0], pref[j - 1][0] + pref[j - 1][1]);
				add(dp[i][j][1], ((ll) suf[j + 1][1] + dp[i - 1][j][0] + dp[i - 1][j][1]) % mod);
			}
		}
	}
	
	int ans = 0;
	for(int i = 1; i <= 200; ++i) {
		ans += dp[n][i][1];
		ans %= mod;
	}
	cout << ans;
				
	
	
    return 0;
}