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

unordered_map<int, int> diffs;
unordered_map<int, int> diffs2[1024];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T=1;
	//freopen("E.in", "r", stdin);
	forn(tc, T) {
		tint n;
		cin >> n;
		vi a(n);
		forn(i, n) {
			cin >> a[i];
		}
		
		int ans = 0;
		forsn(j, -100, 100) {
			diffs.clear();
			forn(i, n) {
				diffs[a[i]-(j*i)]++;
			}
			for(auto& [d, res]: diffs) {
				ans = max(ans, res);
			}
		}
		
		forn(i, n) {
			diffs2[i%1024].clear();
			forsn(j, max(0LL, i-1000LL), i) {
				if((a[i]-a[j])%(i-j) == 0) {
					tint d = (a[i]-a[j])/(i-j);
					if(abs(d) > 100) diffs2[i%1024][d] = diffs2[j%1024][d] + 1;
				}
			} 
			for(auto& [d, res]: diffs2[i%1024]) {
				ans = max(ans, res+1);
			}
		}
		
		cout << n-ans << endl;
	}
}