#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
#define f first
#define s second

int dp[4001][4001];
vector<pii> calls;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n,k; cin >> n >> k; calls.resize(n);
	F0R(i,n) cin >> calls[i].f >> calls[i].s;
	
	F0R(i,n+1) F0R(j,min(i,k)+1) {
		if (i == j) {
			dp[i][j] = 1;
			continue;
		}
		dp[i][j] = max(dp[i-1][j],calls[i-1].f)+calls[i-1].s;
		if (j) dp[i][j] = min(dp[i][j],dp[i-1][j-1]);
	}
	int ans = 0;
	if (n) ans = calls[0].f-1;
	FOR(i,1,n+1) ans = max(ans,calls[i-1].f-dp[i-1][min(k,i-1)]);
	cout << max(ans,86401-dp[n][k]);
}