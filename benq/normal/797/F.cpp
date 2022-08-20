#include <bits/stdc++.h>

using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
 
#define pb push_back
#define f first
#define s second

int n,m,mouse[5000];
ll dp[5001][5001];
pii hole[5000];

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	
	cin >> n >> m;
	F0R(i,n) cin >> mouse[i];
	F0R(i,m) cin >> hole[i].f >> hole[i].s;
	sort(mouse,mouse+n);
	sort(hole,hole+m);
	
	FOR(i,1,n+1) F0R(j,m+1) dp[i][j] = 1e18;
	FOR(j,1,m+1) {
		deque<pair<ll,int>> best;
		best.pb({0,0});
		
		ll tot = 0;
		FOR(i,1,n+1) {
			tot += abs(mouse[i-1]-hole[j-1].f);
			pair<ll,int> nex = {dp[i][j-1]-tot,i};
			while (best.size() && best.back().f >= nex.f) best.pop_back();
			best.pb(nex);
			while (i-best.front().s > hole[j-1].s) best.pop_front();
			dp[i][j] = tot+best.front().f;
		}
	}
	
	if (dp[n][m] > 1e17) cout << -1;
	else cout << dp[n][m];
}