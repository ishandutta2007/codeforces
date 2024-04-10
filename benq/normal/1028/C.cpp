#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/rope>

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
 
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
const int MX = 200001;

int n;
pair<pi,pi> tmp[MX], cum[MX];

pi comb(pi a, pi b) {
    return {max(a.f,b.f),min(a.s,b.s)};
}

pair<pi,pi> comb(pair<pi,pi> x, pair<pi,pi> y) {
    return {comb(x.f,y.f),comb(x.s,y.s)};
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    cum[0] = {{-MOD,MOD},{-MOD,MOD}};
    FOR(i,1,n+1) {
        int x1,y1,x2,y2; cin >> x1 >> y1 >> x2 >> y2;
        tmp[i] = {{x1,x2},{y1,y2}};
    }
    FOR(i,1,n+1) cum[i] = comb(cum[i-1],tmp[i]);
    pair<pi,pi> z = cum[0];
    FORd(i,1,n+1) {
        auto t = comb(cum[i-1],z);
        if (t.f.f <= t.f.s && t.s.f <= t.s.s) {
            cout << t.f.f << " " << t.s.f;
            exit(0);
        }
        z = comb(z,tmp[i]);
    }
}

/* Look for:
* the exact constraints (multiple sets are too slow for n=10^6 :( ) 
* special cases (n=1?)
* overflow (ll vs int?)
* array bounds
* if you have no idea just guess the appropriate well-known algo instead of doing nothing :/
*/