#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<ll, ll> pl;
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
const int MX = 100000;
const ll INF = 1e18;

template<class T, int SZ> struct Seg {
    T seg[2*SZ], MN = {-1e18,1e18};
    
    Seg() {
        memset(seg,0,sizeof seg);
    }
    
    T comb(T a, T b) { return {max(a.f,b.f),min(a.s,b.s)}; } // easily change this to min or max
    
    void upd(int p, ll value) {  // set value at position p
        p += SZ;
        seg[p].f += value, seg[p].s += value;
        for (; p > 1; p >>= 1)
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

int n, q;

struct {
    ll dif[MX], sum = 0;
    Seg<pl,1<<17> S;
    set<int> cand;
    
    void ad(int l) { // neg, pos
        if (l > 0 && l < n-1 && dif[l-1] <= 0 && dif[l] >= 0)
            cand.insert(l);
    }
    
    void rem(int l) {
        if (cand.count(l)) cand.erase(l);
    }
    
    void upd(int l, int x) {
        if (l < 0 || l >= n-1) return;
        rem(l), rem(l+1);
        
        sum -= abs(dif[l]);
        dif[l] += x;
        S.upd(l,x);
        sum += abs(dif[l]);
        
        ad(l); ad(l+1);
    }
    void upd(int l, int r, int x) {
        upd(l-1,-x);
        upd(r,x);
    }
    
    bool ok(int l, int r) {
        auto it = cand.lb(l);
        return it != cand.end() && *it <= r; 
    }
    
    ll tri(int en, int x) {
        ll ret = 0;
        if (en != n-1) ret += abs(dif[en]+x)-abs(dif[en]);
        if (en != 0) ret += abs(dif[en-1]-x)-abs(dif[en-1]);
        return ret;
    }
    
    ll getposneg(int l, int r, int x) {
        if (l > r) return -INF;
        ll mx = -INF;
        FOR(i,l,r+1) mx = max(mx,tri(i,x));
        return mx;
    }
    
    ll getneg(int l, int r, int x) {
        if (l > r) return -INF;
        ll t = S.query(l,r).f;
        // cout << "AH " << l << " " << r << " " << t << " " << x+abs(t+x)-abs(t) << "\n";
        return x+abs(t+x)-abs(t);
    }
    
    ll getpos(int l, int r, int x) {
        if (l > r) return -INF;
        ll t = S.query(l-1,r-1).s;
        return x+abs(t-x)-abs(t);
    }
    
    ll solve(int l, int r, int x) {
        if (l > r) return -INF;
        int lo = l-1, hi = r;
        while (lo < hi) { // last pos, pos
            int mid = (lo+hi+1)/2;
            if (dif[mid-1] >= 0 && dif[mid] >= 0) lo = mid;
            else hi = mid-1;
        }
        
        int LO = l, HI = r+1;
        while (LO < HI) { // last neg, neg
            int mid = (LO+HI)/2;
            if (dif[mid-1] <= 0 && dif[mid] <= 0) HI = mid;
            else LO = mid+1;
        }
        
        return max(max(getpos(l,lo,x),getposneg(lo+1,LO-1,x)),getneg(LO,r,x));
    }
    
    ll naive(int l, int r, int x) {
        ll mx = -1e18;
        FOR(i,l,r+1) mx = max(mx,tri(i,x));
        return mx+sum;
    }
    
    ll query(int l, int r, int x) {
        if (ok(l,r)) return sum+2*x;
        
        ll t = -1e18;
        if (l == 0) t = max(t,tri(l++,x));
        if (r == n-1) t = max(t,tri(r--,x));
    
        return max(t,solve(l,r,x))+sum;
    }
} val;

void input() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    F0R(i,n) val.ad(i);
    F0R(i,n) {
        int a; cin >> a;
        val.upd(i,i,a);
    }
    cin >> q;
} // OK

int main() {
    input();
    F0R(i,q) {
        int t,l,r,x; cin >> t >> l >> r >> x;
        // t = rand() % 2+1, l = rand() % 50+1, r = rand() % 50+1, x = rand() % MOD;
        // if (l > r) swap(l,r);
        l --, r --;
        if (t == 1) cout << val.query(l,r,x) << "\n";
        else val.upd(l,r,x);
    }
} // OK

// read the question correctly (is y a vowel?)
// look out for special cases (n=1?) and overflow (ll vs int?)