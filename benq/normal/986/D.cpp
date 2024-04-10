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
typedef complex<double> cd;

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


const int MOD = (119 << 23) + 1, root = 3; // = 998244353
// For p < 2^30 there is also e.g. (5 << 25, 3), (7 << 26, 3),
// (479 << 21, 3) and (483 << 21, 5). The last two are > 10^9.

const ll INF = 1e18;
const ld PI = 4*atan((ld)1);

template<class T> void ckmin(T &a, T b) { a = min(a, b); }
template<class T> void ckmax(T &a, T b) { a = max(a, b); }

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

template<class T> void normalize(vector<T>& a) {
    //cout << "AH " << a << "\n";
    F0R(i,sz(a)) if (a[i] >= 1000) {
        if (i == sz(a)-1) a.pb(0);
        a[i+1] += a[i]/1000;
        a[i] %= 1000;
    }
    //cout << "AH " << a << "\n";
}

typedef complex<double> cd;

namespace FFT {
    int get(int s) { return s > 1 ? 32 - __builtin_clz(s - 1) : 0; }

    void fft(vcd& a) { 
        int N = sz(a), j = 0;
        
        FOR(i,1,N) {
            int k;
            for (k = N >> 1; j >= k; k >>= 1) j -= k;
            j += k; if (i < j) swap(a[i],a[j]);
        }
        
        vcd roots(N);
        F0R(i,N) roots[i] = cd(cos(2*PI*i/N),sin(2*PI*i/N));
        
        for (int i = 2; i <= N; i *= 2) {
            int i2 = i/2;
            for (j = 0; j < N; j += i) F0R(k,i2) {
                auto z = a[i2+j+k]*roots[N/i*k]; 
                a[i2+j+k] = a[j+k]-z; a[j+k] += z; 
            }
        }
    } 
    
    void fft_rev(vcd& a) {
        fft(a); trav(x,a) x /= sz(a);
        reverse(beg(a)+1, en(a));
    }
    
    template<class T> T brute(const T& a, const T& b) {
        T c(sz(a)+sz(b)-1);
        F0R(i,sz(a)) F0R(j,sz(b)) c[i+j] += a[i]*b[j];
        return c;
    }
    
    vcd conv(vcd a, vcd b) {
        int s = sz(a)+sz(b)-1, L = get(s), n = 1<<L;
        if (s <= 0) return {};
        if (s <= 200) return brute(a,b);
        a.resz(n), fft(a); b.resz(n), fft(b);
        F0R(i,n) a[i] *= b[i];
        fft_rev(a); a.resz(s); return a;
    }
    
    vcd sq(vcd a) {
        int s = sz(a)+sz(a)-1, L = get(s), n = 1<<L;
        if (s <= 0) return {};
        if (s <= 200) return brute(a,a);
        a.resz(n), fft(a); 
        F0R(i,n) a[i] *= a[i];
        fft_rev(a); a.resz(s); return a;
    }
    
    vl tovl(const vcd& X) {
        vl x(sz(X)); F0R(i,sz(X)) x[i] = round(X[i].real());
        return x;
    }
    
    vl conv(const vl& a, const vl& b) { 
        return tovl(conv(vcd(all(a)),vcd(all(b))));
    } // 0.85s when sz(a)=sz(b)=1<<19
    
    vl sq(const vl& a) {
        return tovl(sq(vcd(all(a))));
    }
}

using namespace FFT;

const int MX = 22;
vl po3[MX], S;

vl tri(int a, vl b) {
    for (auto& i: b) i *= a;
    normalize(b);
    return b;
}

bool les(const vl& a, const vl& b) {
    if (sz(a) != sz(b)) return sz(a) < sz(b);
    F0Rd(i,sz(a)) if (a[i] != b[i]) return a[i] < b[i];
    return 0;
}

string s; 

void init() {
    setIO(); 
    re(s);
    if (s == "1") {
        cout << 1;
        exit(0);
    }
    for (int i = sz(s)-3; i+3 > 0; i -= 3) {
    	int st = max(i,0);
    	S.pb(stoi(s.substr(st,i+3-st)));
    }
    po3[0] = {3};
    FOR(i,1,MX) {
        po3[i] = sq(po3[i-1]);
        normalize(po3[i]);
        // if (i < 5) cout << i << " " << po3[i] << "\n";
    }
}

int main() {
    init();
    // F0R(i,MX) pr(i,sz(po3[i]));
    int cur = floor(((sz(s)-1)*log(10)-log(4))/log(3))-1;
    cur = max(cur,0);
    
    vl res = {1};
    F0R(i,MX) if (cur&(1<<i)) {
    	res = conv(res,po3[i]);
    	normalize(res);
    }
    int ans;
    while (les(tri(4,res),S)) res = tri(3,res), cur ++;
    ans = 4+3*cur;
    while (les(tri(2,res),S)) res = tri(3,res), cur ++;
    ans = min(ans,2+3*cur);
    while (les(res,S)) res = tri(3,res), cur ++;
    ans = min(ans,3*cur);
    cout << ans;
    // you should actually read the stuff at the bottom
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/