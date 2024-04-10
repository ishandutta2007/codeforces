#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
#include <set>
#include <unordered_map>
#include <map>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_set>
#define MOD 1000000007
#define forn(a, n) for(tint a = 0; a<(int) (n); ++a)
#define forsn(a, s, n) for(tint a = (s); a<(int) (n); ++a)
#define dforn(a, n) for(int a = (n)-1; a>=0; --a)
#define forall(a, all) for(__typeof(all.begin()) a = all.begin(); a != all.end(); ++a)
#define EPS 0.000000000001
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long tint;
typedef vector<tint> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vvi> vvvi;
typedef vector<pair<tint,tint>> vp;
typedef vector<vp> vvp;
typedef tree<pair<tint, tint>,null_type,less<pair<tint, tint>>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;

namespace std {
	template <> struct hash<std::pair<tint, tint>> {
		inline size_t operator()(const std::pair<tint, tint> &v) const {
			return v.first * 1000000000LL + v.second;
		}
	};
}

bool anda(int a, int b, int c, int d, vvi& lu, unordered_set<pair<tint, tint>>& forb) {
	int n1 = lu[a][b], n2 = lu[c][d];
	return n1 != n2 && !forb.count({min(n1,n2),max(n1,n2)});
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	
	forn(tc, T) {
		tint n, m;
		cin >> n >> m;
		vi a(n);
		unordered_map<tint, tint> cnt;
		forn(i, n) {
			cin >> a[i];
			cnt[a[i]]++;
		}
		vvi lu(n);
		tint ms = 0;
		for(auto p: cnt) {
			ms = max(ms, p.second);
			lu[p.second].push_back(p.first);
		}
		unordered_set<pair<tint, tint>> forb;
		forn(i, m) {
			tint u, v;
			cin >> u >> v;
			forb.insert({u, v});
		}
		
		vi nempty;
		forn(i, ms+1) {
			sort(lu[i].rbegin(), lu[i].rend());
			if(!lu[i].empty()) {
				nempty.push_back(i);
			}
		}
		
		tint ans = 0;
		for(auto i: nempty) for(auto j: nempty) {
			if(lu[j].empty()) continue;
			forn(k, lu[i].size()) {
				if(ans >= (i+j)*(lu[i][k]+lu[j][0])) break;
				if(anda(i,k,j,0,lu,forb)) {
					ans = max(ans, (i+j)*(lu[i][k]+lu[j][0]));
				} else {
					forn(l, lu[j].size()) {
						if(ans >= (i+j)*(lu[i][k]+lu[j][l])) break;
						if(anda(i,k,j,l,lu,forb)) {
							ans = max(ans, (i+j)*(lu[i][k]+lu[j][l]));
						}
					}
				}
			}
		}
		cout << ans << endl;
	}
}