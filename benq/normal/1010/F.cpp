#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

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

const int MOD = (119 << 23) + 1; // = 998244353
const ll INF = 1e18;
const int MX = 100001;

ll po(ll b, ll p) { return !p?1:po(b*b%MOD,p/2)*(p&1?b:1)%MOD; }
ll inv (ll b) { return po(b,MOD-2); }

int mul(int a, int b) { return (ll)a*b%MOD; }
int ad(int a, int b) { return (a+b)%MOD; }
int sub(int a, int b) { return (a-b+MOD)%MOD; }
int get(int s) { return s > 1 ? 32 - __builtin_clz(s - 1) : 0; }

vi operator+(const vi& l, const vi& r) {
    vi res(max(sz(l),sz(r)));
    F0R(i,sz(l)) res[i] = l[i];
    F0R(i,sz(r)) res[i] = ad(res[i],r[i]);
    return res;
}

vi operator-(const vi& l, const vi& r) {
    vi res(max(sz(l),sz(r)));
    F0R(i,sz(l)) res[i] = l[i];
    F0R(i,sz(r)) res[i] = sub(res[i],r[i]);
    return res;
}

namespace NTT {
    const int root = 3; 
    // For p < 2^30 there is also e.g. (5 << 25, 3), (7 << 26, 3),
    // (479 << 21, 3) and (483 << 21, 5). The last two are > 10^9.
        
    
    vi ntt(vi& a) { 
        int n = a.size(), x = get(n); 
        vi res, RES(n), roots(n);
        roots[0] = 1, roots[1] = po(root,(MOD-1)/n);
        FOR(i,2,n) roots[i] = mul(roots[i-1],roots[1]);
        
        res = a;
        FOR(i,1,x+1) {
            int inc = n>>i;
            F0R(j,inc) for (int k = 0; k < n; k += inc) {
                int t = 2*k%n+j;
                RES[k+j] = ad(res[t],mul(roots[k],res[t+inc]));
            }
            swap(res,RES);
        }
        
        return res;
    }
    
    vi ntt_rev(vi& a) {
        vi res = ntt(a);
        ll in = inv(sz(a));
        F0R(i,sz(res)) res[i] = mul(res[i],in);
        reverse(res.begin() + 1, res.end());
        return res;
    }
    
    vi brute(vi& a, vi& b) {
        vi c(sz(a)+sz(b)-1);
        F0R(i,sz(a)) F0R(j,sz(b)) c[i+j] = ad(c[i+j],mul(a[i],b[j]));
        return c;
    }
    
    vi conv(vi a, vi b) {
        int s = sz(a)+sz(b)-1, L = get(s), n = 1<<L;
        if (s <= 0) return {};
        if (s <= 200) return brute(a,b);
        
        a.resize(n); a = ntt(a);
        b.resize(n); b = ntt(b);
        
        F0R(i,n) a[i] = mul(a[i],b[i]);
        a = ntt_rev(a);
        
        a.resize(s);
        return a;
    }
    
    pair<vi,vi> eval(vector<vi> a) { // a_1a_2a_3a_4+a_2a_3a_4+a_3a_4+a_4+1,a_1a_2a_3a_4
        if (sz(a) == 1) {
            auto A = a[0]; A[0] ++;
            return {A,a[0]};
        }
        auto P = eval(vector<vi>(a.begin(),a.begin()+sz(a)/2));
        auto Q = eval(vector<vi>(a.begin()+sz(a)/2,a.end()));
        P.f[0] = sub(P.f[0],1);
        return {NTT::conv(P.f,Q.s)+Q.f,NTT::conv(P.s,Q.s)};
    }
}

int n, sz[MX];
ll x;
vi adj[MX];
vector<vi> dat[MX];

void dfs(int a, int b) {
    sz[a] ++;
    
    vi child;
    for (int i: adj[a]) if (i != b) {
        dfs(i,a);
        sz[a] += sz[i];
        child.pb(i);
    }
    
    switch(sz(child)) {
        case 0:
            dat[a].pb({0,1});
            break;
        case 1:
            swap(dat[a],dat[child[0]]);
            dat[a].pb({0,1});
            break;
        default:
            if (sz[child[0]] < sz[child[1]]) swap(child[0],child[1]);
            swap(dat[child[0]],dat[a]);
            auto x = NTT::eval(dat[child[1]]).f; x.insert(x.begin(),0);
            dat[a].pb(x);
            break;
    }   
    
    /*cout << "HI " << a << " " << sz(child) << "\n";
    for (auto x: dat[a]) {
        for (int y: x) cout << y << " ";
        cout << "\n";
    }
    cout << "----\n";*/
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> x; x %= MOD;
    F0R(i,n-1) {
        int a,b; cin >> a >> b;
        adj[a].pb(b), adj[b].pb(a);
    }
    dfs(1,0);
    vi v = NTT::eval(dat[1]).f;
    
    int ans = 0, ccomb = 1;
    FOR(i,1,n+1) {
        ans = ad(ans,mul(v[i],ccomb));
        ccomb = mul(ccomb,ad(x,i));
        ccomb = mul(ccomb,inv(i));
    }
    cout << ans;
}

/* Look for:
* the exact constraints (multiple sets are too slow for n=10^6 :( ) 
* special cases (n=1?)
* overflow (ll vs int?)
* array bounds
*/