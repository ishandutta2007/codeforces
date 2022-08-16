#include "bits/stdc++.h"
using namespace std;
#define int               long long
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define uniq(v)           (v).erase(unique(all(v)),(v).end())
#define sz(x)             (int)((x).size())
#define fr                first
#define sc                second
#define pii               pair<int,int>
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define ppc               __builtin_popcount
#define ppcll             __builtin_popcountll

template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.fr>>a.sc;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.fr<<" "<<a.sc;return out;}
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}

const int M = 1e9 + 7;

template<int32_t MOD>
struct mod_field {
	int32_t val;
	mod_field(long long v = 0) {if (v < 0) v = v % MOD + MOD; if (v >= MOD) v %= MOD; val = v; }

	static int32_t mod_inv(int32_t a, int32_t m = MOD) {
		int32_t g = m, r = a, x = 0, y = 1;
		while (r != 0) {
			int32_t q = g / r;
			g %= r; swap(g, r);
			x -= q * y; swap(x, y);
		}
		return x < 0 ? x + m : x;
	}
	static unsigned fast_mod(uint64_t x, unsigned m = MOD) {
		#if !defined(_WIN32) || defined(_WIN64)
		return x % m;
		#endif
		unsigned x_high = x >> 32, x_low = (unsigned) x;
		unsigned quot, rem;
		asm("divl %4\n"
			: "=a" (quot), "=d" (rem)
			: "d" (x_high), "a" (x_low), "r" (m));
		return rem;
	}

	explicit operator int() const {return val; }
	mod_field& operator+=(const mod_field &other) {val += other.val; if (val >= MOD) val -= MOD; return *this; }
	mod_field& operator-=(const mod_field &other) {val -= other.val; if (val < 0) val += MOD; return *this; }
	mod_field& operator*=(const mod_field &other) {val = fast_mod((uint64_t) val * other.val); return *this; }
	mod_field& operator/=(const mod_field &other) {return *this *= other.inv(); }
	friend mod_field operator+(const mod_field &a, const mod_field &b) { return mod_field(a) += b; }
	friend mod_field operator-(const mod_field &a, const mod_field &b) { return mod_field(a) -= b; }
	friend mod_field operator*(const mod_field &a, const mod_field &b) { return mod_field(a) *= b; }
	friend mod_field operator/(const mod_field &a, const mod_field &b) { return mod_field(a) /= b; }
	mod_field& operator++() {val = val == MOD - 1 ? 0 : val + 1; return *this; }
	mod_field& operator--() {val = val == 0 ? MOD - 1 : val - 1; return *this; }
	mod_field operator++(int32_t) { mod_field before = *this; ++*this; return before; }
	mod_field operator--(int32_t) { mod_field before = *this; --*this; return before; }
	mod_field operator-() const {return val == 0 ? 0 : MOD - val; }
	bool operator==(const mod_field &other) const { return val == other.val; }
	bool operator!=(const mod_field &other) const { return val != other.val; }
	mod_field inv() const {return mod_inv(val); }
	friend ostream& operator<<(ostream &stream, const mod_field &m) {return stream << m.val; }
	friend istream& operator>>(istream &stream, mod_field &m) {return stream >> m.val; }

	mod_field pow(long long p) const {
		assert(p >= 0);
		mod_field a = *this, result = 1;
		while (p > 0) {
			if (p & 1)
				result *= a;
			
			a *= a;
			p >>= 1;
		}
		return result;
	}
};
typedef mod_field<M> mod_int;

const int N=2005;

int a[N];

void solve(){
	int n,h;
	cin>>n>>h;
	
	rep(i,1,n+1){
		cin>>a[i];
		a[i] = h - a[i];
	}
	
	if(a[1] > 1 || a[n] > 1){
		cout<<0;
		return;
	}
	
	mod_int ans = 1;
	
	rep(i,1,n){
		if(abs(a[i] - a[i+1]) > 1 || a[i] < 0 || a[i+1] < 0){
			cout<<0;
			return;
		}
		if(a[i] >= a[i+1]){
			ans *= (a[i+1]+1);
		}
	}
	
	cout<<ans;
	
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#ifdef SIEVE
		sieve();
	#endif
	#ifdef NCR
		init();
	#endif
	int t=1;
	//cin>>t;
	while(t--) solve();
	return 0;
}