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
const int MX = 2000001;

void setIn(string s) { freopen(s.c_str(),"r",stdin); }
void setOut(string s) { freopen(s.c_str(),"w",stdout); }

void io(string s = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (sz(s)) {
    	setIn(s+".in");
    	setOut(s+".out");
    }
}

int n;
vi p;
int oc[MX];
bitset<MX> comp, need;
ll cans = 1;

bool test(int x) {
    for (int i = x; i < MX; i += x) if (oc[i]) return 1;
    return 0;
}

void solve(int x) {
    pair<int,vi> ret = {0,{}};
    for (int i = x; i < MX; i += x) {
        comp[i] = 1;
        if (oc[i]) {
            int I = i, num = 0; while (I % x == 0) I /= x, num ++;
            if (ret.f < num) ret.f = num, ret.s = {};
            if (ret.f == num && num > 0) ret.s.pb(i);
        }
    }
    if (sz(ret.s) == 1) need[ret.s[0]] = 1;
    F0R(i,ret.f) cans = cans*x%MOD;
}

void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n; p.resize(n);
    F0R(i,n) cin >> p[i]; sort(all(p)); reverse(all(p));
    for (int i = 0; i < sz(p); ) {
        int I = i;
        while (i < sz(p) && p[i] == p[I]) i ++;
        bool b = test(p[I]);
        F0R(j,i-I) {
            if (!b) oc[p[I]] ++, b = 1;
            else oc[p[I]-1] ++;
        }
    }
}

int main() {
    init();
    FOR(i,2,MX) if (!comp[i]) solve(i);
    int nee = 0; FOR(i,1,MX) if (need[i]) nee ++;
    if (nee != n) cans = (cans+1)%MOD;
    cout << cans;
}

/* 
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/