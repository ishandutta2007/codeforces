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
		tint n;
		cin >> n;
		vi a(n);
		forn(i, n) {
			cin >> a[i];
		}
		
		vvi mex(n, vi(n+1, 0));
		forn(i, n) {
			set<tint> found;
			tint m = 0;
			forsn(j, i, n) {
				found.insert(a[j]);
				while(found.count(m)) m++;
				mex[i][j+1] = m;
			}
		}
		
		vvi dp(n, vi(n+1, 0));
		forn(i, n) forsn(j, i, n) dp[i][j+1] = 1 + mex[i][j+1];
		tint ans = 0;
		forn(i, n) forsn(j, i, n) forsn(k, i, j+1) {
			dp[i][j+1] = max(dp[i][j+1], dp[i][k] + mex[k][j+1] + 1);
		}
		forn(i, n) forsn(j, i, n) {
			ans += dp[i][j+1];
		}
		cout << ans << endl;
		
	}
}