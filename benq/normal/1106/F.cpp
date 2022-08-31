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

const int MOD = 998244353;
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
    template<class T, size_t SZ> ostream& operator<<(ostream& os, const array<T,SZ>& a) {
        return printArray(os,a,SZ);
    }
    template<class T> ostream& operator<<(ostream& os, const vector<T>& a) {
        return printArray(os,a,sz(a));
    }
    template<class T> ostream& operator<<(ostream& os, const set<T>& a) {
        os << vector<T>(all(a)); return os;
    }
    template<class T1, class T2> ostream& operator<<(ostream& os, const map<T1,T2>& a) {
        os << vector<pair<T1,T2>>(all(a)); return os;
    }
    
    template<class T> void pr(const T& x) { cout << x << '\n'; }
    template<class Arg, class... Args> void pr(const Arg& first, const Args&... rest) { 
        cout << first << ' '; pr(rest...); 
    }
}

using namespace io;

namespace modOp {
    int ad(int a, int b, int mod = MOD) { return (a+b)%mod; }
    int sub(int a, int b, int mod = MOD) { return (a-b+mod)%mod; }
    int mul(int a, int b, int mod = MOD) { return (ll)a*b%mod; }
    
    int AD(int& a, int b, int mod = MOD) { return a = ad(a,b,mod); }
    int SUB(int& a, int b, int mod = MOD) { return a = sub(a,b,mod); }
    int MUL(int& a, int b, int mod = MOD) { return a = mul(a,b,mod); }
    
    int po (int b, int p, int mod = MOD) { return !p?1:mul(po(mul(b,b,mod),p/2,mod),p&1?b:1,mod); }
    int inv (int b, int mod = MOD) { return po(b,mod-2,mod); }
    
    int invGeneral(int a, int b) { // 0 < a < b, gcd(a,b) = 1
        if (a == 0) return b == 1 ? 0 : -1;
        int x = invGeneral(b%a,a); 
        return x == -1 ? -1 : ((1-(ll)b*x)/a+b)%b;
    }
}

using namespace modOp;

template<class T> struct Mat {
    T** d;
    int a, b;
    
    Mat() { a = b = 0; }

    Mat(int _a, int _b) {
        a = _a, b = _b;
        d = new T*[a];
        F0R(i,a) {
            d[i] = new T[b];
            F0R(j,b) d[i][j] = 0;
        }
    }
    
    Mat (const vector<vector<T>>& v) : Mat(sz(v),sz(v[0])) {
        F0R(i,a) F0R(j,b) d[i][j] = v[i][j];
    }

    vector<vector<T>> toVec() {
        auto ret = vector<vector<T>>(a,vector<T>(b));
        F0R(i,a) F0R(j,b) ret[i][j] = d[i][j];
        return ret;
    }
    
    Mat operator+(const Mat& m) {
        Mat r(a,b);
        F0R(i,a) F0R(j,b) r.d[i][j] = ad(d[i][j],m.d[i][j],MOD-1);
        return r;
    }
    
    Mat operator*(const Mat& m) {
        Mat r(a,m.b);
        F0R(i,a) F0R(j,b) F0R(k,m.b) 
            AD(r.d[i][k],mul(d[i][j],m.d[j][k],MOD-1),MOD-1);
        return r;
    }

    Mat operator^(ll p) {
        Mat r(a,a), base(*this); 
        F0R(i,a) r.d[i][i] = 1;
        
        for (; p; p /= 2) {
            if (p&1) r = r*base;
            base = base*base;
        }
        
        return r;
    }
};

struct DiscreteLog {
    int mod, root, block;
    vi invy;
	unordered_map<int,int> u;

	int query(int x) {
		F0R(i,block) {
			int X = mul(x,invy[i],mod);
			if (u.count(X)) return i*block+u[X];
		}
		return -1;
	}

	void gen(int _mod, int _root) {
	    mod = _mod, root = _root, u.clear();
		
		block = sqrt(mod)+1;
	    int cur = 1;
		F0R(i,block) u[cur] = i, MUL(cur,root,mod);
		cur = inv(cur,mod);

        invy.resize(block);
        invy[0] = 1; FOR(i,1,block) invy[i] = mul(cur,invy[i-1],mod);
	} 
};

DiscreteLog D;
Mat<int> M;
int k,n,m;
vi b;

int main() {
    // you should actually read the stuff at the bottom
    setIO(); re(k); b.resz(k); re(b,n,m);
    M = Mat<int>(k,k);
    F0R(i,k-1) M.d[i][i+1] = 1;
    F0R(i,k) M.d[i][0] = b[i];
    M = M^(n-k); int t = M.d[0][0];
    // x^{MOD-1} = 1
    // x^t % MOD = m
    D.gen(MOD,3);
    m = D.query(m);
    // x*t % (MOD-1) = m 
    int g = __gcd(t,MOD-1);
    if (m % g != 0) { pr(-1); exit(0); }
    // x*(t/g)%((MOD-1)/g) = m/g 
    int x = mul(m/g,invGeneral(t/g,(MOD-1)/g),(MOD-1)/g);
    pr(po(3,x));
    // if (__gcd(MOD-1,m) )
    //
    
    // you should actually read the stuff at the bottom
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/