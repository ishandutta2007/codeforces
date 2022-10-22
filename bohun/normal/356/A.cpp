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

const int nax = 300005;

int n, m;
pair <int, int> t[nax];
int ryc[nax];
set <int> s;
int res[nax];
int ile[nax];
vector <int> del;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin >> n >> m;
	
	for(int i = 1; i <= n; ++i) {
			s.insert(i);
	}
	
	for(int i = 1; i <= m; ++i) {
		cin >> t[i].fi >> t[i].se >> ryc[i];
		auto it = s.lower_bound(t[i].fi);
		while(it != s.end() && *it <= t[i].se) {
			if(*it != ryc[i])
				del.pb(*it);
			++it;
		}
		for(auto it: del) {
			res[it] = ryc[i];
			s.erase(it);
		}
		del.clear();
	}
	for(int i = 1; i <= n; ++i) {
		cout << res[i] << " ";
			
	}
	
	
	
	
				
	
	
	return 0;
}