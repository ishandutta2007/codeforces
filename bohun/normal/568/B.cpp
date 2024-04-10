#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define FOR(i, j, n) for(int i = j; i <= n; ++i)
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl;
#define ios cin.tie(0); ios_base::sync_with_stdio(0)
  
using namespace std;						

const int nax = 4005;
const int mod = 1e9 + 7;

int n;
int dp[nax][nax], com[nax][nax];
int gr[nax];
int ans;

int main() {
	scanf("%d", &n);
	dp[0][0] = 1;
	FOR(i, 1, nax - 1)
		FOR(j, 1, i)
			dp[i][j] = ((ll) dp[i - 1][j] * j % mod + dp[i - 1][j - 1]) % mod;
	FOR(i, 0, n)
		FOR(j, 0, n)
			gr[i] = (gr[i] + dp[i][j]) % mod;
	FOR(i, 0, nax - 1) {
		com[i][0] = com[i][i] = 1;
		FOR(j, 1, i - 1)
			com[i][j] = (com[i - 1][j - 1] + com[i - 1][j]) % mod;
	}
	FOR(i, 1, n) 
		ans = (ans + (ll) com[n][i] * gr[n - i] % mod) % mod;
	cout << ans;
	
		
	return 0;
}