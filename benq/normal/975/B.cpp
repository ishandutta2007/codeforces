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

vl a(14);
ll ans = 0;

ll get(vl x, int ind) {
	if (x[ind] == 0) return 0;
	ll z = x[ind];
	x[ind] = 0;
	FOR(i,1,15) {
		x[(ind+i)%14] += (z+14-i)/14;
	}
	ll tmp = 0;
	F0R(i,14) if (x[i] % 2 == 0) tmp += x[i];
	return tmp;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    F0R(i,sz(a)) cin >> a[i];
    F0R(i,14) ans = max(ans,get(a,i));
    cout << ans;
}