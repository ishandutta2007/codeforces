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

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= (a); i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(a, x) for (auto& a : x)

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

#define sz(x) (int)x.size()
#define beg(x) x.begin()
#define en(x) x.end()
#define all(x) beg(x), en(x)
#define resz resize

const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 100001;
const ld PI = 4*atan((ld)1);

template<class T> void ckmin(T &a, T b) { a = min(a, b); }
template<class T> void ckmax(T &a, T b) { a = max(a, b); }

namespace io {
    // TYPE ID (StackOverflow)
    
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
    
    template<class T> void re(T& x) { cin >> x; }
    template<class Arg, class... Args> void re(Arg& first, Args&... rest);
    void re(double& x) { string t; re(t); x = stod(t); }
    void re(ld& x) { string t; re(t); x = stold(t); }
    
    template<class T> void re(complex<T>& x);
    template<class T1, class T2> void re(pair<T1,T2>& p);
    template<class T> void re(vector<T>& a);
    template<class T, size_t SZ> void re(array<T,SZ>& a);
    
    template<class Arg, class... Args> void re(Arg& first, Args&... rest) { re(first); re(rest...); }
    template<class T> void re(complex<T>& x) { T a,b; re(a,b); x = cd(a,b); }
    template<class T1, class T2> void re(pair<T1,T2>& p) { re(p.f,p.s); }
    template<class T> void re(vector<T>& a) { F0R(i,sz(a)) re(a[i]); }
    template<class T, size_t SZ> void re(array<T,SZ>& a) { F0R(i,SZ) re(a[i]); }
    
    // OUTPUT 
    
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
    template<class T> ostream& operator<<(ostream& os, const vector<T>& a) {
        return printArray(os,a,sz(a));
    }
    template<class T, size_t SZ> ostream& operator<<(ostream& os, const array<T,SZ>& a) {
        return printArray(os,a,SZ);
    }
    
    template<class T> void pr(const T& x) { cout << x << '\n'; }
    template<class Arg, class... Args> void pr(const Arg& first, const Args&... rest) { 
        cout << first << ' '; pr(rest...); 
    }
}

using namespace io;

int n,t,cur; // ori[301]; tmp[301];
int ans[301];

void finish() {
    cout << "! ";
    FOR(i,1,n+1) cout << ans[i];
    cout << endl;
    exit(0);
}

int query(int l, int r) {
    cout << "? " << l << " " << r << endl;
    /*if (rand()&1) {
        FOR(i,1,r+1) tmp[i] ^= 1;
    } else {
        FOR(i,l,n+1) tmp[i] ^= 1;
    }
    int ret = 0;
    FOR(i,1,n+1) ret += tmp[i];
    return ret;*/
    int z; cin >> z; return z;
}

bool allEqual(vi v) {
    FOR(i,1,sz(v)) if (v[i] != v[0]) return 0; 
    return 1;
}

int numVals(vi v) {
    set<int> s;
    F0R(i,sz(v)) s.insert(v[i]);
    return sz(s);
}

int numEq(vi v) {
    int z = 0;
    FOR(i,1,sz(v)) if (v[i] == v[i-1]) z ++;
    return z;
}

void gen(int ind) { // n-1-ind 
    if (n-t == ind+t-2*cur || n-t == ind+t-2*cur-2) {
        // cout << "A\n";
        vi v;
        F0R(i,30) v.pb(query(ind+1,n));
        bool eq = 0;
        if (t == n-t) {
            if (allEqual(v)) eq = 1;
        } else {
            if (numVals(v) == 2 && numEq(v) > 0) eq = 1;
        }
        // cout << "AH " << v << " " << eq; exit(0);
        if (eq) {
            if (n-t == ind+t-2*cur) {
                ans[ind] = 0;
                cur = v.back()-(n-ind)/2;
            } else {
                ans[ind] = 1; 
                cur = v.back()-(n-ind)/2;
                // cout << "ZZ " << ind << " " << cur << " " << v.back(); exit(0);
            }
        } else {
            if (n-t == ind+t-2*cur) {
                ans[ind] = 1;
                cur = v.back()-((n-ind)/2-1);
            } else {
                ans[ind] = 0;
                cur = v.back()-((n-ind)/2+1);
                //cout << "OOPS " << ind << " " << v.back() << " " << cur << "\n";
                //FOR(i,1,n+1) cout << tmp[i] << " "; exit(0);
            }
        }
        t = v.back();
    } else {
        //cout << "B " << cur << " " << t << "\n";
        /*int sum = 0;
        FOR(i,1,n+1) sum += tmp[i];
        cout << sum << "\n";
        FOR(i,1,n+1) cout << tmp[i];
        cout << "\n";*/
        int z = query(1,ind);
        while (z == n-t) {
            query(1,n);
            z = query(1,ind);
        }
        if (z == ind+t-2*cur) {
            ans[ind] = 0;
            cur = ind-cur; 
        } else {
            assert(z == ind+t-2*cur-2);
            ans[ind] = 1;
            cur = ind-cur-1;
        }
        //cout << "AH " << z << "\n";
        /*FOR(i,1,n+1) cout << tmp[i];
        cout << "\n";*/
        t = z;
    }
    /*if (ans[ind] != ori[ind]) {
        cout << "OOPS " << ind << " " << ans[ind] << " " << ori[ind];
        exit(0);
    }*/
}

int main() {
    // you should actually read the stuff at the bottom
    re(n,t); 
    /*FOR(i,1,n+1) {
        tmp[i] = ori[i] = rand()%2;
        t += tmp[i];
    }
    FOR(i,1,n+1) cout << tmp[i];
    cout << "\n";*/
    ans[n] = t;
    FOR(i,1,n) {
        gen(i);
        ans[n] -= ans[i];
    }
    finish();
    // you should actually read the stuff at the bottom
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/