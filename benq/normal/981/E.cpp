#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;

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
#define all(x) x.begin(), x.end()

const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 100001;
const int SZ = 1<<14;

bitset<10001> tmp[1<<15], ans;
vi ad[1<<15];
int n,q;


void upd(int l, int r, int x) {  // sum on interval [l, r]
    r ++;
    for (l += SZ, r += SZ; l < r; l >>= 1, r >>= 1) {
        if (l&1) ad[l++].pb(x);
        if (r&1) ad[--r].pb(x);
    }
}
    
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> q;
	F0R(i,q) {
		int l,r,x; cin >> l >> r >> x; l--, r--;
		upd(l,r,x);
	}
	tmp[0][0] = 1;
	FOR(i,1,1<<15) {
		tmp[i] = tmp[i/2];
		for (int j: ad[i]) tmp[i] |= tmp[i]<<j;
		if (i >= (1<<14)) ans |= tmp[i];
	}
	vi ret;
	FOR(i,1,n+1) if (ans[i]) ret.pb(i);
	cout << sz(ret) << "\n";
	for (int i: ret) cout << i << " ";
}