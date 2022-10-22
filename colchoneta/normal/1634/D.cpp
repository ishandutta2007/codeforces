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

void ask(int a, int b, int c) {
	cout << "? " << a << " " << b << " " << c << endl;
	cout.flush();
}

void answer(int i, int j) {
	cout << "! " << i << " " << j << endl;
	cout.flush();
}

int main() {
	int T;
	cin >> T;
	
	forn(tc, T) {
		tint n;
		cin >> n;
		vi a(n);
		forn(i, n) a[i] = i+1;
		tint mans1 = -1, mi1 = 0;
		forn(i, n-2) {
			ask(1, 2, i+3);
			tint ans;
			cin >> ans;
			if(ans > mans1) {
				mans1 = ans;
				mi1 = i+2;
			}
		}
		
		swap(a[1], a[mi1]);
		tint mans2 = -1, mi2 = 0;
		forn(i, n-2) {
			if(a[i+2] != 2) { 
				ask(1, a[1], a[i+2]);
				tint ans;
				cin >> ans;
				if(ans > mans2) {
					mans2 = ans;
					mi2 = i+2;
				}
			}
		}
		
		// cands: 1, 2, a[1], a[mi2]
		// preg: 1, 2, a[1], 1, a[1], a[mi2]
		set<tint> ans({1, 2, a[1], a[mi2]});
		tint mans3, mans4;
		ask(1, 2, a[mi2]);
		cin >> mans3;
		ask(2, a[1], a[mi2]);
		cin >> mans4;
		tint best = max(mans1, max(mans2, max(mans3, mans4)));
		if(mans1 == best) ans.erase(a[mi2]);
		if(mans2 == best) ans.erase(2);
		if(mans3 == best) ans.erase(a[1]);
		if(mans4 == best) ans.erase(1);
		
		auto i = ans.begin(), j = ans.begin();
		if(ans.size() > 1) {
			j++;
		}
		answer(*i, *j);
	}
}