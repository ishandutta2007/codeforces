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

const int MOD = 998244353;
const ll INF = 1e18;
const int MX = 100001;

void setIn(string s) { freopen(s.c_str(),"r",stdin); }
void setOut(string s) { freopen(s.c_str(),"w",stdout); }

void io(string s = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (sz(s)) {
    	setIn(s+".in");
    	setOut(s+".out");
    }
}

namespace modOp {
    ll po (ll b, ll p) { return !p?1:po(b*b%MOD,p/2)*(p&1?b:1)%MOD; }
    ll inv (ll b) { return po(b,MOD-2); }
    
    ll inv(ll a, ll b) { // 0 < a < b, gcd(a,b) = 1
        a %= b;
        if (a <= 1) return a;
        ll i = inv(b%a,a);
        ll tmp = -((b/a)*i+((b%a)*i)/a) % b;
        if (tmp < 0) tmp += b;
        return tmp;
    }
    
    int ad(int a, int b) { return (a+b)%MOD; }
    int sub(int a, int b) { return (a-b+MOD)%MOD; }
    int mul(int a, int b) { return (ll)a*b%MOD; }
    
    int AD(int& a, int b) { return a = ad(a,b); }
    int SUB(int& a, int b) { return a = sub(a,b); }
    int MUL(int& a, int b) { return a = mul(a,b); }
}

using namespace modOp;

int cnum, csum;
pi cx, cy;
int n,m,ans[1000][1000],a[1000][1000];

void gen(pi x) {
    if (cnum == 0) return;
    ans[x.f][x.s] = csum;
    AD(ans[x.f][x.s],ad(sub(cx.s,mul(mul(2,x.f),cx.f)),mul(mul(x.f,x.f),cnum)));
    AD(ans[x.f][x.s],ad(sub(cy.s,mul(mul(2,x.s),cy.f)),mul(mul(x.s,x.s),cnum)));
    MUL(ans[x.f][x.s],inv(cnum));
}

void ad(pi x) {
    cnum ++;
    AD(csum,ans[x.f][x.s]);
    AD(cx.f,x.f); AD(cx.s,x.f*x.f);
    AD(cy.f,x.s); AD(cy.s,x.s*x.s);
}

int main() {
    io();
    cin >> n >> m;
    F0R(i,n) F0R(j,m) cin >> a[i][j];
    int r, c; cin >> r >> c; r--, c--;
    vpi v; F0R(i,n) F0R(j,m) v.pb({i,j});
    sort(all(v),[](pi x, pi y) { return a[x.f][x.s] < a[y.f][y.s]; });
    for (int i = 0; i < sz(v); ) {
        int I = i;
        while (i < sz(v) && a[v[i].f][v[i].s] == a[v[I].f][v[I].s]) i ++;
        FOR(j,I,i) gen(v[j]);
        FOR(j,I,i) ad(v[j]);
    }
    cout << ans[r][c];
}

/* 
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/