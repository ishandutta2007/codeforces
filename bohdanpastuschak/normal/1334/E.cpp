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

LL n;
vector<pair<LL, int>> p;
const int N = 60;
int f[N];
int inv[N];

int solve(LL u, LL v)
{
	int Sum1 = 0, Sum2 = 0;
	int ans = 1;
	
	for(auto i: p) 
	{
		int tut1 = 0, tut2 = 0;
		while(u % i.X == 0) tut1++, u /= i.X;
		while(v % i.X == 0) tut2++, v /= i.X;
		if (tut1 > tut2) tut1 -= tut2, tut2 = 0;
		else tut2 -= tut1, tut1 = 0;
		MULT(ans, inv[tut1]);
		MULT(ans, inv[tut2]);
		Sum1 += tut1;
		Sum2 += tut2;
	}
	
	MULT(ans, f[Sum1]);
	MULT(ans, f[Sum2]);
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	f[0] = 1;
	FOR(i, 1, N) f[i] = mult(i, f[i - 1]);
	FOR(i, 0, N) inv[i] = power(f[i], mod - 2);
	
	cin >> n;
	LL D = n;
	for(int i = 2; i * (LL) i <= D; ++i) if (D % i == 0)
	{
		p.PB({i, 0});
		while(D % i == 0) D /= i, p.back().Y++;
	}
	if (D > 1) p.PB({D, 1});
	
	int q;
	cin >> q;
	while(q--)
	{
		LL u, v;
		cin >> u >> v;
		cout << solve(u, v) << '\n';
	}	
		
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}