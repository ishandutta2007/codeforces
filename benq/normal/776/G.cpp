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
const int MX = 100001;

int q;
ll cum[1<<16][16][2];

int getVal(char c) {
    if ('0' <= c && c <= '9') return c-'0';
    return 10+(c-'a');
}

ll con(string s) {
    ll cur = 0;
    F0R(i,sz(s)) cur = 16*cur+getVal(s[i]);
    return cur;
}

int getHigh(ll x) {
    int ret = 0;
    while (x) {
        ret = max(ret,int(x%16));
        x /= 16;
    }
    return ret;
}

pl lef[15][16];

pl operator+(const pl& l, const pl& r) { return {l.f+r.f,l.s+r.s}; }

pl get(ll x, int y) {
    vi v; 
    while (x) { v.pb(x%16); x /= 16; }
    reverse(all(v));
    // for (int i: v) cout << i << " ";
    // cout << "\n";
    pl cur = {0,0}; // not equal, equal
    
    bool eq = 0;
    F0R(i,sz(v)) {
        pl z = lef[sz(v)-1-i][y];
        // cout << "HA " << sz(v)-1-i << " " << y << " " << z.f << " " << z.s << "\n";
        F0R(j,v[i]) {
            if (j < y) {
                if (eq) cur.s += z.f+z.s;
                else cur.f += z.f, cur.s += z.s;
            } else if (j == y) cur.s += z.f+z.s;
            else if (j > y) return cur;
        }
        if (v[i] == y) eq = 1;
        else if (v[i] > y) break;
    }
    
    return cur;
}

ll solve(ll x, int y) {
    if (x < 0) return 0LL;
    ll ans = 0;
    pl t = get(x>>16,y);
    
    ans += t.f*cum[(1<<16)-1][y][1];
    ans += t.s*(cum[(1<<16)-1][y][1]+cum[(1<<16)-1][y][0]);
    
    int g = getHigh(x>>16);
    if (g < y) ans += cum[x%(1<<16)][y][1];
    else if (g == y) ans += cum[x%(1<<16)][y][1]+cum[x%(1<<16)][y][0];
    
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    F0R(i,1<<16) {
        int g = getHigh(i);
        F0R(j,16) {
            if (i) F0R(k,2) cum[i][j][k] = cum[i-1][j][k];
            if (j >= g) {
                if (i&(1<<j)) cum[i][j][j == g] ++;
            } 
        }
    }
    F0R(i,15) F0R(j,16) {
        if (i == 0) lef[i][j] = {1,0};
        else {
            lef[i][j].f = j*lef[i-1][j].f;
            lef[i][j].s = lef[i-1][j].f+(j+1)*lef[i-1][j].s;
            // cout << i << " " << j << " " << lef[i][j].f << " " << lef[i][j].s << "\n";
        }
    }
    
    cin >> q;
    F0R(i,q) {
        string l,r; cin >> l >> r;
        ll L = con(l), R = con(r);
        ll ans = 0;
        FOR(j,1,16) ans += solve(R,j)-solve(L-1,j);
        cout << ans << "\n";
    }
}

/* Look for:
* the exact constraints (multiple sets are too slow for n=10^6 :( ) 
* special cases (n=1?)
* overflow (ll vs int?)
* array bounds
* if you have no idea just guess the appropriate well-known algo instead of doing nothing :/
*/