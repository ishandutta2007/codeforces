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

const int MOD = 1000000007; // 998244353
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


typedef unsigned long long ul;

namespace rpm {
    const int bits = 14; // if all numbers are less than 2^k, set bits = 64-k
    const ul po = (ul)1<<bits;
    
    ul mod_mul(ul a, ul b, ul &c) {  // return (__int128(a)*b) % c;
    	ul x = 0;
    	for (; b; b >>= bits, a = (a << bits) % c) 
    		x = (x + (a * (b & (po - 1))) % c) % c;
    	return x;
    }
    
    ul mod_pow(ul a, ul b, ul mod) {
    	if (b == 0) return 1;
    	ul res = mod_pow(a, b / 2, mod);
    	res = mod_mul(res, res, mod);
    	if (b & 1) return mod_mul(res, a, mod);
    	return res;
    }
}

using namespace rpm;

template<int SZ> struct Sieve { 
	bitset<SZ> comp;
	vl pr;
	// int sp[SZ];

	Sieve() {
		for (int i = 2; i*i < SZ; ++i) if (!comp[i]) 
		    for (int j = i*i; j < SZ; j += i) comp[j] = 1;
		FOR(i,2,SZ) if (!comp[i]) pr.pb(i);
		
		/*FOR(i,2,SZ) { // O(N) sieve
			if (sp[i] == 0) { sp[i] = i; pr.pb(i); }
			for (int p : pr) {
				if (p > sp[i] || i*p >= SZ) break;
				sp[i*p] = p;
			}
		}*/
	}
};

Sieve<50000000> S;

vl factor(ll x) {
    vl v;
    trav (t,S.pr) {
        if (t*t > x) break;
        if (x % t == 0) {
            while (x % t == 0) x /= t;
            v.pb(t);
        }
    }
    if (x > 1) v.pb(x);
    return v;
}

/*namespace factor2 {
	Sieve<1<<20> S = Sieve<1<<20>(); // should take care of all primes up to n^(1/3)

	bool prime(ll p) { // miller-rabin
		if (p == 2) return true;
		if (p == 1 || p % 2 == 0) return false;
		ll s = p - 1;
		while (s % 2 == 0) s /= 2;
		F0R(i,15) {
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

	vpl factor2(ll d) {
		vpl res;

		vi& pr = S.pr;
		for (int i = 0; i < sz(pr) && pr[i]*pr[i] <= d; i++) if (d % pr[i] == 0) {
		    int co = 0;
			while (d % pr[i] == 0) d /= pr[i], co ++;
			res.pb({pr[i],co});
		}
			
		if (d > 1) { // d is now a product of at most 2 primes.
			if (prime(d)) res.pb({d,1});
			else while (1) {
				ll has = rand() % 2321 + 47;
				ll x = 2, y = 2, c = 1;
				for (; c == 1; c = __gcd((y > x ? y - x : x - y), d)) {
					x = f(x, d, has);
					y = f(f(y, d, has), d, has);
				}
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
}*/

int t;
map<ll,vpl> q;
bool ans[10000];

ll shortest[MX];

ll invGeneral(ll a, ll b) { // 0 < a < b, gcd(a,b) = 1
    if (a == 0) return b == 1 ? 0 : -1;
    auto x = invGeneral(b%a,a); 
    return x == -1 ? -1 : ((1-(ll)b*x)/a+b)%b;
}

int main() {
    // you should actually read the stuff at the bottom
    setIO(); re(t);
    F0R(i,t) {
        ll n,k; re(n,k);
        q[k].pb({n,i});
    }
    trav(x,q) {
        auto a = factor(x.f);
        // vl a; trav(t,A) a.pb(t.f);
        if (sz(a) == 0) {
            
        } else if (sz(a) == 1) {
            trav(t,x.s) ans[t.s] = ((t.f % a[0]) == 0);
        } else if (sz(a) == 2) {
            trav(t,x.s) {
                ll des = (t.f%a[0])*invGeneral(a[1]%a[0],a[0])%a[0];
                des *= a[1];
                ans[t.s] = (des <= t.f);
                // pr("AH",des);
                // a[0]*x+a[1]*y = t.f 
                // mod a[0]: a[1]*y equiv t.f 
                // (t.f*inv(a[1],a[0]) mod a[0])*a[1] <= t.f;
            }
        } else {
            FOR(i,1,a[0]) shortest[i] = INF;
            priority_queue<pl,vpl,greater<pl>> p; p.push({0,0});
            while (sz(p)) {
                auto z = p.top(); p.pop();
                if (z.f != shortest[z.s]) continue;
                FOR(i,1,sz(a)) {
                    int ind = (z.f+a[i])%a[0];
                    if (z.f+a[i] < shortest[ind]) {
                        p.push({shortest[ind] = z.f+a[i], ind});
                    }
                }
            }
            trav(t,x.s) ans[t.s] = (t.f >= shortest[t.f%a[0]]);
        }
    }
    F0R(i,t) if (ans[i]) pr("YES");
    else pr("NO");
    // you should actually read the stuff at the bottom
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/