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
//#define int LL
namespace IntModulo{
	const int mod = 998244353;

	inline int add(int x, int y, int m = mod){
		return x + y < m ? x + y : x + y - m;
	}

	inline int sub(int x, int y, int m = mod){
		return x >= y ? x - y : x - y + m;
	}

	inline int mult(int x, int y, int m = mod){
		return x * (LL) y % m;
	}

	inline int power(int x, LL y, int m = mod){
		int r = 1;
		while(y){
			if (y & 1) r = mult(r, x, m);
			x = mult(x, x, m);
			y >>= 1;
		}
		
		return r;
	}
	
	inline int inverse(int x, int m = mod){
		return power(x, m - 2, m);
	}

	inline void ADD(int& x, int y, int m = mod){
		x += y;
		if (x >= m) x -= m;
	}

	inline void SUB(int& x, int y, int m = mod){
		x -= y;
		if (x < 0) x += m;
	}

	inline void MULT(int& x, int y, int m = mod){
		x = (x * (LL) y) % m;
	}
};

using namespace IntModulo;
const int N = 1 << 18;
int n, x[N], y[N], s[N];
int dp[N], val[N], sval[N];

inline int get(int l, int r){
	return sub(sval[r], l == 0 ? 0 : sval[l - 1]);
}

int32_t main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	cin >> n;
	FOR(i, 1, n + 1) cin >> x[i] >> y[i] >> s[i];
	x[n + 1] = x[n] + 1;
	
	FOR(i, 1, n + 1){
		int pos = lower_bound(x, x + n + 1, y[i]) - x;
		val[i] = add(get(pos, i - 1), x[i] - y[i]);
		sval[i] = add(sval[i - 1], val[i]);
	}
	
	FOR(i, 0, n + 1){	
		if (s[i]) ADD(dp[i], val[i]);
		dp[i + 1] = add(dp[i], x[i + 1] - x[i]);
	}	
	
	cout << dp[n + 1] << endl;	
	
	cerr << "Time elapsed: " << clock() / (double) CLOCKS_PER_SEC << endl;
	return 0;
}