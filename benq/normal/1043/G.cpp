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
const int MX = 200005;

namespace io {
    template<typename Test, template<typename...> class Ref>
    struct is_specialization : std::false_type {};

    template<template<typename...> class Ref, typename... Args>
    struct is_specialization<Ref<Args...>, Ref>: std::true_type {};
    // https://stackoverflow.com/questions/16337610/how-to-know-if-a-type-is-a-specialization-of-stdvector

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
    template<class T> ostream& operator<<(ostream& os, const vector<T>& a) {
        os << '{';
        F0R(i,sz(a)) {
            if (i) {
                os << ", ";
                if (is_specialization<T, vector>::value) os << '\n';
            }
            os << a[i];
        }
        os << '}';
        return os;
    }
}

using namespace io;

template<class T, int SZ> struct RMQ {
    T stor[SZ][32-__builtin_clz(SZ)];
    
    T comb(T a, T b) {
        return min(a,b);
    }
    
    void build(vector<T>& x) {
        F0R(i,sz(x)) stor[i][0] = x[i];
        FOR(j,1,32-__builtin_clz(SZ)) F0R(i,SZ-(1<<(j-1))) 
            stor[i][j] = comb(stor[i][j-1],
                        stor[i+(1<<(j-1))][j-1]);
    }
    
    T query(int l, int r) {
        int x = 31-__builtin_clz(r-l+1);
        return comb(stor[l][x],stor[r-(1<<x)+1][x]);
    }
};

struct SuffixArray {
    int N;
    vi idx;
    string str;
    RMQ<int,MX> R; 
    
    void compress(vi& v) {
        vi V = v; sort(all(V)); V.erase(unique(all(V)),V.end());
        for (int& i: v) i = lb(all(V),i)-V.begin()+1;
    }
    
    vi A, L; // A stores lexicographic value, L stores suffixes in order
    
    int get(int x) { return x >= N ? 0 : A[x]; }
    
    void sort_by(int x) { // stable sort elements in a by b
        vi cum(N+1); F0R(i,N) cum[get(i+x)] ++;
        int sum = 0; F0R(i,N+1) cum[i] = (sum += cum[i], sum-cum[i]);
        
        vi L2(N);
        for (int i: L) L2[cum[get(i+x)]++] = i;
        swap(L,L2);
    }
    
    void init(string _str) {
        str = _str; N = sz(str);
        A.resize(N); F0R(i,N) A[i] = str[i]; compress(A); 
        L.resize(N); F0R(i,N) L[i] = i;
        
        for (int cnt = 1; cnt < N; cnt <<= 1) { 
            sort_by(cnt), sort_by(0);
        
            vi A2(N);
            F0R(i,N) {
                if (i == 0) A2[L[i]] = 1;
                else A2[L[i]] = A2[L[i-1]]+
                    (mp(get(L[i]),get(L[i]+cnt)) != mp(get(L[i-1]),get(L[i-1]+cnt)));
            }
            
            swap(A,A2);
        }
        
        vi v = lcpArray(); R.build(v);
    }
    
    vi lcpArray() { // KACTL
        int h = 0;
        vi inv(N), res(N);
        F0R(i,N) inv[L[i]] = i;
        F0R(i,N) if (inv[i]) {
            int p0 = L[inv[i] - 1];
            while (max(i,p0)+h < N && str[i+h] == str[p0+h]) h++;
            res[inv[i]] = h;
            if (h) h--;
        }
        return res;
    }
    
    int lcp(int a, int b) {
        if (a == b) return N-a;
        int t0 = A[a], t1 = A[b];
        if (t0 > t1) swap(t0,t1);
        return R.query(t0,t1-1);
    }
};

RMQ<int,MX> tmp;
SuffixArray S; 

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

template<int SZ> struct stringRepeat {
    int len[SZ];
    string S;
    vpi ins[SZ];
    
    vector<array<int,3>> solveLeft(string s, int m) {
        if (m < 0) exit(5);
        vector<array<int,3>> v;
        
        vi v2 = get(string(s.begin()+m+1,s.end()),string(s.begin(),s.begin()+m+1));
        string V = string(s.begin(),s.begin()+m+2); reverse(all(V)); vi v1 = z(V); reverse(all(v1));
        
        F0R(i,m+1) if (v1[i]+v2[i] >= m+2-i) {
            int lo = max(1,m+2-i-v2[i]), hi = min(v1[i],m+1-i); // hi is wrong?
            lo = i-lo+1, hi = i-hi+1; swap(lo,hi); assert(lo <= hi);
            v.pb({2*(m+1-i),lo,hi});
        }
        return v;
    }
    
    void divi(int l, int r) {
        if (l == r) return;
        //cout << l << " " << r << "\n";
        int m = (l+r)/2; divi(l,m); divi(m+1,r);
        
        string t = string(S.begin()+l,S.begin()+r+1);
        m = (sz(t)-1)/2;
        auto a = solveLeft(t,m);
        reverse(all(t));
        auto b = solveLeft(t,sz(t)-2-m);
       /* if (l == 0 && r == 24) {
            cout << "START " << l << " " << r << " " << t << "\n";
            cout << (sz(t)-1)/2 << " " << t[(sz(t)-1)/2] << "\n";
            for (auto z: b) cout << z[0] << " " << z[1] << " " << z[2] << "\n";
            cout << string(S.begin()+l,S.begin()+r+1) << " " << string(S.begin()+12,S.begin()+16) << "\n";
        }*/
        
        for (auto x: a) ins[x[1]+l].pb({x[0],x[2]+l});
        for (auto x: b) {
            ins[r-x[2]-x[0]+1].pb({x[0],r-x[1]-x[0]+1});
            // if (l == 0 && r == 24) cout << "OOPS " << r-x[2]-x[0]+1 << " " << r-x[1]-x[0]+1 << "\n";
        }
        /*if (sz(b)) {
            auto x = b[0];
            cout << "HI " << l << " " << r << " " << r-1-x[0]-x[2]+1 << " " << t << " " << b[0][0] << " " << b[0][1] << " " << b[0][2] << "\n";
        }*/
    }
    
    priority_queue<pi,vpi,greater<pi>> m;
    
    void init(string _S) {
        S = _S;
        divi(0,sz(S)-1);
        m.push({MOD,MOD});
        F0R(i,sz(S)) {
            for (auto j: ins[i]) m.push(j);
            while (m.top().s < i) m.pop();
            len[i] = m.top().f;
            // cout << S << " " << i << " " << len[i] << "\n";
            // for (auto j: ins[i]) cout << "TT " << i << " " << j.f << " " << j.s << "\n";
        }
    }
};

stringRepeat<MX> ML[2];

// main-lorentz algo 

int n,q,ans[MX],cum[26][MX];
string s;

int len;
vi v(26); 

bool checkBorder(int l, int r) {
    int sq = sqrt(n);
    FOR(i,1,min(sq+1,len)) if (S.lcp(l,r-i+1) >= i) return 1;
    int pos = S.A[l]-1;
    assert(S.L[pos] == l);
    //cout << "A\n";
    FOR(i,max(pos-sq,0),min(pos+sq+1,n)) {
        int t = S.L[i];
        if (l < t && t < r && S.lcp(l,t) >= r-t+1) return 1;
    }
    //cout << "B\n";
    return 0;
}

bool test2(int l, int r) {
    // cout << "AH " << ML[0].len[l] << " " << ML[1].len[n-1-r] << " " << len << "\n";
    if (ML[0].len[l] <= len || ML[1].len[n-1-r] <= len) return 1;
    if (checkBorder(l,r)) return 1;
    return 0;
}

bool test3(int l, int r) {
    if (v[s[l]-'a'] > 1 || v[s[r]-'a'] > 1) return 1;
    return tmp.query(l,r) <= r;
}

bool testBad(int l, int r) {
    F0R(i,26) if (v[i] > 1) return 0;
    return 1;
}

bool test1(int l, int r) {
    for (int i = 1; i*i <= len; ++i) if (len % i == 0) {
        // cout << "AH " << i << " " << len << " " << S.lcp(l,l+i) << "\n";
        if (S.lcp(l,l+i) >= len-i) return 1;
        if (i != 1 && S.lcp(l,l+len/i) >= len-len/i) return 1;
    }
    return 0;
}

int answer(int l, int r) {
    len = r-l+1; 
    //cout << string(s.begin()+l,s.begin()+r+1) << "\n";
    //cout << l << " " << r << " " << s.substr(l,4) << " " << ML[0].len[l] << "\n";
    F0R(i,26) v[i] = cum[i][r+1]-cum[i][l];
    if (testBad(l,r)) return -1;
    if (test1(l,r)) return 1;
    if (test2(l,r)) return 2;
    if (test3(l,r)) return 3;
    return 4;
}

int main() {
    setIO(); re(n,s,q); S.init(s); 
    ML[0].init(s);
    string s2 = s; reverse(all(s2));
    ML[1].init(s2);
    vi v; 
    F0R(i,n) v.pb(i+ML[0].len[i]-1);
    tmp.build(v);
    F0R(i,sz(s)) {
        F0R(j,26) cum[j][i+1] = cum[j][i];
        cum[s[i]-'a'][i+1] ++;
    }
    F0R(i,q) {
        int l,r; re(l,r);
        /*if (i == 223) {
            string t = string(s.begin()+l-1,s.begin()+r);
            cout << l << " " << r << " " << t << "\n";
            for (int len = 1; len*2 <= sz(t); ++len) {
                if (t.substr(0,len) == t.substr(len,len)) cout << "A " << len << "\n";
                if (t.substr(sz(t)-2*len,len) == t.substr(sz(t)-len,len)) cout << "B " << len << "\n";
                if (t.substr(0,len) == t.substr(sz(t)-len,len)) cout << "C " << len << "\n";
            }
            cout << "TT " << ML[0].len[l-1] << " " << ML[1].len[n-r] << "\n";
        }*/
        cout << answer(l-1,r-1) << "\n";
    }
    
}

/* 
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/