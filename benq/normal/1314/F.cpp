#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef double db; 
typedef string str; 

typedef pair<int,int> pi;
typedef pair<ll,ll> pl; 
typedef pair<ld,ld> pd; 

typedef vector<int> vi; 
typedef vector<ll> vl; 
typedef vector<ld> vd; 
typedef vector<str> vs; 
typedef vector<pi> vpi;
typedef vector<pl> vpl; 
typedef vector<pd> vpd; 

#define mp make_pair 
#define f first
#define s second
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend() 
#define rsz resize
#define ins insert 
#define ft front() 
#define bk back()
#define pf push_front 
#define pb push_back
#define eb emplace_back 
#define lb lower_bound 
#define ub upper_bound 

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)

const int MOD = 1e9+7; // 998244353;
const int MX = 2e5+5; 
const ll INF = 1e18; 
const ld PI = acos((ld)-1);
const int xd[4] = {1,0,-1,0}, yd[4] = {0,1,0,-1}; 

template<class T> bool ckmin(T& a, const T& b) { 
	return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { 
	return a < b ? a = b, 1 : 0; }
int pct(int x) { return __builtin_popcount(x); } 

namespace input {
	template<class T> void re(complex<T>& x);
	template<class T1, class T2> void re(pair<T1,T2>& p);
	template<class T> void re(vector<T>& a);
	template<class T, size_t SZ> void re(array<T,SZ>& a);

	template<class T> void re(T& x) { cin >> x; }
	void re(double& x) { string t; re(t); x = stod(t); }
	void re(ld& x) { string t; re(t); x = stold(t); }
	template<class T, class... Ts> void re(T& t, Ts&... ts) { 
		re(t); re(ts...); 
	}

	template<class T> void re(complex<T>& x) { T a,b; re(a,b); x = {a,b}; }
	template<class T1, class T2> void re(pair<T1,T2>& p) { re(p.f,p.s); }
	template<class T> void re(vector<T>& a) { F0R(i,sz(a)) re(a[i]); }
	template<class T, size_t SZ> void re(array<T,SZ>& a) { F0R(i,SZ) re(a[i]); }
}

using namespace input;

namespace output {
	void pr(int x) { cout << x; }
	void pr(long x) { cout << x; }
	void pr(ll x) { cout << x; }
	void pr(unsigned x) { cout << x; }
	void pr(unsigned long x) { cout << x; }
	void pr(unsigned long long x) { cout << x; }
	void pr(float x) { cout << x; }
	void pr(double x) { cout << x; }
	void pr(ld x) { cout << x; }
	void pr(char x) { cout << x; }
	void pr(const char* x) { cout << x; }
	void pr(const string& x) { cout << x; }
	void pr(bool x) { pr(x ? "true" : "false"); }
	template<class T> void pr(const complex<T>& x) { cout << x; }
	
	template<class T1, class T2> void pr(const pair<T1,T2>& x);
	template<class T> void pr(const T& x);
	
	template<class T, class... Ts> void pr(const T& t, const Ts&... ts) { 
		pr(t); pr(ts...); 
	}
	template<class T1, class T2> void pr(const pair<T1,T2>& x) { 
		pr("{",x.f,", ",x.s,"}"); 
	}
	template<class T> void pr(const T& x) { 
		pr("{"); // const iterator needed for vector<bool>
		bool fst = 1; for (const auto& a: x) pr(!fst?", ":"",a), fst = 0; 
		pr("}");
	}
	
	void ps() { pr("\n"); } // print w/ spaces
	template<class T, class... Ts> void ps(const T& t, const Ts&... ts) { 
		pr(t); if (sizeof...(ts)) pr(" "); ps(ts...); 
	}
	
	void pc() { pr("]\n"); } // debug w/ commas
	template<class T, class... Ts> void pc(const T& t, const Ts&... ts) { 
		pr(t); if (sizeof...(ts)) pr(", "); pc(ts...); 
	}
	#define dbg(x...) pr("[",#x,"] = ["), pc(x);
}

using namespace output;

namespace io {
	void setIn(string s) { freopen(s.c_str(),"r",stdin); }
	void setOut(string s) { freopen(s.c_str(),"w",stdout); }
	void setIO(string s = "") {
		ios_base::sync_with_stdio(0); cin.tie(0); // fast I/O
		// cin.exceptions(cin.failbit); 
		// throws exception when do smth illegal
		// ex. try to read letter into int
		if (sz(s)) { setIn(s+".in"), setOut(s+".out"); } // for USACO
	}
}

using namespace io;

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 

/**
 * Description: Product of nimbers is associative, commutative, and distributive 
 	* over addition (xor). Forms finite field of size $2^{2^k}.$ Application: 
 	* Given 1D coin turning games $G_1,G_2$ $G_1\times G_2$ is the 2D coin turning 
 	* game defined as follows. If turning coins at $x_1,x_2,\ldots,x_m$ is legal 
 	* in $G_1$ and $y_1,y_2,\ldots,y_n$ is legal in $G_2$, then turning coins at 
 	* all positions $(x_i,y_j)$ is legal assuming that the coin at $(x_m,y_n)$ 
 	* goes from heads to tails. Then the grundy function $g(x,y)$ of $G_1\times G_2$ 
 	* is $g_1(x)\times g_2(y).$ 
 * Source: Andrew He
 	* also see pg 35 of https://www.fmf.uni-lj.si/~juvan/Seminar1/ferguson.pdf
 	* https://en.wikipedia.org/wiki/Nimber
 * Verification: https://codeforces.com/gym/102341/problem/L
 	* https://projecteuler.net/problem=459
 */

using ul = uint64_t;
ul _nimProd[64][64];
ul nimProd(int i, int j) { // nim prod of 2^i, 2^j
	ul& u =_nimProd[i][j]; if (u) return u;
	if (!(i&j)) return u = 1ULL<<(i|j);
	int a = (i&j)&-(i&j); // 2^{2^k}
	return u=nimProd(i^a,j)^nimProd((i^a)|(a-1),(j^a)|(i&(a-1)));
	// 2^{2^k}*2^{2^k} = 2^{2^k}+2^{2^k-1}
	// 2^{2^i}*2^{2^j} = 2^{2^i+2^j} if i<j
}
 
struct nb { // nimber
	ul x; nb() { x = 0; }
	nb(ul _x): x(_x) {}
	explicit operator ul() { return x; }
	nb operator+(nb y) { return nb(x^y.x); }
	nb operator*(nb y) {
		ul res = 0;
		F0R(i,64)if(x>>i&1)F0R(j,64)if(y.x>>j&1)res^=nimProd(i,j);
		return nb(res);
	}
	friend nb pow(nb b, ul p) {
		nb res = 1; for (;p;p/=2,b=b*b) if (p&1) res = res*b;
		return res;
	}
	friend nb inv(nb b) { return pow(b,-2); }
	// b^{2^{2^A}-1}=0 where 2^{2^A} > b
};

const ul M = -1;
const vi factors = {3, 5, 17,  257, 641, 65537, 6700417};
nb root(-1);

/**
 * Description: Hash map with the same API as unordered\_map, but \tilde 3x faster.
 	* Initial capacity must be a power of 2 if provided.
 * Source: KACTL
 * Usage: ht<int,int> h({},{},{},{},{1<<16});
 */

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
struct chash { /// use most bits rather than just the lowest ones
	const uint64_t C = ll(2e18*PI)+71; // large odd number
	const int RANDOM = rng();
	ll operator()(ll x) const {
		return __builtin_bswap64((x^RANDOM)*C); }
};
template<class K,class V> using ht = gp_hash_table<K,V,chash>;
template<class K,class V> V get(ht<K,V>& u, K x) {
	auto it = u.find(x); return it == end(u) ? 0 : it->s; }

gp_hash_table<ul,int> stor[7];
vector<nb> invs;

vi LOG(nb x) {
	vi res;
	F0R(i,sz(factors)) {
		auto t = factors[i];
		auto X = inv(pow(x,M/t));
		int num = 0;
		while (1) {
		    if (stor[i].find(X.x) != end(stor[i])) {
		        num += stor[i][X.x];
		        break;
		    }
		    X = X*invs[i]; num += 1<<20;
		}
		// assert(stor[i].count(X.x));
		res.pb((t-num)%t);
		/*auto R = pow(root,M/t);
		nb cur = 1;
		for (int i = 0;;++i) {
			if (cur.x == X.x) {
				int dumb = (t-i)%t;
				res.pb(dumb);
				ps("HA",t,dumb);
				break;
			}
			cur = cur*R;
		}*/
		// (x*root^a)^{M/t} == 1
		// (root^{M/t})^a= 1/x^{M/t}
	}
	// ps("WHOOPS",res); exit(0);
	return res;
}

/**
 * Description: euclid finds ${x,y}$ such that $ax+by=\gcd(a,b)$ 
 	* such that $|ax|,|by|\le \frac{ab}{\gcd(a,b)},$ 
 	* Should work for $a,b<2^{62}$
 * Source: KACTL
 * Time: O(\log ab)
 */

pl euclid(ll a, ll b) { 
	if (!b) return {1,0};
	pl p = euclid(b,a%b);
	return {p.s,p.f-a/b*p.s};
}
ll invGen(ll a, ll b) { 
	pl p = euclid(a,b); assert(p.f*a+p.s*b == 1); // gcd is 1
	return p.f+(p.f<0)*b; }

nb tmp[64];

int main() {
	clock_t beg = clock();
	stor[6] = gp_hash_table<ul,int>({},{},{},{},{1<<20});
	F0R(i,sz(factors)) {
		auto t = factors[i];
		//ps("DOING",t);
		// ps("WUT",t);
		nb cur(1);
		auto R = pow(root,M/t);
		F0R(j,64) tmp[j] = nb(1ULL<<j)*R;
		F0R(j,min(t,1<<20)) {
			stor[i][cur.x] = j;
			ul z = 0;
			F0R(j,64) if (cur.x&(1ULL<<j)) z ^= tmp[j].x;
			cur = z;
		}
		invs.pb(inv(cur));
		// if (i < 2) ps(i,stor[i]);
	}
	// ps((db)(clock()-beg)/CLOCKS_PER_SEC);
	//ps("DONE"); exit(0);
	//exit(0);
	// setIO();
	/*ps(LOG(root));
	ps(LOG(root*root));
	ps(LOG(root*root*root));
	exit(0);*/
	// ps(pow(root,M).x); // exit(0);
	// ps(pow(root,M/factors[0]).x); exit(0);
	int t; re(t);
	F0R(i,t) {
		ul a, b; re(a,b);
		auto A = LOG(a), B = LOG(b);
		bool bad = 0;
		F0R(i,sz(A)) {
			if (A[i] == 0 && B[i] != 0) bad = 1;
		}
		if (bad) ps(-1);
		else {
			ul prod = 1, cur = 0;
			R0F(i,sz(A)) if (A[i] != 0) {
				auto t = factors[i];
				int rem = (ll)B[i]*invGen(A[i],t)%t;
				if (i == sz(A)-1) cur = rem;
				else {
					while (cur%t != rem) cur += prod;
				}
				prod *= t;
			}
			// ps(A,B);
			ps(cur);
		}
	}
	// you should actually read the stuff at the bottom
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
*/