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
#define debug(a) cerr << #a << " = " << a << endl;

const double PI = acos(-1.0);
const LL INF = 1e9;
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
const int N = 1 << 11;
int dp[N][N << 1];
int n, k;
int a[N];

void onowy(int x, int y, int v)
{
	dp[x][y + N] = add(dp[x][y + N], v);
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

	cin >> n >> k;
	FOR(i, 0, n) cin >> a[i];
	a[n] = a[0];
	
	dp[0][N] = 1;
	FOR(i, 0, n) FOR(j, -(i + 1), i + 2)
	{
		int bulo = dp[i][j + N];
		if (a[i] == a[i + 1])
		{
			onowy(i + 1, j, mult(k, bulo));
			continue;
		}
		
		//stavym a[i]
		onowy(i + 1, j - 1, bulo);
		//stavym a[i + 1];
		onowy(i + 1, j + 1, bulo);
		//stavym inshe
		onowy(i + 1, j, mult(k - 2, bulo));				
	}
	
	
	int ans = 0;
	FOR(i, N + 1, N << 1) ans = add(ans, dp[n][i]);
	cout << ans << endl;	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}