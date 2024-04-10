#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;
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

ll f,T,t0;
ll a1, t1, p1, a2, t2, p2;
ll mn = 1e18;

void test(ll ind) {
    if (a1*t1*ind >= T) {
        if (T/t1 >= f) mn = min(mn,p1*ind);
        return;
    }
    if (ind*a1 >= f) {
        mn = min(mn,p1*ind);
        return;
    }
    ll fp = f-ind*a1, Tp = T-ind*a1*t1;
    if (Tp/t0 >= fp) {
        mn = min(mn,ind*p1);
        return;
    }
    if (t2 == t0) return;
    ld cur = max(cur,(ld)t0*t2*(fp*t0-Tp)/(t0*(t0-t2)));
    
    if (cur > Tp) return;
    ll z = ceil(cur/a2/t2*((ld)1-numeric_limits<ld>::epsilon()));
    // cout << "HI " << fp << " " << cur << " " << Tp << " " << cur/a2/t2 << " " << z << " " << ind*p1+z*p2 << "\n";
    mn = min(mn,ind*p1+z*p2);
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> f >> T >> t0;
	cin >> a1 >> t1 >> p1;
	cin >> a2 >> t2 >> p2;
	if (t1 > t2) swap(a1,a2), swap(t1,t2), swap(p1,p2);
	
	t1 = min(t1,t0), t2 = min(t2,t0);
	
	F0R(i,T/a1/t1+2) test(i);
	if (mn == 1e18) cout << -1;
	else cout << mn;
}

// read!
// ll vs. int!