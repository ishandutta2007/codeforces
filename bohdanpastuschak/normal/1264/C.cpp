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
};

using namespace IntModulo;
const int N = 1 << 18;
int n, q;
int a[N];
int s[N];
int invA[N];
int inv[N];
bool on[N];

inline int get_product(int l, int r)
{
	if (l > r) return 1;
	return mult(s[r], inv[l - 1]);
}

int t[N << 1];

int merge(int l, int r, int tl, int tr)
{
	return add(r, mult(l, get_product(tl, tr)));
}

inline void build(int v, int tl, int tr)
{
	if (tl == tr)
	{
		t[v] = invA[tl];
		return;
	}
	
	int tm = (tl + tr) >> 1;
	build(v * 2, tl, tm);
	build(v * 2 + 1, tm + 1, tr);
	t[v] = merge(t[v * 2], t[v * 2 + 1], tm + 1, tr);
}

inline int get(int v, int tl, int tr, int l, int r)
{
	if (l > r || tl > tr) return 0;
	if (l == tl && r == tr) return t[v];
	int tm = (tl + tr) >> 1;
	return merge(get(v * 2, tl, tm, l, min(r, tm)), 
				 get(v * 2 + 1, tm + 1, tr, max(tm + 1, l), r), 
				tm + 1, r);
}

inline int calculate(int l, int r)
{
	int ans = get(1, 1, n, l, r);
	//cout << l << ' ' << r << ' ' << ans << endl;
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	cin >> n >> q;
	int inv100 = inverse(100);
	FOR(i, 1, n + 1) 
	{
		cin >> a[i];
		a[i] = mult(a[i], inv100);
		invA[i] = inverse(a[i]);
	}
	
	s[0] = 1;
	FOR(i, 1, n + 1) s[i] = mult(invA[i], s[i - 1]);
	FOR(i, 0, n + 1) inv[i] = inverse(s[i]);
	build(1, 1, n);	
		
	set<int> all;
	all.insert(1);
	all.insert(n + 1);
	on[1] = on[n + 1] = 1;
	
	int ans = calculate(1, n);	
	//debug(ans);
	while(q--)
	{
		int u;
		cin >> u;
		if (on[u])
		{
			all.erase(u);
			auto it = all.upper_bound(u);
			int R = *it;
			--it;
			int L = *it;
			
			ans = sub(ans, calculate(L, u - 1));
			ans = sub(ans, calculate(u, R - 1));
			ans = add(ans, calculate(L, R - 1));
		}
		else
		{
			auto it = all.upper_bound(u);
			int R = *it;
			--it;
			int L = *it;
			
			ans = add(ans, calculate(L, u - 1));
			ans = add(ans, calculate(u, R - 1));
			ans = sub(ans, calculate(L, R - 1));
			
			all.insert(u);
		}
		
		on[u] ^= 1;
		cout << ans << '\n';
	}	
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}