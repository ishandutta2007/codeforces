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
#define all(x) begin(x), end(x)
#define rsz resize

const int MOD = 1000000007; // 998244353
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
    friend modular inv(const modular& a) { 
        auto i = invGeneral(a.val,MOD); assert(i != -1);
        return i;
    } // equivalent to return exp(b,MOD-2) if MOD is prime
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

typedef unsigned long long ul;

namespace rpm {
    const int bits = 4; // if all numbers are less than 2^k, set bits = 64-k
    const ul po = (ul)1<<bits;

    ul mod_mul(ul a, ul b, const ul& mod) {  // return (__int128(a)*b) % mod;
        ul x = 0;
        for (; b; b >>= bits, a = (a << bits) % mod)
            x = (x + (a * (b & (po - 1))) % mod) % mod;
        return x;
    }

    ul mod_pow(ul a, ul b, const ul& mod) {
        if (b == 0) return 1;
        ul res = mod_pow(a, b / 2, mod);
        res = mod_mul(res, res, mod);
        if (b & 1) return mod_mul(res, a, mod);
        return res;
    }
}

using namespace rpm;

namespace basicFactor {
    template<class T> vector<pair<T,int>> factor(T x) { // x <= 10^{14} is fine
        vector<pair<T,int>> pri;

        for (T i = 2; i*i <= x; ++i) if (x % i == 0) {
            int t = 0;
            while (x % i == 0) x /= i, t ++;
            pri.pb({i,t});
        }

        if (x > 1) pri.pb({x,1});
        return pri;
    }

    /* Note:
     * number of operations needed s.t.
     *                phi(phi(...phi(n)...))=1
     * is O(log n).
     * Euler's theorem: a^{\phi(p)}\equiv 1 (mod p), gcd(a,p)=1
     */

    ll phi(ll x) {
        trav(a,factor(x)) x /= a.f, x *= a.f-1;
        return x;
    }

    template<class T> void tour(vector<pair<T,int>>& v, vector<T>& V, int ind, T cur) {
        if (ind == sz(v)) V.pb(cur);
        else {
            T mul = 1;
            F0R(i,v[ind].s+1) {
                tour(v,V,ind+1,cur*mul);
                mul *= v[ind].f;
            }
        }
    }

    template<class T> vector<T> getDivi(T x) {
        auto v = factor(x);
        vector<T> V; tour(v,V,0,(T)1); sort(all(V));
        return V;
    }
}

using namespace basicFactor;

template<int SZ> struct Sieve { 
	bitset<SZ> comp;
	vi pr;
	// int sp[SZ];

	Sieve() {
		for (int i = 2; i*i < SZ; ++i) if (!comp[i]) 
			for (int j = i*i; j < SZ; j += i) comp[j] = 1;
		FOR(i,2,SZ) if (!comp[i]) pr.pb(i);
		
		/*FOR(i,2,SZ) { // O(N) sieve
			if (sp[i] == 0) { sp[i] = i; pr.pb(i); }
			trav(p,pr) {
				if (p > sp[i] || i*p >= SZ) break;
				sp[i*p] = p;
			}
		}*/
	}
};

namespace advFactor {
	Sieve<1<<20> S = Sieve<1<<20>(); // should take care of all primes up to n^(1/3)

	bool millerRabin(ll p) { // test primality
		if (p == 2) return true;
		if (p == 1 || p % 2 == 0) return false;
		ll s = p - 1; while (s % 2 == 0) s /= 2;
		F0R(i,30) { // strong liar with probability <= 1/4
			ll a = rand() % (p - 1) + 1, tmp = s;
			ll mod = mod_pow(a, tmp, p);
			while (tmp != p - 1 && mod != 1 && mod != p - 1) {
				mod = mod_mul(mod, mod, p);
				tmp *= 2;
			}
			if (mod != p - 1 && tmp % 2 == 0) return false;
		}
		return true;
	}

	ll f(ll a, ll n, ll &has) { return (mod_mul(a, a, n) + has) % n; }

	vpl pollardsRho(ll d) {
		vpl res;

		auto& pr = S.pr;
		for (int i = 0; i < sz(pr) && pr[i]*pr[i] <= d; i++) if (d % pr[i] == 0) {
		    int co = 0; while (d % pr[i] == 0) d /= pr[i], co ++;
			res.pb({pr[i],co});
		}
			
		if (d > 1) { // d is now a product of at most 2 primes.
			if (millerRabin(d)) res.pb({d,1});
			else while (1) {
				ll has = rand() % 2321 + 47;
				ll x = 2, y = 2, c = 1;
				for (; c == 1; c = __gcd(abs(x-y), d)) {
					x = f(x, d, has);
					y = f(f(y, d, has), d, has);
				} // should cycle in ~sqrt(smallest nontrivial divisor) turns 
				if (c != d) {
				    d /= c; if (d > c) swap(d,c);
				    if (c == d) res.pb({c,2});
				    else res.pb({c,1}), res.pb({d,1});
					break;
				}
			}
		}

		return res;
	}
}

using namespace advFactor;

ll P; 
vpl facP; 
ll n,m,p;
bool bad[2000000];

ll order(ll x) {
    if (__gcd(x,m) != 1) return 0;
    ll res = P;
    trav(t,facP) while (res % t.f == 0 && mod_pow(x,res/t.f,m) == 1) res /= t.f;
    return res;
}

int main() {
    setIO(); re(n,m,p);
    auto v = pollardsRho(m); // ps(v);
    P = m/v[0].f*(v[0].f-1);
    // ps("??",P);
    facP = pollardsRho(P);
	vl res;
    if (p % v[0].f == 0) {
    	set<ll> bad; 
    	ll cur = 1;
    	while (cur != 0) {
    		bad.insert(cur);
    		cur = mod_mul(cur,p,m);
    	}
    	FOR(i,1,m) if (__gcd((ll)i,m) == 1 && !bad.count(i)) {
    		res.pb(i);
    		if (sz(res) == n) break;
    	}
    } else if (v[0].f == 2) {
    	if (m >= 8 && 4*n <= m) {
    		vi v;
    		if (3 != p%8) v.pb(3);
    		if (5 != p%8) v.pb(5);
    		if (7 != p%8) v.pb(7);
    		trav(t,v) {
    			while (t < m && sz(res) < n) {
    				res.pb(t);
    				t += 8;
    			}
    			t %= 8;
    		}
    	} else {
			ll tmp = 1;
			while (!bad[tmp]) {
				bad[tmp] = 1;
				tmp = tmp*p%m;
				// ps("??",tmp);
			}
			F0R(j,m) if (j%2 == 1 && !bad[j]) {
				res.pb(j);
				if (sz(res) == n) break;
			}
			// ps("HA",res);
    	}
    } else {
    	ll t = P/order(p); 
    	if (t != 1) {
	    	// ps(p,v[0].f,p % v[0].f ); exit(0);
	    	ll g = 1; while (order(g) != P) g ++;
	    	ll cur = 1;
	    	// ps("HA",g,t); exit(0);
	    	// ps("HA",g,t);
	    	FOR(i,1,P) {
	    		cur = mod_mul(cur,g,m);
	    		if (i%t != 0) {
	    			res.pb(cur);
	    			if (sz(res) == n) break;
	    		}
	    	}
    	}
    }
	if (sz(res) < n) {
		ps(-1);
		exit(0);
	}
	trav(t,res) pr(t,' ');
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/