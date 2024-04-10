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
		x = x * (LL) y % m;
	}
};

namespace Combinatorics
{
	using namespace IntModulo;
	
	const int N = 10000 + 57;
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

namespace BerlekampMassey
{
	using namespace IntModulo;
		
	inline vector<int> BM(vector<int> x)
	{
		vector<int> ls, cur;
		int lf, ld;
		
		FOR(i, 0, SZ(x))
		{
			int t = 0;
			FOR(j, 0, SZ(cur))
				t = add(t, mult(x[i - j - 1], cur[j]));
				
			if (t == x[i])
				continue;
							
			if(!SZ(cur))
			{
				cur.resize(i + 1);
				lf = i;
				ld = sub(t, x[i]);
				continue;
			}
			
			int k = mult(sub(t, x[i]), inverse(ld));
			vector<int> c(i - lf - 1); 
			c.PB(k);
			
			FOR(j, 0, SZ(ls))
				c.PB(sub(0, mult(k, ls[j])));
				
			if (SZ(c) < SZ(cur))
				c.resize(SZ(cur));
				
			FOR(j, 0, SZ(cur))
				c[j] = add(c[j], cur[j]);
			
			if (i - lf + SZ(ls) >= SZ(cur))
			{
				ls = cur;
				lf = i;
				ld = sub(t, x[i]);
			}
			
			cur = c;
		}
	
		return cur;
	}
	
	inline void multiply(int m, vector<int>& p, vector<int>& q, vector<int>& v)
	{
		vector<int> t(2 * m, 0);
		
		FOR(i, 0, m) 
			FOR(j, 0, m)			
				t[i + j] = add(t[i + j], mult(p[i], q[j]));
				
		RFOR(i, 2 * m, m)
			RFOR(j, m, 0)
				t[i - j - 1] = add(t[i - j - 1], mult(t[i], v[j]));
				
		FOR(i, 0, m)
			p[i] = t[i];
	}
	
	inline int solve(vector<int> x, LL n)
	{
		if ((int) n < SZ(x))
			return x[n];
		
		vector<int> v = BM(x);
		int m = v.size(); 
		if(!m)
			return 0;
		
		VI s(m + 1, 0);
		VI t(m + 1, 0);
		s[0] = 1; 	
		t[1] = 1;		
		if (m == 1)
			t[0] = v[0];
		
		while(n)
		{
			if (n & 1) 
				multiply(m, s, t, v);
			multiply(m, t, t, v);
			n >>= 1;
		}
		
		int ans = 0;
		FOR(i, 0, m)
			ans = add(ans, mult(s[i], x[i]));
		return ans;
	}	
};

namespace LagrangeInterpolation
{
	using namespace Combinatorics;
	
	int solve(vector<int>& y, LL x) //Polynomial on degree k passing through points 1, 2, .., k + 1
	{
		int n = SZ(y);	
		if ((int) x < n)
			return y[x];
			
		if (!Combinatorics::inited)
			Combinatorics::init();
			
		vector<int> pref(n);
		pref[0] = 1;
		FOR(i, 1, n)
			pref[i] = mult(pref[i - 1], (x - i) % mod);
		
		vector<int> suf(n + 1);
		suf[n] = 1;
		RFOR(i, n, 1)
			suf[i] = mult(suf[i + 1], (x - i) % mod);
		
		int ans = 0;
		FOR(i, 1, n)
		{
			int tut = mult(y[i], 
				mult(pref[i - 1], mult(suf[i + 1], 
				mult(invFact[i - 1], invFact[n - i - 1]))));
				
			if ((n - i) & 1)
				ans = add(ans, tut);
			else
				ans = sub(ans, tut);
		}
		
		return ans;		
	}  	

	int powerSum(int k, LL n) // Sum(i, 1, n) i^k
	{
		vector<int> y(k + 3, 0);
		FOR(i, 1, SZ(y))
			y[i] = add(y[i - 1], power(i, k));
		
		return solve(y, n);
	}
};

using namespace IntModulo;

const int N = 10000 + 57;
int p[N];
int q[N];
int x[N];

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n, m, k;
	cin >> n >> m >> k;
	Combinatorics::init();
	
	p[0] = q[0] = 1;
	p[1] = inverse(m);
	q[1] = sub(1, p[1]);
	
	FOR(i, 2, N) p[i] = mult(p[i - 1], p[1]);
	FOR(i, 2, N) q[i] = mult(q[i - 1], q[1]);
	FOR(i, 1, N) x[i] = power(i, k);
	
	vector<int> ans(k + 2, 0);
	FOR(nn, 0, k + 2)
	{
		int tut = 0;
		FOR(i, 1, nn + 1)
			ADD(tut, mult(p[i], mult(q[nn - i], mult(x[i], Combinatorics::C(nn, i)))));
		ans[nn] = tut;
	}
	
	cout << LagrangeInterpolation::solve(ans, n) << endl;
	//cout << BerlekampMassey::solve(ans, n) << endl;
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}