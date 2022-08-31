#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef pair<ll,ll> pl;
typedef pair<double,double> pd;

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
const double PI = 4*atan(1);
const ll INF = 1e18;
const int MX = 1<<17;

int k,n,m;
vpi a,b;

int comb(int a, int b) { return (a+b)%MOD; } // easily change this to min or max

template<class T, int SZ> struct Seg {
    T seg[2*SZ], MN = 0;
    
    Seg() {
        memset(seg,0,sizeof seg);
    }
    
    void upd(int p, T value) {  // set value at position p
        p += SZ;
        for (seg[p] = comb(value,seg[p]); p > 1; p >>= 1)
            seg[p>>1] = comb(seg[(p|1)^1],seg[p|1]); // non-commutative operations
    }
    
    void build() {
        F0Rd(i,SZ) seg[i] = comb(seg[2*i],seg[2*i+1]);
    }
    
    T query(int l, int r) {  // sum on interval [l, r]
        T res1 = MN, res2 = MN; r++;
        for (l += SZ, r += SZ; l < r; l >>= 1, r >>= 1) {
            if (l&1) res1 = comb(res1,seg[l++]);
            if (r&1) res2 = comb(seg[--r],res2);
        }
        return comb(res1,res2);
    }
};

Seg<int,MX> S[2];

bool cmp(pi a, pi b) {
    if (a.f != b.f) return a.f < b.f;
    return a.s > b.s;
}

void red(vpi& x) {
    sort(all(x),cmp);
    vpi X;
    for (auto a: x) {
        while (sz(X) && X.back().s >= a.s) X.pop_back();
        X.pb(a);
    }
    x = X;
}

int nex[2];
vi todo;

ll po(ll b, ll p) {
    return !p?1:po(b*b%MOD,p/2)*(p&1?b:1)%MOD;
}

int get(vpi& x, int t) { // first one such that second coordinate >= t
    int lo = 0, hi = sz(x);
    while (lo < hi) {
        int mid = (lo+hi)/2;
        if (x[mid].s < t) lo = mid+1;
        else hi = mid;
    }
    return lo;
}

int getnex(vpi& x, int t) { // first one such that first coordinate >= t
    int lo = 0, hi = sz(x);
    while (lo < hi) {
        int mid = (lo+hi)/2;
        if (x[mid].f < t) lo = mid+1;
        else hi = mid;
    }
    return lo;
}

void upd(int x, int y) {
    int A = get(a,x), B = get(b,x);
    int q0 = S[0].query(B,MX-1), q1 = S[1].query(A,MX-1);
    // cout << x << " " << y << " " << A << " " << B << " " << q0 << " " << q1 << "\n";
    
    S[1].upd(getnex(a,x),q0); // all black
    S[0].upd(getnex(b,x),q1); // all white
    
    ll t = po(2,y-x+1)-2; t = t*comb(q0,q1)%MOD;
    S[0].upd(getnex(b,y+1),t);
}

void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> k >> n >> m;
    F0R(i,n) {
        int l,r; cin >> l >> r;
        a.pb({l,r});
    }
    red(a);
    F0R(i,m) {
        int l,r; cin >> l >> r;
        b.pb({l,r});
    }
    red(b);
    for (auto x: a) todo.pb(x.f), todo.pb(x.s+1);
    for (auto x: b) todo.pb(x.f), todo.pb(x.s+1);
    todo.pb(1); todo.pb(k+1);
    sort(all(todo)); todo.erase(unique(all(todo)),todo.end());
}

int main() {
    init();
    S[0].upd(0,1);
    F0R(i,sz(todo)-1) upd(todo[i],todo[i+1]-1);
    cout << comb(S[0].query(sz(b),sz(b)),S[1].query(sz(a),sz(a)));
}

// read the question correctly (is y a vowel?)
// look out for special cases (n=1?) and overflow (ll vs int?)