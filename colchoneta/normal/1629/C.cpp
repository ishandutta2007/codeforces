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
		vi a(n), ms(n);
		forn(i, n) cin >> a[i];
		tint cm = 0;
		vi found(n+1);
		dforn(i, n) {
			found[a[i]] = 1;
			while(found[cm]) cm++;
			ms[i] = cm;
		}
		
		vi cnt(n+1), b;
		forn(i, n) {
			tint j = i, fop = 0, am = 0;
			b.push_back(ms[i]);
			while(!fop) { 
				cnt[a[j]]++;
				while(cnt[am]) am++;
				if(am == ms[i]) fop = 1;
				j++;
			}
			forsn(k, i, j) {
				cnt[a[k]]--;
			}
			i = j-1;
		}
		
		cout << b.size() << endl;
		forn(i, b.size()) cout << b[i] << " ";
		cout << endl;
	}
}