#include <bits/stdc++.h>
using namespace std;

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

int dp[11][1 << 10];

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
		
	int n, m;
	cin >> n >> m;
	dp[0][1] = 1;
	FOR(i, 1, m + 1) FOR(j, 1, n + 1) FOR(k, 1, j + 1)
		ADD(dp[i][j], dp[i - 1][k]);
		
	int ans = 0;
	FOR(i, 1, n + 1) FOR(j, 1, n + 1)
		if (i <= j)
			ADD(ans, mult(dp[m][i], dp[m][n + 1 - j]));	
	cout << ans << endl;
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}