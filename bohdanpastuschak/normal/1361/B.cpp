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

int solve(int n, int p, vector<int>& a){
	vector<pair<int, int>> all;
	all.PB({a[0], 1});
	FOR(i, 1, n){
		if (a[i] == a[i - 1]) all.back().Y++;
		else all.PB({a[i], 1});
	}
	
	int i = SZ(all) - 1;
	while(i >= 0){
		if (all[i].Y & 1){
			if (i == 0){
				return power(p, all[0].X);
			}
			
			LL treba = 1;
			int j = i - 1;
			while(true){
				int df = all[j + 1].X - all[j].X;
				LL P = 1;
				FOR(it, 0, df){
					P *= p;
					if (P > n){
						P = n + 1;
						break;
					}
				}
				
				treba *= P;
										
				if (all[j].Y >= treba){
					all[j].Y -= treba;
					i = j;
					break;
				}
				
				if (j == 0 || treba > n){
					int ans = power(p, all[i].X);
					FOR(x, 0, i) SUB(ans, mult(power(p, all[x].X), all[x].Y));
					return ans;
				}	
				
				treba -= all[j].Y;		
				--j;
			}
		}else{
			--i;
		}
	}
	
	return 0;	
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int t;
	cin >> t;
	while(t--){
		int n, p;
		cin >> n >> p;
		vector<int> a(n);
		FOR(i, 0, n) cin >> a[i];
		sort(ALL(a));
		
		if (p == 1){
			cout << (n & 1) << '\n';
			continue;
		}
		
		cout << solve(n, p, a) << '\n';
	}
	
    cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}