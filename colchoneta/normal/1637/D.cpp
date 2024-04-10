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
	
	tint maxs = 20010;
	forn(tc, T) {
		tint n;
		cin >> n;
		vi a(n), b(n);
		forn(i, n) {
			cin >> a[i];
		}
		forn(i, n) {
			cin >> b[i];
		}
		
		vvi dp(n+1, vi(maxs, 0));
		dp[0][0] = 1;
		forn(i, n) forn(j, maxs) {
			if(j >= a[i] && dp[i][j-a[i]]) dp[i+1][j] = 1;
			if(j >= b[i] && dp[i][j-b[i]]) dp[i+1][j] = 1;
		}
		
		tint ts = 0, tss = 0;
		forn(i, n) {
			ts += a[i] + b[i];
			tss += a[i]*a[i] + b[i]*b[i];
		}
		tint ans = maxs*maxs;
		forn(i, maxs) if(dp[n][i]) {
			ans = min(ans, i*i + (ts-i)*(ts-i));
		}
		cout << ans + (n-2)*tss << endl;
	}
}