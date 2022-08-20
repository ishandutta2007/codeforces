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
const int SZ = 1<<17;

void MX(int& a, int b) { a = max(a,b); }

struct Seg {
    int lazy[2*SZ];
    pi mx[2*SZ];
    
    Seg() {
        F0R(i,SZ) mx[i+SZ] = {i,-MOD};
        FORd(i,1,SZ) pull(i);
    }
    
    void push(int ind, int L, int R) {
        if (!lazy[ind]) return;
        if (L != R) {
            if (max(lazy[2*ind],mx[2*ind].f) == mx[ind].f) lazy[2*ind] = lazy[ind];
            if (max(lazy[2*ind+1],mx[2*ind+1].f) == mx[ind].f) lazy[2*ind+1] = lazy[ind];
        }
        mx[ind].f = lazy[ind]; lazy[ind] = 0;
    }
    
    void pull(int ind) {
        mx[ind].f = max(mx[2*ind].f,mx[2*ind+1].f);
        mx[ind].s = max(mx[2*ind].s,mx[2*ind+1].s);
        if (mx[ind].f != mx[2*ind].f) MX(mx[ind].s,mx[2*ind].f);
        if (mx[ind].f != mx[2*ind+1].f) MX(mx[ind].s,mx[2*ind+1].f);
    }
    
    void upd(int pos, int val, int ind = 1, int L = 0, int R = SZ-1) {
        push(ind,L,R);
        /*cout << "ZZ " << pos << " " << val << " " << ind << " " << L << " " << R << "\n";
        cout << mx[ind].f << " " << mx[ind].s << "\n";*/
        if (pos < L) return;
        if (pos >= R) {
            if (mx[ind].f < pos) return;
            if (mx[ind].s < pos) {
                lazy[ind] = val;
                //cout << "HI " << ind << " " << L << " " << R << " " << lazy[ind] << " " << mx[ind].f << " " << mx[ind].s << "\n";
                push(ind,L,R);
                //cout << "HI " << ind << " " << L << " " << R << " " << lazy[ind] << " " << mx[ind].f << " " << mx[ind].s << "\n";
                return;
            }
        }
        int M = (L+R)/2;
        upd(pos,val,2*ind,L,M); upd(pos,val,2*ind+1,M+1,R);
        pull(ind);
    }
    
    int get(int pos, int ind = 1, int L = 0, int R = SZ-1) {
        push(ind,L,R);
        //cout << ind << " " << L << " " << R << " " << mx[ind].f << " " << mx[ind].s << "\n";
        if (L == R) return mx[ind].f;
        int M = (L+R)/2;
        if (pos <= M) return get(pos,2*ind,L,M);
        return get(pos,2*ind+1,M+1,R);
    }
};

Seg S;

int n,m,res[SZ],ans[SZ];
vpi query[SZ];

void process(int r) {
    if (res[r]) {
        S.upd(res[r],r);
    }
    for (auto a: query[r]) ans[a.s] = S.get(a.f);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    F0R(i,m) {
        int l,r; cin >> l >> r;
        res[r] = l;
    }
    int q; cin >> q;
    F0R(i,q) {
        int x,y; cin >> x >> y;
        query[y].pb({x,i});
    }
    FOR(i,1,n+1) process(i);
    F0R(i,q) cout << ans[i] << "\n";
}

/* Look for:
* the exact constraints (multiple sets are too slow for n=10^6 :( ) 
* special cases (n=1?)
* overflow (ll vs int?)
* array bounds
* if you have no idea just guess the appropriate well-known algo instead of doing nothing :/
*/