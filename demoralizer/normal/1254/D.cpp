#include <bits/stdc++.h>
using namespace std;
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
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

const long long INF=1e18;
const int32_t M=998244353;

const int N=15e4+20;

const int32_t MOD = M;
struct mod_int {
	int32_t val;
	mod_int(long long v = 0) {if (v < 0) v = v % MOD + MOD; if (v >= MOD) v %= MOD; val = v; }

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
	mod_int& operator+=(const mod_int &other) {val += other.val; if (val >= MOD) val -= MOD; return *this; }
	mod_int& operator-=(const mod_int &other) {val -= other.val; if (val < 0) val += MOD; return *this; }
	mod_int& operator*=(const mod_int &other) {val = fast_mod((uint64_t) val * other.val); return *this; }
	mod_int& operator/=(const mod_int &other) {return *this *= other.inv(); }
	friend mod_int operator+(const mod_int &a, const mod_int &b) { return mod_int(a) += b; }
	friend mod_int operator-(const mod_int &a, const mod_int &b) { return mod_int(a) -= b; }
	friend mod_int operator*(const mod_int &a, const mod_int &b) { return mod_int(a) *= b; }
	friend mod_int operator/(const mod_int &a, const mod_int &b) { return mod_int(a) /= b; }
	mod_int& operator++() {val = val == MOD - 1 ? 0 : val + 1; return *this; }
	mod_int& operator--() {val = val == 0 ? MOD - 1 : val - 1; return *this; }
	mod_int operator++(int32_t) { mod_int before = *this; ++*this; return before; }
	mod_int operator--(int32_t) { mod_int before = *this; --*this; return before; }
	mod_int operator-() const {return val == 0 ? 0 : MOD - val; }
	bool operator==(const mod_int &other) const { return val == other.val; }
	bool operator!=(const mod_int &other) const { return val != other.val; }
	mod_int inv() const {return mod_inv(val); }
	friend ostream& operator<<(ostream &stream, const mod_int &m) {return stream << m.val; }
	friend istream& operator>>(istream &stream, mod_int &m) {return stream >> m.val; }

	mod_int pow(long long p) const {
		assert(p >= 0);
		mod_int a = *this, result = 1;
		while (p > 0) {
			if (p & 1)
				result *= a;
			
			a *= a;
			p >>= 1;
		}
		return result;
	}
};

#define SIZE   N
#define LSB(i) ((i) & -(i)) // zeroes all the bits except the least significant one

mod_int A[SIZE];

mod_int query(int i) // Returns the sum from index 1 to i
{
	mod_int sum = 0;
	while (i > 0) 
		sum += A[i], i -= LSB(i);
	return sum;
}

mod_int rq(int x,int y){
	return query(y) - query(x-1);
}

void update(int i, mod_int k) // Adds k to element with index i
{
	if(!i)return;
	while (i < SIZE) 
		A[i] += k, i += LSB(i);
}


vector<int> v[N];
int tin[N],tout[N],par[N],siz[N],heavy[N],head[N];
int tim=1;
mod_int d[N];
void dfs_sz(int z,int p){
	siz[z]=1;
	par[z]=p;
	for(int x:v[z]){
		if(x==p)continue;
		dfs_sz(x,z);
		if(siz[x] > siz[heavy[z]]){
			heavy[z]=x;
		}
		siz[z]+=siz[x];
	}
}

void decompose(int z){
	tin[z]=tim++;
	if(heavy[par[z]] == z)head[z]=head[par[z]];
	else head[z]=z;
	if(heavy[z]){
		decompose(heavy[z]);
	}
	for(int x:v[z]){
		if(x==par[z] || x==heavy[z])continue;
		decompose(x);
	}
	tout[z]=tim;
}

mod_int allans=0;

void solve(){
	int n,m;
	cin>>n>>m;
	rep(i,1,n){
		int x,y;
		cin>>x>>y;
		v[x].pb(y);
		v[y].pb(x);
	}
	dfs_sz(1,0);
	decompose(1);
	mod_int inv=1;
	inv/=n;
	rep(i,0,m){
		int t,z;
		cin>>t>>z;
		if(t==1){
			int x;
			cin>>x;
			d[z]+=x;
			allans += mod_int(x)*siz[z];
			update(tin[heavy[z]],(n-siz[z]-siz[heavy[z]])*mod_int(x));
		}
		else{
			mod_int ans=allans;
			ans += (n-siz[z])*d[z];
			int k=z;
			while(k){
				ans += rq(tin[head[k]],tin[k]);
				k = head[k];
				ans += (n-siz[k]-siz[par[k]])*d[par[k]];
				k = par[k];
			}
			cout<<ans*inv<<"\n";
		}
	}
	
	
	
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#ifdef SEIVE
		seive();
	#endif
	#ifdef NCR
		init();
	#endif
	int t=1;
	//cin>>t;
	while(t--) solve();
	return 0;
}