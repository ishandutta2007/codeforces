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

const int mod = 1e9 + 7, nax = 200005;

int T;
string a, b;
vector <pair<int, int>> c, d;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin >> T;
	while(T--) {
		cin >> a >> b;
		c.clear();
		d.clear();
		int n = ss(a);
		int m = ss(b);
		for(int i = 0; i < n;) {
			int ile = 1;
			while(i + 1 < n && a[i] == a[i + 1])
				++i, ile++;
			c.pb(mp(a[i] - 'a', ile));
			++i;
		}
		
		for(int i = 0; i < m;) {
			int ile = 1;
			while(i + 1 < m && b[i] == b[i + 1])
				++i, ile++;
			d.pb(mp(b[i] - 'a', ile));
			++i;
		}
		
		bool ok = 1;
		if(ss(c) != ss(d))
			ok = 0;
		else {
			for(int i = 0; i < ss(c); ++i) {
				if(c[i].fi != d[i].fi || c[i].se > d[i].se)
					ok = 0;
			}
		}
		
		if(ok) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
		
		
			
						
	
	
				
	
	
	return 0;
}