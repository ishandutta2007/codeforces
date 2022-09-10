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
const LL INF = 1e9 + 47;
const LL LINF = INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define endl '\n'

const int LOG = 20;
const int N = 1 << LOG;
int n, m;
PII a[N];
int to[N];
int kin[N];
int dp[N][LOG];
	
inline int solve(int x, int y, int from)
{
	if (x >= y)
		return 0;
	
	RFOR(i, from, 0)
		if (dp[x][i] < y)
			return (1 << i) + solve(dp[x][i], y, i);
	return 1;
}	

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("In.txt", "w", stdout);
	
	cin >> n >> m;
	FOR(i, 0, n)
	{
		cin >> a[i].X >> a[i].Y;
		kin[a[i].X] = max(kin[a[i].X], a[i].Y);
	}
	
	int mx = 0;
	FOR(i, 0, N)
	{
		mx = max(mx, kin[i]);
		to[i] = mx;
	}	
	
	FOR(i, 0, N) 
		dp[i][0] = to[i];
	
	FOR(j, 1, LOG)
		FOR(i, 0, N)
			dp[i][j] = dp[dp[i][j - 1]][j - 1];
	
	while(m--)
	{
		int x, y;
		cin >> x >> y;
		
		int ans = 0;
		if (dp[x][LOG - 1] < y)
			ans = -1;
		else
			ans = solve(x, y, LOG);
	
		cout << ans << endl;
	}	

	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}