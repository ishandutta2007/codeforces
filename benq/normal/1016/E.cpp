
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
const int MX = 200005;

int sy,n;
pi p[MX];
pd des;
ld cum[MX];

ld scale(pi x, ld z) {
    return (ld)z*(x.s-sy)/x.s;
}

ld inter(pd a, pd b) {
    a.f = max(a.f,b.f);
    a.s = min(a.s,b.s);
    return max((ld)0,a.s-a.f);
}

pd get(pi x, pi z) {
    ld fac = (ld)(x.s-sy)/x.s;
    return {(z.f-x.f)*fac+x.f,(z.s-x.f)*fac+x.f};
}

int getFst(pi x) {
    int l = 0, r = n;
    while (l < r) {
        int m = (l+r)/2;
        pd z = get(x,p[m]);
        if (z.s >= des.f) r = m;
        else l = m+1;
    }
    return l;
}

int getLst(pi x) {
    int l = -1, r = n-1;
    while (l < r) {
        int m = (l+r+1)/2;
        pd z = get(x,p[m]);
        if (z.f <= des.s) l = m;
        else r = m-1;
    }
    return l;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> sy >> des.f >> des.s >> n;
    F0R(i,n) {
        cin >> p[i].f >> p[i].s;
        cum[i+1] = cum[i]+p[i].s-p[i].f;
    }
    cout << fixed << setprecision(9);
    int q; cin >> q;
    F0R(i,q) {
        pi x; cin >> x.f >> x.s;
        int l = getFst(x);
        int r = getLst(x);
        if (l > r) {
            cout << "0\n";
            continue;
        }
        if (l == r) {
            cout << inter(des,get(x,p[l])) << "\n";
            continue;
        }
        ld ans = scale(x,cum[r]-cum[l+1]);
        ans += inter(des,get(x,p[l]));
        ans += inter(des,get(x,p[r]));
        cout << ans << "\n";
    }
}

/* Look for:
* the exact constraints (multiple sets are too slow for n=10^6 :( ) 
* special cases (n=1?)
* overflow (ll vs int?)
* array bounds
*/