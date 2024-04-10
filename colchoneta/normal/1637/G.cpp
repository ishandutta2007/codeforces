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

void doop(tint a, tint b, vp& ans, vi& cnt) {
	cnt[a+b]++;
	cnt[max(a,b)-min(a,b)]++;
	assert(cnt[a] > 0);
	cnt[a]--;
	assert(cnt[b] > 0);
	cnt[b]--;
	ans.push_back({a,b});
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	
	forn(tc, T) {
		tint n;
		cin >> n;
		if(n == 2) {
			cout << -1 << endl;
			continue;
		}
		
		tint p = 1;
		while(p < n) p*=2;
		vi cnt(p+1, 0);
		forn(i, n) cnt[i+1] = 1;
		tint r = p;
		vp ans;
		while(r > 1) {
			bool oped = 1;
			while(oped) {
				oped = 0;
				forsn(i, r+1, min(n+1, 2*r)) { 
					if(cnt[i]) {
						oped = 1;
						doop(i, 2*r-i, ans, cnt);
					}
				}
			}	
			r /= 2;
		}
		r =1;
		while(cnt[r] <= 1) r*=2;
		doop(r, r, ans, cnt);
		
		r = 1;
		while(r < p) {
			while(cnt[r]) {
				doop(0, r, ans, cnt);
				doop(r, r, ans, cnt);
			}
			r *= 2;
		}
		doop(0, p, ans, cnt);
		cout << ans.size() << endl;
		forn(i, ans.size()) {
			cout << ans[i].first << " " << ans[i].second << endl;
		}
	}
}