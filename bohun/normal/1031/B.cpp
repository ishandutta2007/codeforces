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

const int nax = 100005;

int n;
int a[nax], b[nax];
int dp[nax][4];
int opt[nax][4];
				
		


int main() {
	
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin >> n;
	for(int i = 2; i <= n; ++i) 
		cin >> a[i];
	for(int i = 2; i <= n; ++i) 
		cin >> b[i];
	
	dp[1][0] = dp[1][1] = dp[1][2] = dp[1][3] = 1;
	
	for(int i = 2; i <= n; ++i) {
		for(int j = 0; j < 4; ++j) {
			for(int prev = 0; prev < 4; ++prev) {
				if(dp[i - 1][prev] == 0)
					continue;
				int A = (prev & j);
				int O = (prev | j);
				if(a[i] == O && b[i] == A) {
					dp[i][j] = 1;
					opt[i][j] = prev;
				}
			}
		}
	}
	for(int j = 0; j < 4; ++j) {
		if(dp[n][j]) {
			cout << "YES\n";
			int a = n;
			int b = j;
			vector <int> v;
			while(a) {
				v.pb(b);
				b = opt[a][b];
				a--;
			}
			reverse(v.begin(), v.end());
			for(auto it: v) 
				cout << it << " ";
			return 0;
		}
	}
	cout << "NO";
				
	
	
	
	
	
				
	
	
    return 0;
}