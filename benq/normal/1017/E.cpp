
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

int n,m;

ll dist(pi A, pi B) {
    A.f -= B.f, A.s -= B.s;
    return (ll)A.f*A.f+(ll)A.s*A.s;
}

ll dot(pi O, pi A, pi B) {
    return (ll)(A.f-O.f)*(B.f-O.f)+(ll)(A.s-O.s)*(B.s-O.s);
}

ll cross(pi O, pi A, pi B) {
    return (ll)(A.f-O.f)*(B.s-O.s)
            -(ll)(A.s-O.s)*(B.f-O.f);
}

vpi convex_hull(vpi P) {
    sort(all(P)); P.erase(unique(all(P)),P.end());
    int n = sz(P);
    if (n == 1) return P;
    
    vpi bot = {P[0]};
    FOR(i,1,n) {
        while (sz(bot) > 1 && cross(bot[sz(bot)-2], bot.back(), P[i]) <= 0) bot.pop_back();
        bot.pb(P[i]);
    }
    bot.pop_back();
    
    vpi up = {P[n-1]};
    F0Rd(i,n-1) {
        while (sz(up) > 1 && cross(up[sz(up)-2], up.back(), P[i]) <= 0) up.pop_back();
        up.pb(P[i]);
    }
    up.pop_back();
    
    bot.insert(bot.end(),all(up));
    return bot;
}

int min_rotation(vl s) {
	int a=0, N=sz(s); 
	s.insert(s.end(),all(s));
	F0R(b,N) F0R(i,N) {
		if (a+i == b || s[a+i] < s[b+i]) {b += max(0, i-1); break;}
		if (s[a+i] > s[b+i]) { a = b; break; }
	}
	return a;
}

vl rot_min(vl v) {
    int x = min_rotation(v);
    rotate(v.begin(),v.begin()+x,v.end());
    return v;
}

vl hsh(vpi x) {
    vl v;
    F0R(i,sz(x)) {
        v.pb(dist(x[i],x[(i+1)%sz(x)]));
        v.pb(4*INF+dot(x[i],x[(i+1)%sz(x)],x[(i+2)%sz(x)]));
    }
    return v;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    vpi x(n), y(m);
    F0R(i,n) cin >> x[i].f >> x[i].s;
    F0R(i,m) cin >> y[i].f >> y[i].s;
    x = convex_hull(x), y = convex_hull(y);
    vl X = hsh(x), Y = hsh(y);
    X = rot_min(X);
    Y = rot_min(Y);
    //for (auto a: X) cout << a << " ";
    //cout << "\n";
    if (X == Y) cout << "YES";
    else cout << "NO";
}

/* Look for:
* the exact constraints (multiple sets are too slow for n=10^6 :( ) 
* special cases (n=1?)
* overflow (ll vs int?)
* array bounds
*/