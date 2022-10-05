// optimization flags
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
// including std
#include <bits/stdc++.h>
using namespace std;
// use solve instead of main for easy fast input
void solve();
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout<<setprecision(99);
	solve();
}
// generic printing of iterators
template<
	typename T_container, // container type
	typename T = typename enable_if<!is_same<T_container,string>::value, typename T_container::value_type>::type
> ostream& operator<<(ostream& os,const T_container& v){
	os << '{';
	string sep;
	for (const T& x: v) os<< sep << x, sep = ", ";
	return os << '}';
}
// python-ish read and print functions
template<typename T>
T read(){
	T x;
	cin >> x;
	return x;
}
template<typename T>
void read(T& x) {
	cin >> x;
}
template<typename T>
void print(const T& x) {
	cout << x<< "\n";
}
// macro/template hackery to get quick debug info
template<typename L> void DEBUG_(const char* str, L& last) { cout << str << " = " << last << endl; }
template<typename H, typename ...T> void DEBUG_(const char* str, H& val, T&... tail) {
	const char* comma = strchr(str, ',');
	cout << regex_replace(string(str, comma), regex("^ +| +$|( ) +"), "$1") << " = " << val << ", ";
	DEBUG_(comma+1, tail...);
}
#define DEBUG(...) DEBUG_(#__VA_ARGS__, __VA_ARGS__)
// macro hackery to generate new names
#define CONCAT_(x,y) x##y
#define CONCAT(x,y) CONCAT_(x,y)
#define FRESHVAR() CONCAT(__FRESHVAR__, __COUNTER__)
// use 64-bit integers by default
#define int int_fast64_t
#define db double
// iterator utility defines
#define AR array
#define IT(x) (x).begin(),(x).end()
#define sz size
// loop utility defines
#define TIMES_(i,n) for (int i = (n); i > 0; i--)
#define TIMES(n) TIMES_(FRESHVAR(), n)
#define FOR(i,n) for (int i = 0; i < (n); i++)
#define FORS(i,s,n) for (int i = (s); i < (n); i++)
#define FOR1(i,n) for (int i = 1; i <= (n); i++)
#define FORB(i,n)for (int i = (n) - 1; i >= 0; i--)
// common function defines
#define pb push_back
#define vi vector<int>
#define mp make_pair
#define ri read<int>
#define pii pair<int,int>

const string NOYES[2] = {"NO","YES"};
const string NoYes[2] = {"No","Yes"};
const int INF = numeric_limits<int>::max() / 10;

// UTILITY PASTE

const int inf = 1e9;
struct Node {
	Node *l = 0, *r = 0;
	int lo, hi, mset = inf, madd = 0, val = -inf;
	Node(int lo,int hi):lo(lo),hi(hi){} // Large interval of -inf
	Node(vi& v, int lo, int hi) : lo(lo), hi(hi) {
		if (lo + 1 < hi) {
			int mid = lo + (hi - lo)/2;
			l = new Node(v, lo, mid); r = new Node(v, mid, hi);
			val = max(l->val, r->val);
		}
		else val = v[lo];
	}
	int query(int L, int R) {
		if (R <= lo || hi <= L) return -inf;
		if (L <= lo && hi <= R) return val;
		push();
		return max(l->query(L, R), r->query(L, R));
	}
	void set(int L, int R, int x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) mset = val = x, madd = 0;
		else {
			push(), l->set(L, R, x), r->set(L, R, x);
			val = max(l->val, r->val);
		}
	}
	void add(int L, int R, int x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) {
			if (mset != inf) mset |= x;
			else madd |= x;
			val |= x;
		}
		else {
			push(), l->add(L, R, x), r->add(L, R, x);
			val = max(l->val, r->val);
		}
	}
	void push() {
		if (!l) {
			int mid = lo + (hi - lo)/2;
			l = new Node(lo, mid); r = new Node(mid, hi);
		}
		if (mset != inf)
			l->set(lo,hi,mset), r->set(lo,hi,mset), mset = inf;
		else if (madd)
			l->add(lo,hi,madd), r->add(lo,hi,madd), madd = 0;
	}
};

// END UTIL

const int maxN = 500005;
int a[maxN], n;

void solve() {
	TIMES(ri()) {
		cin >> n;
		FOR(i, n) cin >> a[i];
		Node st(0, n+5);
		st.set(0, n+5, 0);
		FOR(i, n) {
			int prev = st.query(0, a[i]+1);
			if (prev & 1) prev++;
			prev = max(prev, (int)0) + 2;
			st.set(a[i], a[i]+1, prev);
			st.add(0, a[i], 1);
			//FOR1(j, n) cout << st.query(j, j+1) << " ";
			//cout << endl;
		}
		cout << (st.query(0, n+1) / 2) << "\n";
	}
}