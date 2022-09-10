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
#define ITER(it, a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)((a).size())
#define FILL(a, value) memset(a, value, sizeof(a))
#define debug(a) cout << #a << " = " << a << endl;

const double PI = acos(-1.0);
const LL INF = 1e9;
const LL LINF = INF * INF;

const int mod = 998244353;

inline int add(int x, int y)
{
	if (x + y < mod)
		return x + y;
	return x + y - mod;
}

inline int mult(int x, int y)
{
	return x * (LL) y % mod;
}

const int MAX = 1 << 20;
int f[MAX];
int inv[MAX];

inline int power(int x, int y)
{
	int r = 1;
	while(y)
	{
		if (y & 1)
			r = mult(r, x);
		x = mult(x, x);
		y >>= 1;
	}
	return r;
}

int t(int n, int k)
{
	int res = (n - k + 1);
	res = mult(res, f[n + 1]);
	res = mult(res, inv[n - k + 2]);
	return res;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

	f[0] = 1;
	FOR(i, 1, MAX)
		f[i] = mult(f[i - 1], i);
	
	FOR(i, 0, MAX)
		inv[i] = power(f[i], mod - 2);
	
	int n;
	cin >> n;
	int ans = 1;
	FOR(i, 1, n)	 
		ans = add(ans, mult(i, t(n - 1, i)));
	ans %= mod;
	cout << ans << endl;	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}