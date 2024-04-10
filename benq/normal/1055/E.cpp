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
const int MX = 100001;

namespace io {
    // Source: StackOverflow
    
    template<class T> struct like_array : is_array<T>{};
    template<class T, size_t N> struct like_array<array<T,N>> : true_type{};
    template<class T> struct like_array<vector<T>> : true_type{};
    template<class T> bool is_like_array(const T& a) { return like_array<T>::value; }

    // I/O 
    
    void setIn(string s) { freopen(s.c_str(),"r",stdin); }
    void setOut(string s) { freopen(s.c_str(),"w",stdout); }
    void setIO(string s = "") {
        ios_base::sync_with_stdio(0); cin.tie(0);
        if (sz(s)) { setIn(s+".in"), setOut(s+".out"); }
    }
    
    // INPUT 
    
    // double input seems slow on CF
    void re(double& x) { string t; cin >> t; x = stod(t); } 
    void re(ld& x) { string t; cin >> t; x = stold(t); }
    template<class T> void re(T& x) { cin >> x; }
    template<class Arg, class... Args> void re(Arg& first, Args&... rest) { 
        re(first); re(rest...); 
    }
    template<class T1, class T2> istream& operator>>(istream& is, pair<T1,T2>& p) {
        is >> p.f >> p.s; return is;
    }
    template<class T> istream& operator>>(istream& is, vector<T>& a) {
        F0R(i,sz(a)) is >> a[i];
        return is;
    }
    
    // OUTPUT 
    
    template<class T> void pr(const T& x) { cout << x << '\n'; }
    template<class Arg, class... Args> void pr(const Arg& first, const Args&... rest) { 
        cout << first << ' '; pr(rest...); 
    }
    template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) {
        os << '{' << a.f << ", " << a.s << '}'; return os;
    }
    
    template<class T> ostream& printArray(ostream& os, const T& a, int SZ) {
        os << '{';
        F0R(i,SZ) {
            if (i) {
                os << ", ";
                if (is_like_array(a[i])) cout << "\n";
            }
            os << a[i];
        }
        os << '}';
        return os;
    }
    
    template<class T, size_t SZ> ostream& operator<<(ostream& os, const array<T,SZ>& a) {
        return printArray(os,a,SZ);
    }
    template<class T> ostream& operator<<(ostream& os, const vector<T>& a) {
        return printArray(os,a,sz(a));
    }
}

using namespace io;

int n,s,m,k, dp[1501], tmp[1501];
vi a,A;
vi lef[1501];

int getMax(vpi& q, int mn) {
    return lb(all(q),mp(mn,-2*MOD))->s;
}

void ad() {
    F0R(i,n+1) {
        tmp[i] = dp[i];
        if (i) tmp[i] = max(tmp[i],tmp[i-1]);
    }
    vpi q;
    F0R(i,n+1) {
        while (sz(q) && q.back().s <= dp[i]-i) q.pop_back();
        q.pb({i,dp[i]-i});
        for (int j: lef[i]) {
            dp[i] = max(dp[i],tmp[j-1]+i-j+1);
            dp[i] = max(dp[i],getMax(q,j)+i);
        }
    }
}

int maxInter() {
    dp[0] = 0;
    FOR(i,1,n+1) dp[i] = -MOD;
    F0R(i,m) ad();
    int ans = 0;
    F0R(i,n+1) ans = max(ans,dp[i]);
    return ans;
}

vpi v;

bool ok(int mid) {
    int co = 1;
    F0R(i,sz(a)) {
        if (a[i] <= mid) A[i] = co++;
        else A[i] = -1;
    }
    // cout << A << "\n";
    vpi V;
    F0R(i,n+1) lef[i].clear();
    for (auto x: v) {
        auto X = x;
        while (X.f <= X.s && A[X.f] == -1) X.f ++;
        while (X.f <= X.s && A[X.s] == -1) X.s --;
        if (X.f <= X.s) {
            lef[A[X.s]].pb(A[X.f]);
            // cout << "AH " << X.f << " " << X.s << "\n";
        }
    }
    // cout << "OOPS " << maxInter() << "\n";
    return maxInter() >= k;
}

int main() {
    setIO(); re(n,s,m,k); a.resize(n); re(a); A.resize(n);
    F0R(i,s) {
        int l,r; re(l,r);
        v.pb({l-1,r-1});
    }
    
    int lo = 1, hi = MOD;
    while (lo < hi) {
        int mid = (lo+hi)/2;
        if (ok(mid)) hi = mid;
        else lo = mid+1;
    }
    if (hi == MOD) cout << -1;
    else cout << hi;
}

/* 
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/