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

int main() {
	int T;
	cin >> T;
	
	forn(tc, T) {
		tint a, b;
		cin >> a >> b;
		tint ans = b-a;
		forsn(i, a, b) ans = min(ans, i-a + 1 + (i|b) - b);
		dforn(i, 30) {
			if(a & (1 << i) && !(b & (1 << i))) {
				tint ra = a & ((1 << (i+1)) -1), rb = b & ((1 << (i+1)) -1);
				ans = min(ans, ra-rb + 1);
				break;
			} 
		}
		cout << ans << endl;
	}
}