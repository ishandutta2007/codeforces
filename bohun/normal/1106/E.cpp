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

const int nax = 1e5 + 5, pod = (1 << 19), mod = 998244353;
const ll inf = 1e18;

int n, m, k;
int a, b, c, d;
multiset <pair<int, int>> secik;
struct s {
	int ile, d, add;
	s () {}
	s(int a, int b, int c) {
		ile = a;
		d = b;
		add = c;
	}
};
ll dp[nax][205];

vector <s> v[nax];
	
void go(int x) {
	for(auto it: v[x]) {
		if(it.add == 1)
			secik.insert(mp(it.ile, it.d));
		else
			secik.erase(secik.find(mp(it.ile, it.d)));
	}
}

int main() {
	
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int maxi = -1;
	cin >> n >> m >> k;
	for(int i = 0; 100001 >= i; ++i)
		for(int j = 0; m >= j; ++j)
			dp[i][j] = inf;
	
	dp[1][0] = 0;
	for(int i = 1; i <= k; ++i) {
		s xd;
		cin >> a >> b >> c >> d;
		maxi = max(maxi, b + 1);
		xd = s(d, c, 1);
		v[a].pb(xd);
		xd = s(d, c, -1);
		v[b + 1].pb(xd);
	}
	maxi = n + 1;
	for(int i = 1; i <= maxi; ++i) {
		go(i);
		for(int j = 0; j <= m; ++j) {
			//cout << i << " " << j << " " << dp[i][j] << endl;
			if(!ss(secik))
				dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
			else {
				dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j]);
				pair<int, int> x = *--secik.end();
				dp[x.se + 1][j] = min(dp[x.se + 1][j], (ll) dp[i][j] + x.fi);
			}
		}
	}
	
	ll best = inf;
	for(int i = 0; i <= m; ++i) {
		best = min(best, dp[maxi][i]);
	}
	cout << best;
			
			
		
		
	
	
	
		
	
    return 0;
}