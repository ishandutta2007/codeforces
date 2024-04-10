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

tint modexp(tint a, tint b) {
	if(b == 0) return 1;
	tint rec = modexp(a, b/2);
	rec = (rec*rec)%MOD;
	if(b % 2) rec = (rec * a)%MOD;
	return rec;
}

tint inv(tint a) {
	return modexp(a, MOD-2);
}

int main() {
	int T;
	cin >> T;
	forn(tc, T) {
		tint m, n, k;
		cin >> n >> m >> k;
		tint ans = 0;
		vvi ch(2*n+1, vi(2*n+1, 0));
		forn(i, 2*n+1) forn(j, i+1) {
			if(j == 0 || j == i) ch[i][j] = 1; else ch[i][j] = (ch[i-1][j] + ch[i-1][j-1]) % MOD;
		}
		
		if(n <= m) {
			ans = (n*k)%MOD;
		} else {
		tint b = inv(2), r = n-m-1;
			forn(i, m+1) {
				ans += ((i * ch[m-i+r][r])%MOD * modexp(b, n-i))%MOD;
				ans %= MOD;
			}
			ans *= k;
			ans %= MOD;
		}
		cout << ans << endl;
	}
}