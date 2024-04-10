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

const int N = 1 << 9;
int n, m;
int a[N];
int pos[N];
int dp[N][N];
int MN[N][N];

inline int f(int l, int r)
{
	if (l > r)
		return 1;
	
	if (dp[l][r] != -1)
		return dp[l][r];
	
	int mn = MN[l][r];	
	int p = pos[mn];
	
	int lft = 0, rgt = 0;
	
	FOR(L, l, p + 1)
		lft = add(lft, mult(f(l, L - 1), f(L, p - 1)));
	FOR(R, p, r + 1)
		rgt = add(rgt, mult(f(p + 1, R), f(R + 1, r)));
	
	return dp[l][r] = mult(lft, rgt);
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("In.txt", "w", stdout);
	
	cin >> n >> m;
	FOR(i, 0, n)
	{
		cin >> a[i];
		pos[a[i]] = i;
	}
	
	FOR(i, 0, n)
	{
		MN[i][i] = a[i];
		FOR(j, i + 1, n)
			MN[i][j] = min(MN[i][j - 1], a[j]);
	}
	
	FILL(dp, -1);
	cout << f(0, n - 1) << endl;
			
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}