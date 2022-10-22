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
typedef vector<vvi> vvvi;
typedef vector<pair<tint,tint>> vp;
typedef vector<vp> vvp;
typedef tree<pair<tint, tint>,null_type,less<pair<tint, tint>>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;

int main() {
	int T;
	cin >> T;
	forn(tc, T) {
		tint n;
		cin >> n;
		vector<string> s(n);
		forn(i, n) cin >> s[i];
		tint ans = 0;
		
		vi f2(27*27), f3(27*27), h3(27*27*27);
		if(ans == 0) {
			for(auto t: s) {
				string r = t;
				reverse(r.begin(), r.end());
				if(r == t) {
					ans = 1;
					continue;
				}
				if(t.size() == 2) {
					tint rh = (t[1]-'a')*27+(t[0]-'a');
					if(f2[rh] || f3[rh]) ans = 1;
					f2[(t[0]-'a')*27+(t[1]-'a')] = 1;
				} else {
					tint rh = (t[2]-'a')*27+(t[1]-'a');
					if(f2[rh]) ans = 1;
					tint frh = (t[2]-'a')*27*27+(t[1]-'a')*27+(t[0]-'a');
					if(h3[frh]) ans = 1;
					f3[(t[0]-'a')*27+(t[1]-'a')] = 1;
					h3[(t[0]-'a')*27*27+(t[1]-'a')*27+(t[2]-'a')] = 1;
				}
			}
		}
		if(ans) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
}