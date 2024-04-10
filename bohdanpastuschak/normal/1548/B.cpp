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

template<typename T>
class SparseTable{
public:
	int n, lg;
	vector<vector<T>> table;
	vector<T> a;

	inline T operation(const T& l, const T& r){
		return __gcd(l, r);
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

LL solve(int n, vector<LL>& a){
	if (n == 0) return 1;
	SparseTable<LL> s(a);
	int ans = 0;
	FOR(i, 0, n){
		if (a[i] == 1) continue;
		if (s.query(i, n - 1) > 1){
			setmax(ans, n - i);
		}else{
			int L = i, R = n - 1;
			while(R - L > 1){
				int M = (L + R) >> 1;
				if (s.query(i, M) > 1) L = M;
				else R = M;
			}
			
			setmax(ans, L - i + 1);			
		}
	}
	
	return ans + 1;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<LL> a(n);
		FOR(i, 0, n) cin >> a[i];
		vector<LL> b(n - 1);
		FOR(i, 0, n - 1) b[i] = abs(a[i + 1] - a[i]);
		cout << solve(n - 1, b) << endl;
	}
	
	cerr << "Time elapsed: " << clock() / (double) CLOCKS_PER_SEC << endl;
	return 0;
}