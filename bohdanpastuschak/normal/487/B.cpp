#include <bits/stdc++.h>
using namespace std;

//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef long double db;

#define MP make_pair
#define PB push_back
#define X first
#define Y second

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)((a).size())
#define FILL(a, value) memset(a, value, sizeof(a))
#define debug(a) cerr << #a << " = " << a << endl;

template<typename T> void setmax(T& x, T y) {x = max(x, y);}
template<typename T> void setmin(T& x, T y) {x = min(x, y);}

template<typename T> void print(const T& a, ostream& out){	
	for(auto i: a) out << i << ' ';
	out << endl;
}

const double PI = acos(-1.0);
const LL INF = 1e9 + 47;
const LL LINF = INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template <typename T, typename R>
class SegmentTree{
public:
	int n;
	vector<R> t;

	SegmentTree(){}
	SegmentTree(int _n){
		n = _n;
		t.assign(4 * n, 0);
	}

	inline R combine(const R& l, const R& r){
		//change here and in query!!!
		return min(l, r);
	}
	
	void build(const vector<T>& a, int v, int tl, int tr){
		if (tl == tr){
			t[v] = a[tl];
		}else{
			int tm = (tl + tr) >> 1;
			build(a, v * 2, tl, tm);
			build(a, v * 2 + 1, tm + 1, tr);
			t[v] = combine(t[v * 2], t[v * 2 + 1]);
		}	
	}

	inline void change(int v, int tl, int tr, int pos, T val){
		if (tl == tr){
			t[v] = val;
		}else{
			int tm = (tl + tr) >> 1;
			if (pos <= tm){
				change(v * 2, tl, tm, pos, val);
			}else{
				change(v * 2 + 1, tm + 1, tr, pos, val);
			}
			t[v] = combine(t[v * 2], t[v * 2 + 1]);
		}
	}

	inline R query(int v, int tl, int tr, int l, int r){
		if (l > r || tl > tr){
			return INF;
		}

		if (l == tl && r == tr){
			return t[v];
		}else{
			int tm = (tl + tr) >> 1;
			return combine(query(v * 2, tl, tm, l, min(r, tm)), query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
		}	
	}
};

template<typename T>
class SparseTable1{
public:
	int n, lg;
	vector<vector<T>> table;
	vector<T> a;

	inline T operation(const T& l, const T& r){
		return max(l, r);
	}
	
	void build(){
		FOR(i, 0, n) table[i][0] = a[i];		
		FOR(len, 0, lg - 1) FOR(i, 0, n){
			table[i][len + 1] = i + (1 << len) >= n ? table[i][len] :
			operation(table[i][len], table[i + (1 << len)][len]);			
		}
	}

	T query(int l, int r){
		const int LOG = 31 - __builtin_clz(r - l + 1);
		return operation(table[l][LOG], table[r - (1 << LOG) + 1][LOG]);
	}

	void init(){
		lg = 1;
		while((1 << lg) <= n) lg++;

		table.resize(n);
		FOR(i, 0, n) table[i].resize(lg);
		
		build();
	}
	
	SparseTable1(){}
	SparseTable1(const vector<T>& A){
		n = SZ(A);
		a = A;
		init();
	}

	SparseTable1(int _n, const T* A){
		n = _n;
		a.resize(n);
		FOR(i, 0, n) a[i] = A[i];
		init();
	}	
};

template<typename T>
class SparseTable{
public:
	int n, lg;
	vector<vector<T>> table;
	vector<T> a;

	inline T operation(const T& l, const T& r){
		return min(l, r);
	}
	
	void build(){
		FOR(i, 0, n) table[i][0] = a[i];		
		FOR(len, 0, lg - 1) FOR(i, 0, n){
			table[i][len + 1] = i + (1 << len) >= n ? table[i][len] :
			operation(table[i][len], table[i + (1 << len)][len]);			
		}
	}

	T query(int l, int r){
		const int LOG = 31 - __builtin_clz(r - l + 1);
		return operation(table[l][LOG], table[r - (1 << LOG) + 1][LOG]);
	}

	void init(){
		lg = 1;
		while((1 << lg) <= n) lg++;

		table.resize(n);
		FOR(i, 0, n) table[i].resize(lg);
		
		build();
	}
	
	SparseTable(){}
	SparseTable(const vector<T>& A){
		n = SZ(A);
		a = A;
		init();
	}

	SparseTable(int _n, const T* A){
		n = _n;
		a.resize(n);
		FOR(i, 0, n) a[i] = A[i];
		init();
	}	
};

void no(){
	cout << -1 << endl;
	exit(0);
}

const int N = 1 << 17;
int n, s, l;
PII to[N];
	
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> n >> s >> l;
	vector<int> a(n);
	FOR(i, 0, n) cin >> a[i];

	SparseTable<int> mn(a);
	SparseTable1<int> mx(a);

	FILL(to, -1);
	FOR(i, l - 1, n){
		int MN = mn.query(i - l + 1, i);
		int MX = mx.query(i - l + 1, i);
		if (MX - MN > s){
			continue;
		}

		int L = -1, R = i - l + 1, M;
		while(R - L > 1){
			M = (L + R) >> 1;
			MN = mn.query(M, i);
			MX = mx.query(M, i);
			if (MX - MN <= s) R = M;
			else L = M;
		}
		
		to[i] = {R, i - l + 1};
	}

	vector<int> dp(n + 1, INF);
	SegmentTree<int, int> SG(n+1);
	VI A(n+1, INF);
	A[0] = 0;
	SG.build(A, 1, 0, n);

	FOR(i, 0, n){
		int& res = dp[i + 1];
		if (to[i].X != -1){
			res = SG.query(1, 0, n, to[i].X, to[i].Y) + 1;			
		}
		
		SG.change(1, 0, n, i + 1, res);
	}
	
	cout << (dp[n] >= INF ? -1 : dp[n]) << endl;
    
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}