#ifndef LOCAL
#define NDEBUG
#endif



#include <bits/stdc++.h>
using namespace std;
 
using i64 = int64_t;
using int64 = int64_t;
using uint64 = unsigned int64_t;
using ll = int64_t;
using db =  long double; // or double, if TL is tight
using str = string; // yay python!

using pi = pair<int,int>;
using pl = pair<ll,ll>;
using pd = pair<db,db>;

using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<ll>;
using vd = vector<db>; 
using vs = vector<str>;
using vpi = vector<pi>;
using vpl = vector<pl>; 
using vpd = vector<pd>;

#define tcT template<class T
#define tcTU tcT, class U
// ^ lol this makes everything look weird but I'll try it
tcT> using V = vector<T>; 
tcT, size_t SZ> using AR = array<T,SZ>; 
tcT> using PR = pair<T,T>;

// pairs
#define mp make_pair
#define f first
#define s second

// vectors
// oops size(x), rbegin(x), rend(x) need C++17
#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend() 
#define sor(x) sort(all(x)) 
#define rsz resize
#define ins insert 
#define ft front()
#define bk back()
#define pb push_back
#define eb emplace_back 
#define pf push_front
#define C0(x) memset(x, 0, sizeof(x))
#define C1(x) memset(x, 1, sizeof(x))

#define lb lower_bound
#define ub upper_bound 
tcT> int lwb(V<T>& a, const T& b) { return int(lb(all(a),b)-bg(a)); }

// loops
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)
#define INF 2e18

const db PI = acos((db)-1);
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1}; // for every grid problem!!
template<class T> using min_pq = priority_queue<T,vector<T>,greater<T>>;
template<class T> using max_pq = priority_queue<T,vector<T>,less<T>>;

// bitwise ops
// also see https://gcc.gnu.org/onlinedocs/gcc/Other-Builtins.html
constexpr int pct(int x) { return __builtin_popcount(x); } // # of bits set
constexpr int bits(int x) { // assert(x >= 0); // make C++11 compatible until USACO updates ...
	return x == 0 ? 0 : 31-__builtin_clz(x); } // floor(log2(x)) 
constexpr int p2(int x) { return 1<<x; }
constexpr int msk2(int x) { return p2(x)-1; }

ll cdiv(ll a, ll b) { return a/b+((a^b)>0&&a%b); } // divide a by b rounded up
ll fdiv(ll a, ll b) { return a/b-((a^b)<0&&a%b); } // divide a by b rounded down

tcT> bool ckmin(T& a, const T& b) {
	return b < a ? a = b, 1 : 0; } // set a = min(a,b)
tcT> bool ckmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0; }

tcTU> T fstTrue(T lo, T hi, U f) {
	hi ++; assert(lo <= hi); // assuming f is increasing
	while (lo < hi) { // find first index such that f is true 
		T mid = lo+(hi-lo)/2;
		f(mid) ? hi = mid : lo = mid+1; 
	} 
	return lo;
}
tcTU> T lstTrue(T lo, T hi, U f) {
	lo --; assert(lo <= hi); // assuming f is decreasing
	while (lo < hi) { // find first index such that f is true 
		T mid = lo+(hi-lo+1)/2;
		f(mid) ? lo = mid : hi = mid-1;
	} 
	return lo;
}
tcT> void remDup(vector<T>& v) { // sort and remove duplicates
	sort(all(v)); v.erase(unique(all(v)),end(v)); }
tcTU> void erase(T& t, const U& u) { // don't erase
	auto it = t.find(u); assert(it != end(t));
	t.erase(it); } // element that doesn't exist from (multi)set

// INPUT
#define tcTUU tcT, class ...U
tcT> void re(complex<T>& c);
tcTU> void re(pair<T,U>& p);
tcT> void re(V<T>& v);
tcT, size_t SZ> void re(AR<T,SZ>& a);

tcT> void re(T& x) { cin >> x; }
void re(double& d) { str t; re(t); d = stod(t); }
void re(long double& d) { str t; re(t); d = stold(t); }
tcTUU> void re(T& t, U&... u) { re(t); re(u...); }

tcT> void re(complex<T>& c) { T a,b; re(a,b); c = {a,b}; }
tcTU> void re(pair<T,U>& p) { re(p.f,p.s); }
tcT> void re(V<T>& x) { trav(a,x) re(a); }
tcT, size_t SZ> void re(AR<T,SZ>& x) { trav(a,x) re(a); }
tcT> void rv(int n, V<T>& x) { x.rsz(n); re(x); }

// TO_STRING
#define ts to_string
str ts(char c) { return str(1,c); }
str ts(const char* s) { return (str)s; }
str ts(str s) { return s; }
str ts(bool b) { 
	#ifdef LOCAL
		return b ? "true" : "false"; 
	#else 
		return ts((int)b);
	#endif
}
tcT> str ts(complex<T> c) { 
	stringstream ss; ss << c; return ss.str(); }
str ts(V<bool> v) {
	str res = "{"; F0R(i,sz(v)) res += char('0'+v[i]);
	res += "}"; return res; }
template<size_t SZ> str ts(bitset<SZ> b) {
	str res = ""; F0R(i,SZ) res += char('0'+b[i]);
	return res; }
tcTU> str ts(pair<T,U> p);
tcT> str ts(T v) { // containers with begin(), end()
	#ifdef LOCAL
		bool fst = 1; str res = "{";
		for (const auto& x: v) {
			if (!fst) res += ", ";
			fst = 0; res += ts(x);
		}
		res += "}"; return res;
	#else
		bool fst = 1; str res = "";
		for (const auto& x: v) {
			if (!fst) res += " ";
			fst = 0; res += ts(x);
		}
		return res;

	#endif
}
tcTU> str ts(pair<T,U> p) {
	#ifdef LOCAL
		return "("+ts(p.f)+", "+ts(p.s)+")"; 
	#else
		return ts(p.f)+" "+ts(p.s);
	#endif
}

// OUTPUT
tcT> void pr(T x) { cout << ts(x); }
tcTUU> void pr(const T& t, const U&... u) { 
	pr(t); pr(u...); }
void ps() { pr("\n"); } // print w/ spaces
tcTUU> void ps(const T& t, const U&... u) { 
	pr(t); if (sizeof...(u)) pr(" "); ps(u...); }

// DEBUG
void DBG() { cerr << "]" << endl; }
tcTUU> void DBG(const T& t, const U&... u) {
	cerr << ts(t); if (sizeof...(u)) cerr << ", ";
	DBG(u...); }
#ifdef LOCAL // compile with -DLOCAL, chk -> fake assert
	#define dbg(...) cerr << "Line(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
	#define chk(...) if (!(__VA_ARGS__)) cerr << "Line(" << __LINE__ << ") -> function(" \
		 << __FUNCTION__  << ") -> CHK FAILED: (" << #__VA_ARGS__ << ")" << "\n", exit(0);
#else
	#define dbg(...) 0
	#define chk(...) 0
#endif

#ifndef LOCAL
std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
#else
std::mt19937 rng(0);
#endif
template<class T>
T Rand(T l, T r) {
	std::uniform_int_distribution<T> random(l, r);
	return random(rng);
}
#ifndef PREC
#define PREC 1e-12
#endif




void Init();

void SolveFast(int testNum, istream& in, ostream& out);

void SolveSlow(int testNum, istream& in, ostream& out);

string GenerateInput(int testNum);

bool MatchOutput(const string& input, const string &slow, const string &fast);

string Printable(string s){
	if(s.size() > 200){
		s = s.substr(0, 200) + "\n...";
	}
	return s;
}
#if (defined STRESS) && (defined LOCAL)
void Stress(){
	for(int i = 1; i <= 10000; i++) {
		std::cerr << "TEST " << i << ":" << std::endl;
		string input = GenerateInput(i);
		string print_input = input;
		std::cerr << "INPUT:\n" << Printable(input) << std::endl;
		
		stringstream fast_output;
		stringstream slow_output;
		stringstream fast_input = stringstream(input);
		stringstream slow_input = stringstream(input);
		SolveSlow(1, slow_input, slow_output);
		std::cerr << "EXPECT:\n" << Printable(slow_output.str()) << std::endl;
		SolveFast(1, fast_input, fast_output);		
		std::cerr << "EXECUTE:\n" << Printable(fast_output.str()) << std::endl;
		
		if(MatchOutput(input, slow_output.str(), fast_output.str())){
			std::cerr << "Verdict: PASS" << std::endl;
		}else{
			std::cerr << "Verdict: FAIL" << std::endl;
			std::cerr << "INPUT:" << std::endl << input << std::endl;
			std::cerr << "SLOW:" << std::endl << slow_output.str() << std::endl;
			std::cerr << "FAST:" << std::endl << fast_output.str() << std::endl;
			exit(1);
		}
	}
}
#endif

void Solve(){
	int t = 1;
#ifdef MULTI_TEST
	std::cin >> t;
#endif
	for(int i = 1; 
#ifdef EOF_TEST
	!std::cin.eof();
#else	
	i <= t;
#endif
	i++){
		SolveFast(i, std::cin, std::cout);
	}
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout << std::setiosflags(std::ios::fixed);
    std::cout << std::setprecision(15);

	Init();
#if (defined STRESS) && (defined LOCAL)
    Stress();
#else
	Solve();
#endif

    return 0;
}


int fib[30];
const int LIM = 200000 + 10;
int inv[LIM];
int sizes[LIM];
V<vi> g;

void dfsForSize(int root, int p) {
	sizes[root] = 1;
	for (int node : g[root]) {
		if (node == p) {
			continue;
		}
		dfsForSize(node, root);
		sizes[root] += sizes[node];
	}
}

pair<int, int> findPair(int root, int p, int target, int total) {
	if (sizes[root] == target || total - sizes[root] == target) {
		return mp(root, p);
	}
	for (int node : g[root]) {
		if (node == p) {
			continue;
		}
		pair<int, int> ans = findPair(node, root, target, total);
		if (ans.first != -1) {
			return ans;
		}
	}
	return mp(-1, -1);
}

void removeElement(vi &adj, int v) {
	for (auto x = adj.begin(); x != adj.end(); x++) {
		if (*x == v) {
			adj.erase(x);
			return;
		}
	}
	assert(false);
}

bool check(int root) {
	dfsForSize(root, -1);
	if (sizes[root] <= 2) {
		return true;
	}
	int x = inv[sizes[root]];
	pair<int, int> p = findPair(root, -1, fib[x - 1], sizes[root]);
	if (p.first == -1) {
		return false;
	}
	removeElement(g[p.first], p.second);
	removeElement(g[p.second], p.first);
	return check(p.first) && check(p.second);
}



void SolveFast(int testNum, istream& in, ostream& out) {
	int n;
	in >> n;
	int index = -1;
	g.resize(n);
	for (int i = 0; i < 30; i++) {
		if (fib[i] == n) {
			index = i;
		}
	}
	if (index == -1) {
		out << ("NO");
		return;
	}
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		in >> a >> b;
		a--; b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	out << (check(0) ? "YES" : "NO");
}

void Init() {
	fib[0] = fib[1] = 1;
	inv[1] = 1;
	for (int i = 2; i < 30; i++) {
		fib[i] = fib[i - 1] + fib[i - 2];
		if (fib[i] < LIM) {
			inv[fib[i]] = i;
		}
	}
}
void SolveSlow(int testNum, istream& in, ostream& out) {}
string GenerateInput(int testNum) {return string();}
bool MatchOutput(const string &input, const string &slow, const string &fast) {return slow == fast;}