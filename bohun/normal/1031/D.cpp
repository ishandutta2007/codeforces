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

const int nax = 3005;
int n, m, k;
string s[nax];
int dp[nax][nax];
int opt[nax][nax];
vector <pair<int, int>> v[nax];
vector <pair<int, int>> lit[nax];

int ok[nax][nax];

int main() {
	
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin >> n >> k;
	for(int i = 1; i <= n; ++i) {
		cin >> s[i];
		s[i] = '2' + s[i];
	}
	
	if(n == 1) {
		if(k > 0) {
			cout << 'a';
		}
		else {
			cout << s[1][1];
		}
		return 0;
	}
	
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			v[i + j].pb(mp(i, j));
			dp[i][j] = n * n + 10;
		}
	}
	
	ok[1][1] = 1;
	dp[1][1] = 0;
	
	for(int i = 2; i <= 2 * n - 1; ++i) {
		int best = 100;
		for(int j = 0; j < 26; ++j)
			lit[j].clear();
		for(auto it: v[i]) {
			int x = it.fi;
			int y = it.se;
			if(!ok[x][y]) 
				continue;
			if(dp[x][y] < k && s[x][y] != 'a') {
				dp[x][y]++;
				s[x][y] = 'a';
			}
			lit[s[x][y] - 'a'].pb(mp(x, y));
			best = min(best, s[x][y] - 'a');
		}
		for(auto it: lit[best]) {
				int x = it.fi;
				int y = it.se;
				int px = x;
				int py = y + 1;
				if(py <= n) {
					dp[px][py] = min(dp[px][py], dp[x][y]);
					opt[px][py] = 1;
					ok[px][py] = 1;
				}
				px = x + 1;
				py = y;
				if(px <= n) {
					dp[px][py] = min(dp[px][py], dp[x][y]);
					opt[px][py] = 0;
					ok[px][py] = 1;
				}
			}
	}
	
	if(dp[n][n] < k)
		s[n][n] = 'a';
	
	int X = n;
	int Y = n;
	vector <char> res;
	
	do {
		res.pb(s[X][Y]);
		if(opt[X][Y] == 1)
			Y--;
		else
			X--;
	} while(X != 1 || Y != 1);
	res.pb(s[1][1]);
	reverse(res.begin(), res.end());
	for(auto it: res)
		cout << it;
			
			
		
		
	
	
	
	
	
	
				
	
	
    return 0;
}