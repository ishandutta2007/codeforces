#include <bits/stdc++.h>
using namespace std;
 
typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<double> VD;
#define MP make_pair
#define PB push_back
#define X first
#define Y second
 
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define ITER(it, a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)((a).size())
#define FILL(a, value) memset(a, value, sizeof(a))
#define debug(a) cout << #a << " = " << a << endl;

const double PI = acos(-1.0);
const LL INF = 1e9 + 47;
const LL LINF = INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

namespace Math
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
	
	inline int power(int x, int y, int m  = mod)
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

	int Random(int n)
	{
		return rng() % n;
	}	

	bool MillerRabin(int n, int k)
	{
		if (n <= 3)
			return n > 1;

		int d = n - 1;
		int s = 0;
		while(d % 2 == 0)
		{
			d >>= 1;
			++s;
		}

		FOR(iter, 0, k)
		{
			int a = Random(n - 3) + 2;
			int x = power(a, d, n);
			if (x == 1 || x == n - 1)
				continue;

			bool ok = 0;
			FOR(i, 0, s - 1)
			{
				x = mult(x, x, n);
				if (x == 1)
					return 0;

				if (x == n - 1)
				{
					ok = 1;
					break;
				}
			}

			if (!ok)
				return 0;
		}

		return 1;
	}

	int pollard(int n)
	{
		if (n % 2 == 0)
			return 2;

		int x = Random(n - 2) + 2;
		int c = Random(n - 1) + 1;
		int y = x, d = 1;

		while(d == 1)
		{
			x = add(mult(x, x, n), c, n);
			y = add(mult(y, y, n), c, n);
			y = add(mult(y, y, n), c, n);
			if (x == y)
				return pollard(n);

			d = __gcd(abs(x - y), n);
		}

		return d;
	}
};

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("In.txt", "w", stdout);
	
	int n, m;
	cin >> n >> m;
	
	int ans = Math::power(2, n + m);		
	cout << ans << endl;
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}