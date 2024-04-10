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

const ll mod = 1e18;

int n, m;
vector <vector<int>> v, byl, dp;
vector <int> x;
char s[1000001];
vector <pair<int, int>> ac, to;

int main() {	
	scanf("%d%d", &n, &m);
	FOR(i, 1, n) {
		scanf("%s", s);
		x.clear();
		FOR(j, 0, m - 1)
			x.pb((s[j] == '.'));
		v.pb(x);
	}
	
	FOR(i, 0, n - 1) {
		vector <int> z;
		FOR(j, 0, m - 1)
			z.pb(0);
		byl.pb(z);
		dp.pb(z);
	}
	
	for(int i = n - 1; 0 <= i; --i) 
		for(int j = m - 1; 0 <= j; --j) {
			if(i == n - 1 && j == m - 1)
				dp[i][j] = 1;
			else {
				if(i < n - 1 && v[i + 1][j])
					dp[i][j] |= dp[i + 1][j];
				if(j < m - 1 && v[i][j + 1])
					dp[i][j] |= dp[i][j + 1];
			}
		}
	
	ac.pb(mp(0, 0));
	
	int steps = n + m - 2;
	bool ok = 0;
	while(steps--) {
		if(ac.empty()) {
			printf("0\n");
			return 0;
		}
		//cout << steps << " " << ss(ac) << endl;
		if(steps != n + m - 3 && ss(ac) == 1)
			ok = 1;
		to.clear();
		for(auto it : ac) {
			if(it.fi < n - 1 && v[it.fi + 1][it.se] && !byl[it.fi + 1][it.se] && dp[it.fi + 1][it.se]) {
				to.pb(mp(it.fi + 1, it.se));
				byl[it.fi + 1][it.se] = 1;
			}
			if(it.se < m - 1 && v[it.fi][it.se + 1] && !byl[it.fi][it.se + 1] && dp[it.fi][it.se + 1]) {
				to.pb(mp(it.fi, it.se + 1));
				byl[it.fi][it.se + 1] = 1;
			}
		}
		ac = to;
	}
	if(ok) {
		printf("1\n");
	}
	else {
		printf("2\n");
	}
	
	
					
		
	
	
	
	
	
	return 0;
}