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
const int N = 5000 + 7;
int n, m;
int s[N];
int f[N];
int h[N];
int l[N];
int r[N];
vector<int> id[N];
int G[N];
int Res[N][N];
int KEK[N];

int GR()
{
	int ans = 0;
	FOR(i, 1, n + 1)
	{
		if (SZ(id[i]) == 0) continue;
		
		int hto = id[i][0];
		if (r[hto] >= 1) ans++;
	}
	
	return ans;
}

int S()
{
	int ans = 1;
	FOR(i, 1, n + 1)
	{
		int cnt = 0;
		for(auto j: id[i]) cnt += r[j] >= 1;
		if (cnt) MULT(ans, cnt);
	}
	
	return ans;
}

inline int get(int max_l)
{
	if (max_l == 0) return GR();
	int min_r = max_l + 1;
	int ans = 0;
	
	int Id = s[max_l];
	if (SZ(id[Id]) == 0) return -1;
	
	bool ok = 0;
	for(auto j: id[Id]) if (l[j] != max_l)
		ans |= r[j] >= min_r;
	else ok = 1;
	
	if (!ok) return -1;
	ans++;
	
	FOR(i, 1, n + 1)
	{
		if (i == s[max_l]) continue;
		
		if (SZ(id[i]) == 0) continue;
		if (SZ(id[i]) == 1)
		{
			int hto = id[i][0];
			if (l[hto] <= max_l) ans++, Res[max_l][i] = 1;
			else if (r[hto] >= min_r) ans++, Res[max_l][i] = 1;
			
			continue;
		}
		
		int hto1 = id[i][0], hto2 = id[i][1];
		if (l[hto1] <= max_l && r[hto2] >= min_r)
		{
			Res[max_l][i] = 2;
			ans += 2;
			continue;
		}
		
		if (l[hto2] <= max_l && r[hto1] >= min_r)
		{
			Res[max_l][i] = 2;
			ans += 2;
			continue;
		}
		
		if (l[hto1] <= max_l || r[hto1] >= min_r) 
		{
			ans++;
			Res[max_l][i] = 1;
		}
	}
	
	return ans;
}

int solve(int max_l)
{
	if (max_l == 0) return S();
	int min_r = max_l + 1;
	int ans = 1;
	
	int Id = s[max_l];
	if (SZ(id[Id]) > 1)
	{
		int can_r = 0;
		for(auto j: id[Id])
		{
			if (l[j] == max_l) continue;
			can_r += r[j] >= min_r;
		}		
		
		if (can_r) 
			MULT(ans, can_r);
	}	
		
	FOR(i, 1, n + 1)
	{
		if (i == s[max_l]) continue;		
		int can_l = 0, can_r = 0, can_both = 0;
		for(auto j: id[i])
		{
			bool ok_l = l[j] <= max_l;
			bool ok_r = r[j] >= min_r;
			can_l += ok_l;
			can_r += ok_r;
			can_both += ok_l && ok_r;
		}		
		
		if (!can_l && !can_r) continue;
		if (!can_l) 
		{
			MULT(ans, can_r);
			continue;
		}
		
		if (!can_r)
		{
			MULT(ans, can_l);
			continue;
		}
		
		if (Res[max_l][i] == 1)
		{
			if (can_both) MULT(ans, 2);
			continue;
		}
		
		int tut = mult(can_l, can_r);
		SUB(tut, can_both);
		MULT(ans, tut);		
	}
	
	return ans;
}

int cmp(int x, int y)
{
	return h[x] < h[y];
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	cin >> n >> m;
	FOR(i, 1, n + 1) cin >> s[i];	
	FOR(i, 0, m)
	{
		cin >> f[i] >> h[i];
		id[f[i]].PB(i);
		
		l[i] = n + 2;
		r[i] = 0;
		
		int vje = 0;
		FOR(j, 1, n + 1)
		{
			vje += s[j] == f[i];
			if (vje == h[i])
			{
				l[i] = j;
				break;
			}
		}
		
		vje = 0;
		RFOR(j, n + 1, 1)
		{
			vje += s[j] == f[i];
			if (vje == h[i])
			{
				r[i] = j;
				break;
			}
		}
	}	
	
	FOR(i, 1, n + 1) sort(ALL(id[i]), cmp);
	
	int mx = 0;
	FOR(i, 0, n + 1)
	{
		G[i] = get(i);
		setmax(mx, G[i]);
	}	
	
	cout << mx << ' ';
	
	if (mx == 0)
	{
		cout << 1 << endl;
		return 0;
	}
	
	int ans = 0;
	FOR(i, 0, n + 1) if (G[i] == mx)
	{
		KEK[i] = solve(i);
		ADD(ans, KEK[i]);
	}
	
	cout << ans << endl;
	
	//FOR(i, 0, n + 1) cout << G[i] << ' ' << KEK[i] << endl;
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}