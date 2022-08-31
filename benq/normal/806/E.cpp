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
const int MX = 1<<19;

template<class T, int SZ> struct LazySegTree {
    T mx[2*SZ], mn[2*SZ], lazy[2*SZ]; // set SZ to a power of 2
    
    LazySegTree() {
        F0R(i,2*SZ) {
            mn[i] = MOD; // min value of a_y-y
            mx[i] = -MOD; // max value of a_x+x 
            lazy[i] = 0;
        }
    }
    
    void push(int ind, int L, int R) {
        mn[ind] -= lazy[ind]; mx[ind] += lazy[ind];
        if (L != R) lazy[2*ind] += lazy[ind], lazy[2*ind+1] += lazy[ind];
        lazy[ind] = 0;
    }
    
    void pull(int ind) {
        mn[ind] = min(mn[2*ind],mn[2*ind+1]);
        mx[ind] = max(mx[2*ind],mx[2*ind+1]);
    }
    
    void upd0(int pos, int val, int ind = 1, int L = 0, int R = SZ-1) {
        push(ind,L,R);
        if (L > pos || R < pos) return;
        if (L == pos && R == pos) {
            mx[ind] += val+MOD; mn[ind] += val-MOD;
            return;
        }
        int M = (L+R)/2;
        upd0(pos,val,2*ind,L,M);
        upd0(pos,val,2*ind+1,M+1,R);
        pull(ind);
    }
    
    int query0(int ind = 1, int L = 0, int R = SZ-1) {
        push(ind,L,R);
        if (mx[ind] < 0) return MOD;
        if (L == R) return L;
        int M = (L+R)/2;
        int x = query0(2*ind,L,M); if (x < MOD) return x;
        return query0(2*ind+1,M+1,R);
    }
    
    int query1(int pos, int ind = 1, int L = 0, int R = SZ-1) {
        push(ind,L,R);
        if (pos <= L) return mn[ind];
        if (pos > R) return MOD;
        int M = (L+R)/2;
        return min(query1(pos,2*ind,L,M),query1(pos,2*ind+1,M+1,R));
    }
    
    void upd1(int pos, int ind = 1, int L = 0, int R = SZ-1) {
        push(ind,L,R);
        if (pos > R) return;
        if (pos <= L) {
            lazy[ind] = 1;
            push(ind,L,R);
            return;
        }
        int M = (L+R)/2;
        upd1(pos,2*ind,L,M); upd1(pos,2*ind+1,M+1,R);
        pull(ind);
    }
};

LazySegTree<int,MX> L;

int n, a[MX];
map<int,int> co, pos;

void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    F0R(i,n) {
        cin >> a[i];
        co[a[i]] ++;
    }
    int cur = 0;
    for (auto x: co) {
        pos[x.f] = cur;
        cur += x.s;
    }
}

int main() {
    init();
    Tree<int> T;
    F0R(i,n) {
        int p = pos[a[i]]++;
        L.upd0(p,a[i]); 
        L.upd1(p+1); 
        T.insert(p);
        int x = L.query0(); // first index such that a[i] >= -i, a[i]+i >= 0 
            // cout << x << " " << i-2*(int)T.order_of_key(x)+1 << " ";
            // F0R(i,10) cout << L.query1(i) << " ";
        cout << min(i-2*(int)T.order_of_key(x)+1,L.query1(x)+i) << "\n";
    }
}

/* Look for:
* the exact constraints (multiple sets are too slow for n=10^6 :( ) 
* special cases (n=1?)
* overflow (ll vs int?)
* array bounds
* if you have no idea just guess the appropriate well-known algo instead of doing nothing :/
*/