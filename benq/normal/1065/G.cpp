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
    void setIn(string s) { freopen(s.c_str(),"r",stdin); }
    void setOut(string s) { freopen(s.c_str(),"w",stdout); }
    void setIO(string s = "") {
        ios_base::sync_with_stdio(0); cin.tie(0);
        if (sz(s)) { setIn(s+".in"), setOut(s+".out"); }
    }
    
    // double input seems slow on CF
    void re(double& x) { string t; cin >> t; x = stod(t); } 
    void re(ld& x) { string t; cin >> t; x = stold(t); }
    template<class T> void re(T& x) { cin >> x; }
    template<class Arg, class... Args> void re(Arg& first, Args&... rest) { re(first); re(rest...); }
    
    // pair
    template<class T1, class T2> istream& operator>>(istream& is, pair<T1,T2>& p) {
        is >> p.f >> p.s;
        return is;
    }
    template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) {
        os << '{' << a.f << ", " << a.s << '}';
        return os;
    }
    
    // vector
    template<class T> istream& operator>>(istream& is, vector<T>& a) {
        int sz; is >> sz; a.resize(sz);
        F0R(i,sz) is >> a[i];
        return is;
    }
    template<class T> ostream& operator<<(ostream& os, const vector<T>& a) {
        os << "{";
        F0R(i,sz(a)) {
            if (i) os << ", ";
            os << a[i];
        }
        os << "}";
        return os;
    }
}

using namespace io;

ll k;
int n,m;
ld num[201];
pair<string,string> en[201];

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

int eq(string& s, string& t, vi& v, int j, int len) {
    int val = v[j];
    if (val >= len) return 1;
    if (val >= sz(s)) return 0;
    /*if (val >= sz(s) || val >= sz(t)) {
        cout << "AH " << val << " " << sz(s) << " " << sz(t);
        exit(0);
    }*/
    return s[val] > t[val+j];
}

ld get(string s) {
    num[0] = ("0" <= s); num[1] = ("1" <= s);
    FOR(i,2,n+1) {
        num[i] = num[i-2]+num[i-1];
        string t = en[i-2].s+en[i-1].f;
        vi v = get(s,t);
        
        F0Rd(j,sz(en[i-2].s)) {
            num[i] -= eq(s,t,v,j,min(m,sz(en[i-2].s)-j));
            num[i] += eq(s,t,v,j,min(m,sz(t)-j));
        }
        // F(i-2)+F(i-1)
    }
    return num[n];
}

void input() {
    setIO();
    cin >> n >> k >> m; 
    
    en[0] = {"0","0"}, en[1] = {"1","1"};
    FOR(i,2,201) {
        en[i].f = en[i-2].f+en[i-1].f;
        en[i].s = en[i-2].s+en[i-1].s;
        int t = min(m,sz(en[i].s));
        en[i].f = en[i].f.substr(0,t);
        en[i].s = en[i].s.substr(sz(en[i].s)-t,t);
    }
    // count how many with first m chars <= str 
    
}

int main() {
    input();
    string cur = ""; // last cur such that cnt(cur) < k
    while (sz(cur) < m) {
        if (get(cur+'1') < k) {
            cur += '1';
        } else if (get(cur+'0') < k) {
            cur += '0';
        } else break;
    }
    if (sz(cur) < m) {
        cur += '0';
    } else {
        while (cur.back() == '1') cur.pop_back();
        cur.pop_back(); cur += '1';
    }
    cout << cur;
}
/* 
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/