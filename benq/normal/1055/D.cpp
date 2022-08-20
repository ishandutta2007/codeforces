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

int n;
vector<string> a,b,bad;
string bef, aft, l, r;

string match2(string a, string b) {
    int ind = 0;
    while (ind < min(sz(a),sz(b)) && a[ind] == b[ind]) ind ++;
    return a.substr(0,ind);
}

string match1(string a, string b) {
    reverse(all(a)), reverse(all(b));
    string t = match2(a,b); reverse(all(t));
    return t;
}

namespace Z {
    vi z(string s) {
        int N = sz(s); s += '#';
        vi ans(N); ans[0] = N;
        while (s[1+ans[1]] == s[ans[1]]) ans[1] ++;
        
        int L = 1, R = ans[1];
        FOR(i,2,N) {
            if (i <= R) ans[i] = min(R-i+1,ans[i-L]);
            while (s[i+ans[i]] == s[ans[i]]) ans[i] ++;
            if (i+ans[i]-1 > R) L = i, R = i+ans[i]-1;
        }
        return ans;
    }
    
    vi get(string a, string b) { // find prefixes of a in b
        string s = a+"@"+b; 
        vi t = z(s);
        return vi(t.begin()+sz(a)+1,t.end());
    }
};

using namespace Z;

string transform(string a, string b, string c) {
    vi v = get(b,a);
    F0R(i,sz(a)) if (v[i] == sz(b)) {
        //cout << "AH " << a << " " << sz(b) << " " << b << "\n";
        F0R(j,sz(b)) a[i+j] = c[j];
        //cout << "AH " << a << "\n";
        return a;
    }
    return a;
}

int main() {
    setIO(); re(n);
    a.resize(n), b.resize(n); re(a,b);
    
    //cout << a << "\n" << b;
    //exit(0);
    F0R(i,n) {
        if (a[i] == b[i]) bad.pb(a[i]);
        else {
            if (sz(a[i]) != sz(b[i])) exit(5);
            int x = 0, y = 0;
            while (a[i][x] == b[i][x]) x ++;
            while (a[i][sz(b[i])-1-y] == b[i][sz(b[i])-1-y]) y ++;
            
            
            string BEF = string(a[i].begin()+x,a[i].end()-y);
            string AFT = string(b[i].begin()+x,b[i].end()-y);
            
            if (sz(bef)) {
                if (bef != BEF || aft != AFT) {
                    cout << "NO";
                    exit(0);
                }
                l = match1(l,string(a[i].begin(),a[i].begin()+x));
                r = match2(r,string(a[i].end()-y,a[i].end()));
            } else {
                bef = BEF, aft = AFT;
                l = string(a[i].begin(),a[i].begin()+x);
                r = string(a[i].end()-y,a[i].end());
            }
        }
    }
    string x = l+bef+r;
    string y = l+aft+r;
    F0R(i,sz(a)) if (transform(a[i],x,y) != b[i]) {
        cout << "NO";
        exit(0);
    }
    cout << "YES\n";
    cout << x << "\n" << y;
}

/* 
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/