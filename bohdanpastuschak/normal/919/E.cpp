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

const double PI = acos(-1.0);
const LL INF = 1e9 + 47;
const LL LINF = INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int mult(int x, int y, int mod)
{
	return x * (LL) y % mod;
}

int power(int x, int y, int mod)
{
	int r = 1;
	while(y)
	{
		if (y & 1) r = mult(r, x, mod);
		x = mult(x, x, mod);
		y >>= 1;
	}
	
	return r;
}

int inverse(int x, int mod)
{
	return power(x, mod - 2, mod);
}

int phi(int x)
{
	int res = x;
	for(int i = 2; i * i <= x; ++i)
		if (x % i == 0)
		{
			while(x % i == 0) x /= i;
			res /= i;
			res *= i - 1;
		}
	if (x > 1)
		res /= x, res *= x - 1;
	return res;
}

int phi_p1, phi_p2;

LL chinese(int a1, int a2, int p1, int p2)
{
	LL res = a1 *  (LL) p2 * power(p2, phi_p1 - 1, p1) + 
			 a2 *  (LL) p1 * power(p1, phi_p2 - 1, p2);
	return res % (p1 * (LL) p2);
}

int main()
{
	int a, b, p;
	LL x;
	cin >> a >> b >> p >> x;
	//FOR(n, 1, x + 1) if (mult(n, power(a, n, p), p) == b) debug(n)
	phi_p2 = p - 1;
	phi_p1 = phi(p - 1);
	
	LL ans = 0;
	FOR(i, 0, p - 1)
	{
		int mod_p = mult(b, inverse(power(a, i, p), p), p);
		LL tut = chinese(i, mod_p, p - 1, p);
		LL cila = x / p / (p - 1);
		LL drobova = x % (p * (LL) (p - 1));
		ans += cila;
		ans += tut <= drobova;
	}
		
	cout << ans << endl;
	return 0;
}