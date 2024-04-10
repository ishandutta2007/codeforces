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

int sum(int x, LL k)//x^1 + x^2 + ... + x^(k-1)
{
	if (x == 0) return 1;
	if (x == 1) return k % mod;
	return mult(power(x, k) - 1, inverse(x - 1));
}

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
			if (n < SZ(x))
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

	

int f(LL k, int a, int b)
{
	if (!b) return 1;
	if (a == b) return mult(b, power(a + b, k - 1));
	
	
	vector<int> F(1111);
	F[0] = 1;
	FOR(i, 1, 1111)
		F[i] = add(mult(a, F[i - 1]), mult(b, sub(power(a + b, i - 1), F[i - 1])));
	
	//debug(F[k])
	return BerlekampMassey::solve(F, k);
}

int n, m, r;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int l;
	cin >> n >> m >> l >> r;
	r = r - l + 1;	
	
	if ((n & 1) && (m & 1))
		cout << power(r, n * (LL) m) << endl;
	else 
	{
	
		cout << f(n * (LL) m, (r + 1) / 2, r / 2) << endl;
	}
	
	//cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}