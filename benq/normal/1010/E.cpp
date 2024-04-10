
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
const int MX = 100005;
const int SZ = MX;

template<class T> struct node {
    T val;
    node<T>* c[2];
    
    node() {
        val = 0;
        c[0] = c[1] = NULL;    
    }
    
    void upd(int ind, T v, int L = 0, int R = SZ-1) { // add v
        if (L == ind && R == ind) { val += v; return; }
        
        int M = (L+R)/2;
        if (ind <= M) {
            if (!c[0]) c[0] = new node();
            c[0]->upd(ind,v,L,M);
        } else {
            if (!c[1]) c[1] = new node();
            c[1]->upd(ind,v,M+1,R);
        }
        
        val = 0;
        if (c[0]) val += c[0]->val;
        if (c[1]) val += c[1]->val;
    }
    
    T query(int low, int high, int L = 0, int R = SZ-1) { // query sum of segment
        if (low <= L && R <= high) return val;
        if (high < L || R < low) return 0;
        
        int M = (L+R)/2;
        T t = 0;
        if (c[0]) t += c[0]->query(low,high,L,M);
        if (c[1]) t += c[1]->query(low,high,M+1,R);
        return t;
    }
    
    void UPD(int ind, node* c0, node* c1, int L = 0, int R = SZ-1) { // for 2D segtree
        if (L != R) {
            int M = (L+R)/2;
            if (ind <= M) {
                if (!c[0]) c[0] = new node();
                c[0]->UPD(ind,c0 ? c0->c[0] : NULL,c1 ? c1->c[0] : NULL,L,M);
            } else {
                if (!c[1]) c[1] = new node();
                c[1]->UPD(ind,c0 ? c0->c[1] : NULL,c1 ? c1->c[1] : NULL,M+1,R);
            }
        } 
        val = 0;
        if (c0) val += c0->val;
        if (c1) val += c1->val;
    }
};

template<class T> struct SegBit {
    node<T> seg[SZ+1];
    
    SegBit() {
        F0R(i,SZ+1) seg[i] = node<T>();
    }
    
    void upd(int x, int y, int v) { // add v
        for (x++;x <= SZ; x += (x&-x)) seg[x].upd(y,v);
    }
    
    T query(int x, int y1, int y2) {
        T ret = 0;
        for (;x > 0; x -= (x&-x)) ret += seg[x].query(y1,y2);
        return ret;
    }
    
    T query(int x1, int x2, int y1, int y2) { // query sum of rectangle
        return query(x2+1,y1,y2)-query(x1,y1,y2);
    }
};

SegBit<int> S;
int xm,ym,zm,n,m,k,ans[MX];
pi X,Y,Z;
vector<array<int,6>> que[MX];
vpi ad[MX];

void solve() {
    F0R(i,100001) {
        for (auto a: ad[i]) S.upd(a.f,a.s,1);
        for (auto a: que[i]) ans[a[4]] += a[5]*S.query(a[0],a[1],a[2],a[3]);
    }
}

bool in (pi x, int y) {
    return x.f <= y && y <= x.s;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    X = Y = Z = {MOD,-MOD};
    cin >> xm >> ym >> zm >> n >> m >> k;
    F0R(i,n) {
        int x,y,z; cin >> x >> y >> z;
        X.f = min(X.f,x), X.s = max(X.s,x);
        Y.f = min(Y.f,y), Y.s = max(Y.s,y);
        Z.f = min(Z.f,z), Z.s = max(Z.s,z);
    }
    F0R(i,m) {
        int x,y,z; cin >> x >> y >> z;
        ad[x].pb({y,z});
        if (in(X,x) && in(Y,y) && in(Z,z)) {
            cout << "INCORRECT";
            exit(0);
        }
    }
    cout << "CORRECT\n";
    F0R(i,k) {
        int x,y,z; cin >> x >> y >> z;
        if (in(X,x) && in(Y,y) && in(Z,z)) ans[i] = -1;
        else {
            pi XX = {min(X.f,x), max(X.s,x)}, YY = {min(Y.f,y),max(Y.s,y)}, ZZ = {min(Z.f,z),max(Z.s,z)};
            que[XX.f-1].pb({YY.f,YY.s,ZZ.f,ZZ.s,i,-1});
            que[XX.s].pb({YY.f,YY.s,ZZ.f,ZZ.s,i,1});
        }
    }
    solve();
    F0R(i,k) {
        if (ans[i] == -1) cout << "OPEN";
        else if (ans[i] == 0) cout << "UNKNOWN";
        else cout << "CLOSED";
        cout << "\n";
    }
}

/* Look for:
* the exact constraints (multiple sets are too slow for n=10^6 :( ) 
* special cases (n=1?)
* overflow (ll vs int?)
* array bounds
*/