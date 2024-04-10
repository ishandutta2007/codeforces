#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define FOR(i, n) for(int i = 1; i <= n; ++i) 
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl;



using namespace std;
using namespace __gnu_pbds;

// order_by_key
// find_by_order
// tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> Plus, Minus;

const int nax = 100005;

int n, m;
string s[nax];
int col[nax];
int row[nax];
int ans = 1e9;
	
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int T;
	cin >> T;
	while(T--) {
		ans = 1e9;
		cin >> n >> m;
		for(int i = 1; i <= n; ++i) {
			cin >> s[i];
			s[i] = '2' + s[i];
			row[i] = 0;
		}
		for(int i = 1; i <= m; ++i)
			col[i] = 0;
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= m; ++j) {
				if(s[i][j] == '.') {
					row[i]++;
					col[j]++;
				}
			}
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= m; ++j) {
				int res = row[i] + col[j] - (s[i][j] == '.');
				ans = min(res, ans);
			}
		cout << ans << endl;
	}
			
	
	

	return 0;
}