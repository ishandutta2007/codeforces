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
#define ios cin.tie(0); ios_base::sync_with_stdio(0);
 
 
using namespace std;
using namespace __gnu_pbds;
 
// order_by_key
// find_by_order
// tree<int>, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ja;		
const int nax = 6e5 + 5;
int T;
int n, m, a, b;
vector <int> vv[nax];
int good[nax];
int ile[nax];	
int ILE[nax];
pair <pair<int, int>, int> e[nax];
int eee[nax];
int X[nax];
				
int main() {
	ios
	cin >> T;
	while(T--) {
		cin >> n >> m;
		FOR(i, 1, 3 * n) {
			good[i] = ile[i] = ILE[i] = 0;
			vv[i].clear();
			eee[i] = 0;
		}
		vector <int> edges, ver;
		FOR(i, 1, m) {
			cin >> a >> b;
			vv[a].pb(b);
			vv[b].pb(a);
			e[i] = mp(mp(a, b), i);
		}
		
		edges.clear();
		ver.clear();
		
		while(ss(edges) < n && ss(ver) < n) {
			FOR(i, 1, 3 * n) {
				good[i] = ile[i] = ILE[i] = eee[i] = 0;
			}
			edges.clear();
			ver.clear();
			random_shuffle(e + 1, e + m + 1);
			for(int i = 1; i <= m; ++i) {
				int A = e[i].fi.fi;
				int B = e[i].fi.se;
				if(!eee[A] && !eee[B]) {
					edges.pb(e[i].se);
					eee[A]++;
					eee[B]++;
				}
			}
			while(ss(edges) > n)
				edges.pop_back();
			if(ss(edges) == n) {
				cout << "Matching\n";
				for(auto it: edges)
					cout << it << " ";
				cout << endl;
				break;
			}
			FOR(i, 1, 3 * n)
				X[i] = i;
				
			random_shuffle(X + 1, X + 3 * n + 1);
			
			FOR(i, 1, 3 * n) {
				int node = X[i];
				if(ile[node] == 0) {
					ver.pb(node);
					for(auto it: vv[node])
						ile[it]++;
				}
			}
			
			while(ss(ver) > n)
				ver.pop_back();
			
			if(ss(ver) == n) {
				cout << "IndSet\n";
				for(auto it: ver)
					cout << it << " ";
				cout << endl;
				break;
			}
		}
			
		
		
		
		
	}
		
	
	
	
	
	
	
	
	
	
		
	return 0;
}