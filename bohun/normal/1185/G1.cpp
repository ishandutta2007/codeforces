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
#define FOR(i, n) for(int i = 1; i <= n; ++i)
#define FORd(i, n) for(int i = n; 1 <= i; --i)

using namespace std;
using namespace __gnu_pbds;

// order_by_key
// find_by_order
// tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> siema;

const int mod = 1e9 + 7, nax = 20;

int dp[(1 << 16)][4][250];

int n, tim;
int t[nax][2];

void add(int &a, int b) {
	a += b;
	if(a > mod)
		a -= mod;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
		
	cin >> n >> tim;
	for(int i = 0; i < n; ++i) {
		cin >> t[i][0] >> t[i][1];
	}	
	dp[0][0][0] = 1;
	for(int maska = 0; maska < (1 << n); ++maska) {
		for(int last = 0; last < 4; ++last)
			for(int sum = 0; sum <= 230; ++sum) {
				if(dp[maska][last][sum] == 0)
					continue;
				for(int node = 0; node < n; ++node) {
					if(((1 << node) & maska) || t[node][1] == last)
						continue;
					int nlast = t[node][1];
					int nsum = sum + t[node][0];
					if(nsum > 230)
						continue;
					int nmaska = (maska | (1 << node));
					add(dp[nmaska][nlast][nsum], dp[maska][last][sum]);
				}
			}
	}
	int ans = 0;
	for(int i = 0; i < (1 << n); ++i) {
		for(int j = 1; j <= 3; ++j) {
			//cout << i << " " << j << " " << dp[i][j][tim] << endl;
			add(ans, dp[i][j][tim]);
		}
	}
	cout << ans;
	
		
			
		
		
			
						
	
	
				
	
	
	return 0;
}