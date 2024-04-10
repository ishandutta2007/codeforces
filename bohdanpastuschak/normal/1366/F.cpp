#include <bits/stdc++.h>
using namespace std;

//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
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

const double PI = acos(-1.0);
const LL INF = 1e9 + 47;
const LL LINF = INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

namespace IntModulo
{
	const int mod = 1e9 + 7;

	inline int add(int x, int y, int m = mod)
	{
		if (x + y < m)
			return x + y;
		return x + y - m;
	}

	inline int sub(int x, int y, int m = mod)
	{
		if (x >= y)
			return x - y;
		return x - y + m;
	}

	inline int mult(int x, int y, int m = mod)
	{
		return x * (LL) y % m;
	}

	inline int power(int x, int y, int m = mod)
	{
		int r = 1;
		while(y)
		{
			if (y & 1)
				r = mult(r, x, m);
			x = mult(x, x, m);
			y >>= 1;
		}
		
		return r;
	}
	
	inline int inverse(int x, int m = mod)
	{
		return power(x, m - 2, m);
	}
	
	inline void ADD(int& x, int y, int m = mod)
	{
		x += y;
		x %= m;
		//if (x >= m) x -= m;
	}
	
	inline void SUB(int& x, int y, int m = mod)
	{
		x -= y;
		if (x < 0) x += m;
	}
	
	inline void MULT(int& x, int y, int m = mod)
	{
		x = (x * (LL) y) % m;
	}
};

using namespace IntModulo;

const int N = 3000;
int n, m, q;
vector<PII> g[N];
int32_t dp[N][N];

inline int sum(int r){
	return r * (LL) (r + 1) / 2 % mod;
}

inline int sum(int l, int r){
	return sub(sum(r) ,sum(l - 1));
}

struct Line{
	int k, b;
	Line(){
		k = b = 0;
	}
	
	Line(int _k, int _b){
		k = _k;
		b = _b;
	}
	
	//f(x) = kx + b
	//f(x) = w * x + weight - w * len
	
	#warning k i b     mod
	
	Line(int w, int weight, int len){
		k = w;
		b = weight - w * len;		
	}
	
	int query(int l, int r){
		int ans = mult((b%mod+mod)%mod, r - l + 1);
		ADD(ans, mult(k, sum(l, r)));
		return ans;
	}		
	
	bool operator<(const Line& l) const{
		if (k != l.k) return k < l.k;
		return b < l.b;
	}
	
	long double intersectX(Line l) { return (long double) (b - l.b) / (l.k - k); }
};

Line all_lines[N * N];
int ptr;
Line d[N * N];
int D;

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	cin >> n >> m >> q;
	while(m--){
		int u, v, w;
		cin >> u >> v >> w;
		--u; --v;
		g[u].PB({v, w});
		g[v].PB({u, w});
	}
	
	FOR(i, 0, N) FOR(j, 0, N) dp[i][j] = -2 * INF;
	dp[0][0] = 0;
	FOR(i, 1, N) FOR(v, 0, n) for(auto u: g[v]){
		setmax(dp[i][v], dp[i - 1][u.X] + u.Y);
	}
	
	int ans = 0;
	FOR(i, 1, n){
		int mx = 0;
		FOR(j, 0, n) setmax(mx, (int)dp[i][j]);
		ADD(ans, mx % mod);		
	}
	
	//ans += f(n) + ... + f(m) + .. + f(q);
	
	FOR(len, 1, n) FOR(v, 0, n) if (dp[len][v] >= 0) for(auto u: g[v]){
		all_lines[ptr++] = Line(u.Y, dp[len][v], len);
	}	
	
	sort(all_lines, all_lines + ptr);
	d[D++] = all_lines[0];
	FOR(i, 1, ptr){
		auto& l = all_lines[i];
		while(D && d[D - 1].k == l.k) D--;
		while(D >= 2 && d[D - 1].intersectX(l) <= d[D - 1].intersectX(d[D - 2])){
			D--;
		}
		
		d[D++] = l;
	}	
	
	const long double EPS = 1e-12;
	int left = n, right = q;
	FOR(i, 0, D){
		if (i == D - 1){
			ADD(ans, d[i].query(left, right));
		}else{
			LL inter = (LL)(d[i].intersectX(d[i + 1]) + EPS);
			if (inter > right) inter = right;
			if (inter >= left){
				ADD(ans, d[i].query(left, (int)inter));
				left = inter + 1;
			}
		}
	}
	
	cout << ans << endl;
    cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}