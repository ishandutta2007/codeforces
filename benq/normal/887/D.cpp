#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<ll,ll> pll;
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

typedef pll T;

const int MOD = 1000000007;

int lo = 0, hi = -1;
int n,a,b,c,d,start,len;
int t[300005], q[300005];

T comb(T a, T b) { 
    return {a.f+b.f,min(a.s,a.f+b.s)};
} 

template<int SZ> struct Seg {
    T seg[2*SZ];
    
    Seg() {
        memset(seg,0,sizeof seg);
    }
    
    void upd(int p, T value) {  // set value at position p
        for (seg[p += SZ] = value; p > 1; p >>= 1) {
            seg[p>>1] = comb(seg[(p|1)^1],seg[p|1]);
        }
    }
    
    void build() {
        F0Rd(i,SZ) seg[i] = comb(seg[2*i],seg[2*i+1]);
    }
    
    T query(int l, int r) {  // sum on interval [l, r]
        r ++;
        pll le = {0,0}, ri = {0,0};
        for (l += SZ, r += SZ; l < r; l >>= 1, r >>= 1) {
            if (l&1) le = comb(le,seg[l++]);
            if (r&1) ri = comb(seg[--r],ri);
        }
        return comb(le,ri);
    }
};

Seg<1<<19> S[2];

void test(int ti) {
    T x = comb(S[0].query(0,lo-1),S[1].query(lo,hi));
    if (start+x.s < 0) return;
    cout << ti;
    exit(0);
}

void solve() {
    while (t[hi+1] < len) hi ++;
    test(0);
    
    while (lo < n) {
	    if (t[lo]+1 < t[hi+1]-len+1) {
	        lo ++;
	        if (lo == n) break;
	        test(t[lo-1]+1);
	    } else if (t[lo]+1 > t[hi+1]-len+1) {
	        hi ++;
	        test(t[hi]-len+1);
	    } else {
	        lo++, hi++;
	        if (lo == n) break;
	        test(t[lo-1]+1);
	    }
	}
	test(t[n-1]+1);
}

void init() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> a >> b >> c >> d >> start >> len;
	
	F0R(i,n) {
	    cin >> t[i] >> q[i];
	    if (q[i] == 0) {
	        S[0].upd(i,{-b,-b});
	        S[1].upd(i,{-d,-d});
	    } else {
	        S[0].upd(i,{a,0});
	        S[1].upd(i,{c,0});
	    }
	}
	t[n] = 2*MOD;
}

int main() {
    init();
	solve();
	cout << -1;
}

// read!
// ll vs. int!