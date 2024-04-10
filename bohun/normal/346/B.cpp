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
#define po(x) cerr << #x << " = " << x << endl;

using namespace std;
using namespace __gnu_pbds;

// order_by_key
// find_by_order
// tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> siema;

const int inf = 1e9;

string a, b, c;
int p[105];
int dp[105][105][105];
pair<pair<int, int>, int> opt[105][105][105];

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin >> a >> b >> c;
	int n = ss(c);
	for(int i = 1; i < n; ++i) {
		int pref = p[i - 1];
		while(pref && c[i] != c[pref])
			pref = p[pref - 1];
		if(c[pref] == c[i])
			++pref;
		p[i] = pref;
	}
	
	int A = ss(a);
	int B = ss(b);
	int C = ss(c);
	
	a = '2' + a + '3';
	b = '2' + b + '4';
	
	for(int i = 0; i <= A; ++i)
		for(int j = 0; j <= B; ++j)
			for(int g = 0; g <= C; ++g) {
				dp[i][j][g] = -inf;
			}
	dp[0][0][0] = 0;
	for(int i = 0; i <= A; ++i) 
		for(int j = 0; j <= B; ++j) {
			for(int g = 0; g < n; ++g) {
				if(dp[i + 1][j][g] < dp[i][j][g]) {
					dp[i + 1][j][g] = dp[i][j][g];
					opt[i + 1][j][g] = mp(mp(i, j), g);
				}
				if(dp[i][j + 1][g] < dp[i][j][g]) {
					dp[i][j + 1][g] = dp[i][j][g];
					opt[i][j + 1][g] = mp(mp(i, j), g);
				}
				if(a[i + 1] == b[j + 1]) {
					int pref = g;
					while(pref && c[pref] != a[i + 1])
						pref = p[pref - 1];
					if(c[pref] == a[i + 1])
						++pref;
					if(dp[i + 1][j + 1][pref] < dp[i][j][g] + 1) {
						dp[i + 1][j + 1][pref] = dp[i][j][g] + 1;
						opt[i + 1][j + 1][pref] = mp(mp(i, j), g);
					}
				}
			}
		}
		
	int ans = 0;
	int j = 0;
	for(int i = 0; i < n; ++i) {
		if(ans < dp[A][B][i]) {
			j = i;
			ans = dp[A][B][i];
		}
	}
	int X = A;
	int Y = B;
	string res = "";
	while(X && Y) {
		int px = opt[X][Y][j].fi.fi;
		int py = opt[X][Y][j].fi.se;
		int pj = opt[X][Y][j].se;
		if(dp[X][Y][j] != dp[px][py][pj])
			res.pb(a[X]);
		X = px;
		Y= py;
		j = pj;
	}
	if(!ans) {
		cout << 0;
	}
	reverse(res.begin(), res.end());
	cout << res;
		
	
				
					
				
			
	
	
	
	
	
		
	
	
	
	return 0;
}