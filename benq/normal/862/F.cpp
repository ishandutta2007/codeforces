#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
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
const int MX = 100000;
const int LIM = 78; // set to 78

template<class T, int SZ> struct MaxSeg {
    T seg[2*SZ], MN = 0;
    
    MaxSeg() {
        memset(seg,0,sizeof seg);
    }
    
    T comb(T a, T b) { return max(a,b); } // easily change this to min or max
    
    void upd(int p, T value) {  // set value at position p
        for (seg[p += SZ] = value; p > 1; p >>= 1) seg[p>>1] = comb(seg[p],seg[p^1]);
    }
    
    void build() {
        F0Rd(i,SZ) seg[i] = comb(seg[2*i],seg[2*i+1]);
    }
    
    T query(int l, int r) {  // sum on interval [l, r]
        T res = MN; r++;
        for (l += SZ, r += SZ; l < r; l >>= 1, r >>= 1) {
            if (l&1) res = comb(res,seg[l++]);
            if (r&1) res = comb(res,seg[--r]);
        }
        return res;
    }
};

MaxSeg<int,1<<17> maxseg;

template<class T, int SZ> struct Seg {
    T seg[2*SZ], MN = {0,0,0,0};
    
    Seg() {
        memset(seg,0,sizeof seg);
    }
    
    T comb(T a, T b) { 
        T c; 
        c[0] = a[0]+b[0];
        c[1] = max(max(a[1],b[1]), a[3]+b[2]);
        c[2] = (a[2] == a[0] ? a[0]+b[2] : a[2]);
        c[3] = (b[3] == b[0] ? a[3]+b[0] : b[3]);
        return c;
    } 
    
    void upd(int p, T value) {  // set value at position p
        for (seg[p += SZ] = value; p > 1; p >>= 1) seg[p>>1] = comb(seg[(p|1)^1],seg[p|1]);
    }
    
    void build() {
        F0Rd(i,SZ) seg[i] = comb(seg[2*i],seg[2*i+1]);
    }
    
    int query(int l, int r) {  // sum on interval [l, r]
        T res = MN, res1 = MN; r++;
        for (l += SZ, r += SZ; l < r; l >>= 1, r >>= 1) {
            if (l&1) res = comb(res,seg[l++]);
            if (r&1) res1 = comb(seg[--r],res1);
        }
        return comb(res,res1)[1];
    }
};

Seg<array<int,4>,1<<17> seg[LIM]; // len, max value, left, right

int n,q;
string S[MX];
map<int,int> z;
int lcp[MX];

void gen(int x) {
    if (x == n-1 || x == -1) return;
    if (z.count(x)) z.erase(x);
    
    lcp[x] = 0;
    F0R(i,min(sz(S[x]),sz(S[x+1]))) {
        if (S[x][i] != S[x+1][i]) break;
        lcp[x] ++;
    }
    FOR(i,1,LIM) if (i <= lcp[x]) seg[i].upd(x,{1,1,1,1});
    else seg[i].upd(x,{1,0,0,0});
    
    if (lcp[x] >= LIM) z[x] = lcp[x];
}

int brute(int a, int b) {
    auto it = z.lb(a);
    int ret = 0;
    
    vector<pii> cur;
    while (it != z.end() && it->f <= b) {
        int fst = it->f;
        while (sz(cur) && cur.back().s >= it->s) {
            ret = max(ret,(it->f+1-cur.back().f)*cur.back().s);
            fst = cur.back().f;
            cur.pop_back();
        }
        cur.pb({fst,it->s});
        
        if (next(it) == z.end() || next(it)->f != it->f+1 || next(it)->f > b) {
            while (sz(cur)) {
                ret = max(ret,(it->f+2-cur.back().f)*cur.back().s);
                cur.pop_back();
            }
        }
        it = next(it);
    }
    
    return ret;
}

int query(int a, int b) {
    int ans = 0;
    FOR(i,1,LIM) {
        int t = seg[i].query(a,b-1);
        if (t > 0) ans = max(ans,i*(t+1));
    }
    ans = max(ans,brute(a,b-1));
    ans = max(ans,maxseg.query(a,b));
    return ans;
}

int main() {
    cin >> n >> q;
    F0R(i,n) {
        cin >> S[i];
        maxseg.upd(i,sz(S[i]));
    }
    F0R(i,n-1) {
        gen(i);
        // cout << seg[10].query(0,3) << "\n";
    }
    
    F0R(i,q) {
        int t; cin >> t;
        if (t == 1) {
            int a,b; cin >> a >> b; a--, b--;
            cout << query(a,b) << "\n";
        } else {
            int x; string y; cin >> x >> y; x--;
            maxseg.upd(x,sz(y));
            S[x] = y;
            gen(x-1), gen(x);
        }
    }
}