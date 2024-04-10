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

void setIn(string s) { freopen(s.c_str(),"r",stdin); }
void setOut(string s) { freopen(s.c_str(),"w",stdout); }

void io(string s = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (sz(s)) {
    	setIn(s+".in");
    	setOut(s+".out");
    }
}


namespace {
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
    
    void nor(ll& a) { a = (a%MOD+MOD)%MOD; }
    ll ad(ll a, ll b) { nor(a); nor(b); return (a+b)%MOD; }
    ll sub(ll a, ll b) { nor(a); nor(b); return (a-b+MOD)%MOD; }
    ll mul(ll a, ll b) { nor(a); nor(b); return (ll)a*b%MOD; }
    
    ll AD(ll& a, ll b) { return a = ad(a,b); }
    //int SUB(int& a, int b) { return a = sub(a,b); }
}

int n,q,a[MX],w[MX];

template<class T, int SZ> struct BIT {
    T bit[SZ+1];
    
    BIT() { memset(bit,0,sizeof bit); }
    
    void upd(int k, T val) { // add val to index k
        for( ;k <= SZ; k += (k&-k)) bit[k] += val;
    }
    
    T query(int k) {
        T temp = 0;
        for (;k > 0;k -= (k&-k)) temp += bit[k];
        return temp;
    }
    T query(int l, int r) { return query(r)-query(l-1); } // range query [l,r]
};

BIT<ll,MX> W, prod;

int lstLeft(int x) {
    int L = 0, R = n;
    while (L < R) {
        int M = (L+R+1)/2;
        if (a[M] <= x) L = M;
        else R = M-1;
    }
    return L;
}

int solve(int l, int r) {
    int L = a[l], R = a[r];
    ll wei = W.query(l,r);
    while (1) {
        int M = (L+R)/2;
        int ind = min(lstLeft(M),r);
        ll tmp = W.query(l,ind);
        if (L < R) {
            if (tmp > wei-tmp) R = M;
            else L = M+1;
        } else {
            ll ans = sub(mul(tmp,L),prod.query(l,ind));
            AD(ans,sub(prod.query(ind+1,r),mul(wei-tmp,L)));
            return ans;
        }
    }
}

void upd(int x, int y) {
    W.upd(x,-w[x]);
    prod.upd(x,-mul(w[x],a[x]));
    
    w[x] = y;
    
    W.upd(x,w[x]);
    prod.upd(x,mul(w[x],a[x]));
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> q;
    FOR(i,1,n+1) { cin >> a[i]; a[i] -= i; }
    FOR(i,1,n+1) {
        int t; cin >> t;
        upd(i,t);
    }
    F0R(i,q) {
        int x,y; cin >> x >> y;
        if (x < 0) {
            upd(-x,y);
        } else {
            cout << solve(x,y) << "\n";
        }
    }
}

/* 
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/