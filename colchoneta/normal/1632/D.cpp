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

tint gcd(tint a, tint b) {
	if(b == 0) return a;
	return gcd(b, a%b);
}

int main() {
	int T=1;
	
	forn(tc, T) {
		tint n;
		cin >> n;
		vi a(n+1), ans(n+1, 0);
		a[0] = 1;
		forn(i, n) cin >> a[i+1];
		
		vp g(1, {1, 0});
		forn(i, n+1) if(i) {
			ans[i] = ans[i-1];
			if(a[i] == 1) {
				ans[i]++;
				g = vp(1, {1, i});
				continue;
			}
			vp ng(1, {a[i], i});
			tint act = a[i];
			dforn(i, g.size()) {
				tint next = gcd(act, g[i].first);
				if(next != act) {
					act = next;
					ng.push_back({next, g[i].second});
				}
			}
			reverse(ng.begin(), ng.end());
			g = ng;
			forn(j, g.size()) if(j) {
				int l = i - g[j].second + 1, r = i - g[j-1].second;
				if(l <= g[j].first && g[j].first <= r) {
					ans[i]++;
					g = vp(1, {1, i});
					break;
				}
			}
		}
		
		forn(i, n) cout << ans[i+1] << " ";
		cout << endl;
	}
}