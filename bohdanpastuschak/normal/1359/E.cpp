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
	const int mod = 998244353;

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
		if (x >= m) x -= m;
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
namespace Combinatorics
{
	using namespace IntModulo;
	
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
		debug(Combinatorics::N);
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
	
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	Combinatorics::init();
	int n, k;
	cin >> n >> k;
		
	int ans = 0;
	FOR(i, 1, n + 1)
	{
		int cnt = 0;
		for(int j = i + i; j <= n; j += i) cnt++;
		
		ADD(ans, Combinatorics::C(cnt, k - 1));
	}
	
	cout << ans << endl;
	
    cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}