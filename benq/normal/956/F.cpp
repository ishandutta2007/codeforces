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
const int MX = 200005;
const ld PI = 4*atan((ld)1);

template<class T> void ckmin(T &a, T b) { a = min(a, b); }
template<class T> void ckmax(T &a, T b) { a = max(a, b); }

namespace input {
    template<class T> void re(complex<T>& x);
    template<class T1, class T2> void re(pair<T1,T2>& p);
    template<class T> void re(vector<T>& a);
    template<class T, size_t SZ> void re(array<T,SZ>& a);

    template<class T> void re(T& x) { cin >> x; }
    void re(double& x) { string t; re(t); x = stod(t); }
    void re(ld& x) { string t; re(t); x = stold(t); }
    template<class Arg, class... Args> void re(Arg& first, Args&... rest) { 
        re(first); re(rest...); 
    }

    template<class T> void re(complex<T>& x) { T a,b; re(a,b); x = cd(a,b); }
    template<class T1, class T2> void re(pair<T1,T2>& p) { re(p.f,p.s); }
    template<class T> void re(vector<T>& a) { F0R(i,sz(a)) re(a[i]); }
    template<class T, size_t SZ> void re(array<T,SZ>& a) { F0R(i,SZ) re(a[i]); }
}

using namespace input;

namespace output {
    template<class T1, class T2> void pr(const pair<T1,T2>& x);
    template<class T, size_t SZ> void pr(const array<T,SZ>& x);
    template<class T> void pr(const vector<T>& x);
    template<class T> void pr(const set<T>& x);
    template<class T1, class T2> void pr(const map<T1,T2>& x);

    template<class T> void pr(const T& x) { cout << x; }
    template<class Arg, class... Args> void pr(const Arg& first, const Args&... rest) { 
        pr(first); pr(rest...); 
    }

    template<class T1, class T2> void pr(const pair<T1,T2>& x) { 
        pr("{",x.f,", ",x.s,"}"); 
    }
    template<class T> void prContain(const T& x) {
        pr("{");
        bool fst = 1; for (const auto& a: x) pr(!fst?", ":"",a), fst = 0; // const needed for vector<bool>
        pr("}");
    }
    template<class T, size_t SZ> void pr(const array<T,SZ>& x) { prContain(x); }
    template<class T> void pr(const vector<T>& x) { prContain(x); }
    template<class T> void pr(const set<T>& x) { prContain(x); }
    template<class T1, class T2> void pr(const map<T1,T2>& x) { prContain(x); }
    
    void ps() { pr("\n"); }
    template<class Arg> void ps(const Arg& first) { 
        pr(first); ps(); // no space at end of line
    }
    template<class Arg, class... Args> void ps(const Arg& first, const Args&... rest) { 
        pr(first," "); ps(rest...); // print w/ spaces
    }
}

using namespace output;

namespace io {
    void setIn(string s) { freopen(s.c_str(),"r",stdin); }
    void setOut(string s) { freopen(s.c_str(),"w",stdout); }
    void setIO(string s = "") {
        ios_base::sync_with_stdio(0); cin.tie(0); // fast I/O
        if (sz(s)) { setIn(s+".in"), setOut(s+".out"); } // for USACO
    }
}

using namespace io;

template<class T> T invGeneral(T a, T b) {
    a %= b; if (a == 0) return b == 1 ? 0 : -1;
    T x = invGeneral(b,a); 
    return x == -1 ? -1 : ((1-(ll)b*x)/a+b)%b;
}

template<class T> struct modular {
    T val; 
    explicit operator T() const { return val; }
    modular() { val = 0; }
    template<class U> modular(const U& v) {
        val = (-MOD <= v && v <= MOD) ? v : v % MOD;
        if (val < 0) val += MOD;
    }
    friend ostream& operator<<(ostream& os, const modular& a) { return os << a.val; }
    friend bool operator==(const modular& a, const modular& b) { return a.val == b.val; }
    friend bool operator!=(const modular& a, const modular& b) { return !(a == b); }

    modular operator-() const { return modular(-val); }
    modular& operator+=(const modular& m) { if ((val += m.val) >= MOD) val -= MOD; return *this; }
    modular& operator-=(const modular& m) { if ((val -= m.val) < 0) val += MOD; return *this; }
    modular& operator*=(const modular& m) { val = (ll)val*m.val%MOD; return *this; }
    friend modular exp(modular a, ll p) {
        modular ans = 1; for (; p; p /= 2, a *= a) if (p&1) ans *= a;
        return ans;
    }
    friend modular inv(const modular& a) { return invGeneral(a.val,MOD); } 
    // inv is equivalent to return exp(b,b.mod-2) if prime
    modular& operator/=(const modular& m) { return (*this) *= inv(m); }
    
    friend modular operator+(modular a, const modular& b) { return a += b; }
    friend modular operator-(modular a, const modular& b) { return a -= b; }
    friend modular operator*(modular a, const modular& b) { return a *= b; }
    
    friend modular operator/(modular a, const modular& b) { return a /= b; }
};

typedef modular<int> mi;
typedef pair<mi,mi> pmi;
typedef vector<mi> vmi;
typedef vector<pmi> vpmi;

ll bit[10];
ll odd[18][2], even[18][2];

struct rec {
    vl keys, vals[10];
    void ins(ll mask) { keys.pb(mask); }
    void init(int x) {
        sort(all(keys)); keys.erase(unique(all(keys)),keys.end());
        F0R(i,10) vals[i].assign(sz(keys),x);
    }
    void sum() {
        FOR(i,1,10) F0R(j,sz(vals[i])) vals[i][j] += vals[i-1][j];
    }
    int getIndex(ll mask) {
        auto it = lb(all(keys),mask); if (it == keys.end() || *it != mask) return -1;
        return it-keys.begin();
    }
    ll get(ll mask, int maxd) {
        if (maxd < 0) return 0;
        int ind = getIndex(mask); if (ind == -1) return 0;
        return vals[maxd][ind];
    }
    void upd(int d, ll mask, ll v) {
        vals[d][getIndex(mask)] += v;
    }
};

rec f[10][19];
 
void dfs(int depth, int cnt, int sum, ll mask, bitset<82> posi) {
    if (depth == 10) {
        for (int i = sum/2; i >= 0; --i) if (posi[i] == 1) {
            int dif = sum-2*i;
            if (dif > 1) f[dif][18].ins(mask);
            break;
        }
        return;
    }
    dfs(depth+1,cnt,sum,mask,posi);
    while (cnt < 18) {
        cnt ++; sum += depth; mask += bit[depth]; posi |= posi<<depth;
        dfs(depth+1,cnt,sum,mask,posi);
    }
}

void init() {
    bit[1] = 1; FOR(i,2,10) bit[i] = bit[i-1]<<5;
    bitset<82> posi = bitset<82>(); posi[0] = 1;
    dfs(1,0,0,0,posi);
    FOR(i,2,10) {
        f[i][18].init(1); // continue;
        for (int j = 18; j >= 1; --j) {
            F0R(a,sz(f[i][j].keys)) {
                auto mask = f[i][j].keys[a]; int cnt = 0;
                FOR(b,1,10) {
                    int numb = (mask>>(5*(b-1)))&((1<<5)-1); if (!numb) continue;
                    cnt += numb; f[i][j-1].ins(mask-bit[b]);
                }
                if (cnt < j) f[i][j-1].ins(mask);
            }
            f[i][j-1].init(0);
            F0R(a,sz(f[i][j].keys)) {
                auto mask = f[i][j].keys[a]; int cnt = 0;
                FOR(b,1,10) {
                    int numb = (mask>>(5*(b-1)))&((1<<5)-1); if (!numb) continue;
                    cnt += numb; f[i][j-1].upd(b,mask-bit[b],f[i][j].vals[9][a]);
                }
                if (cnt < j) f[i][j-1].upd(0,mask,f[i][j].vals[9][a]);
            }
            f[i][j-1].sum();
        }
    }
}

string getString(ll r) {
    string s = to_string(r);
    return string(18-sz(s),'0')+s;
}

int sumDig(ll r) {
    int res = 0;
    while (r) { res += r%10; r /= 10; }
    return res;
}

ll getOdd(ll r) {
    if (r%2 == 1) return (r+1)/2; // 11 -> 6 
    return r/2+(sumDig(r)&1); // 10 -> 5+
}

ll tri(int dif, ll r) {
    string s = getString(r);
    ll mask = 0, ans = 0;
    F0R(i,18) {
        int d = s[i]-'0';
        ans += f[dif][i].get(mask,d-1);
        mask += bit[d];
    }
    ans += f[dif][18].get(mask,9);
    return ans;
}

ll solve(ll r, int k) {
    ll res = r;
    if (k == 0) {
        res -= getOdd(r);
        /*cout << "?? " << r << " " << k << " " << res << "\n";
        cout << tri(2,100) << "\n";
        cout << tri(4,100) << "\n";
        cout << tri(6,100) << "\n";
        cout << tri(8,100) << "\n";*/
        for (int i = 2; i < 10; i += 2) {
            // cout << "ZZ " << res << " " << tri(i,r) << "\n";
            res -= tri(i,r);
            // cout << "WAT " << res << " " << i << " " << r << "\n";
        }
        // cout << "WAT " << r << " " << res << "\n";
    } else {
        for (int i = k+1; i < 10; ++i) res -= tri(i,r);
    }
    return res;
}

int main() {
    init();	// exit(0);
    int n; re(n);
    F0R(i,n) {
        ll l,r; int k; re(l,r,k); ll ret = 0;
        if (r == INF) {
            if (k >= 1) ret ++;
            r --;
        }
        ret += solve(r,k);  ret -= solve(l-1,k);
        ps(ret);
    }
    // you should actually read the stuff at the bottom
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/