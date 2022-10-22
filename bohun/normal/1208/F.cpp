#pragma GCC optimize("O3")
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
const int nax = (1 << 21) + 11;

int n;
vector <int> dp[nax];
int t[nax];

void Reduce(int x) {
	sort(dp[x].begin(), dp[x].end());
	reverse(dp[x].begin(), dp[x].end());
	while(ss(dp[x]) > 2)
		dp[x].pop_back();
	reverse(dp[x].begin(), dp[x].end());
}

int main() {
	ios;
	cin >> n;
	FOR(i, 1, n) {
		cin >> t[i];
		dp[t[i]].pb(i);
		Reduce(t[i]);
	}
	
	FOR(k, 0, 20) 
		FOR(m, 0, (1 << 21) - 1) {
			if(!((m >> k) & 1)) {
				for(auto it: dp[m ^ (1 << k)])
					dp[m].pb(it);
				Reduce(m);
			}
		}
	
	int best = 0;
	FOR(i, 1, n - 2) {
		int M = (((1 << 21) - 1) ^ t[i]);
		int res = 0;
		for(int k = 20; 0 <= k; --k) {
			if((M & (1 << k)) == 0)
				continue;
			int NM = (res ^ (1 << k));
			if(ss(dp[NM]) == 2 && dp[NM][0] > i && dp[NM][1] > i)
				res ^= (1 << k);
		}
		best = max(best, res + t[i]);
	}
	
	cout << best;
			
				
	
	
		
	
	
	return 0;
}