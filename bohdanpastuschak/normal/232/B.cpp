#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")

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

	inline int power(int x, LL y, int m = mod)
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
	
namespace Combinatorics
{
	
	const int N = 1 << 20;
	int fact[N];
	int inv[N];
	int invFact[N];
	bool inited = false;
	
	inline int C(int n, int k) // binomial C(n, k)
	{
		return n < k ? 0 : mult(fact[n], mult(invFact[k], invFact[n - k]));
	}
	
	inline int H(int n, int k) // number of solution x1 + .. + xn = k
	{
		return C(n + k - 1, k);
	}
	
	void init()
	{
		inited = true;
		inv[1] = 1;
		FOR(i, 2, N)
			inv[i] = mult(mod - mod / i, inv[mod % i]);
		
		invFact[0] = fact[0] = 1;
		FOR(i, 1, N)
		{
			fact[i] = mult(i, fact[i - 1]);
			invFact[i] = mult(invFact[i - 1], inv[i]);
		}
	}	
};

const int N = 1 << 7;
int n, k;
LL m;
int dp[N][N * N];
int KOEF[N][2];
LL cnt[2];

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	Combinatorics::init();
	cin >> n >> m >> k;
	cnt[0] = m / n;
	cnt[1] = cnt[0] + 1;
	FOR(i, 0, n + 1) FOR(j, 0, 2){
		KOEF[i][j] = power(Combinatorics::C(n, i), cnt[j]);
	}
	
	dp[0][0] = 1;
	FOR(i, 0, n){
		FOR(bulo, 0, k + 1) FOR(tut, 0, n + 1){
			if (bulo + tut > k) break;
			ADD(dp[i + 1][bulo + tut], mult(dp[i][bulo], KOEF[tut][m % n > i]));
		}
	}
	
	cout << dp[n][k] << endl;
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}