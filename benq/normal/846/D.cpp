#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

const int MOD = 1000000007;
const ll INF = 1e18;

int n,m,k,q, cum[501][501];
vector<pair<int,pii>> pixel;

bool test(int mid) {
    F0R(i,n+1) F0R(j,m+1) cum[i][j] = 0;
    for (auto a: pixel) if (a.f <= mid) cum[a.s.f][a.s.s] ++;
    FOR(i,1,n+1) FOR(j,1,m+1)
        cum[i][j] += cum[i-1][j]+cum[i][j-1]-cum[i-1][j-1];
    F0R(i,n+1-k) F0R(j,m+1-k) if (cum[i+k][j+k]-cum[i][j+k]-cum[i+k][j]+cum[i][j] == k*k) return 1;
    return 0;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> m >> k >> q;
	F0R(i,q) {
	    int x,y,t; cin >> x >> y >> t;
	    pixel.pb({t,{x,y}});
	}
	int lo = 0, hi = MOD;
	while (lo < hi) {
	    int mid = (lo+hi)/2;
	    if (test(mid)) hi = mid;
	    else lo = mid+1;
	}
	if (hi == MOD) cout << -1;
	else cout << lo;
}

// read!
// ll vs. int!