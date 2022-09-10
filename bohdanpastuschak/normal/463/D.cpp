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

const int N = 1 << 10;
int a[5][N];
int n, k;
int cnt[N][N];
VI g[N];
int dp[N];

int f(int x)
{
	if (dp[x] != -1)
		return dp[x];
	int res = 0;
	for(auto i: g[x])
		res = max(res, f(i));
	return dp[x] = res + 1;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("In.txt", "w", stdout);

	cin >> n >> k;
	FOR(i, 0, k)
	{
		FOR(j, 0, n)
		{
			cin >> a[i][j];
			a[i][j]--;
		}
		FOR(j, 0, n)
			FOR(z, j + 1, n)
				cnt[a[i][j]][a[i][z]]++;
	}
	
	FOR(i, 0, n)
		FOR(j, 0, n)
			if (cnt[i][j] == k)
				g[i].PB(j);
	FILL(dp, -1);
	int ans = 0;
	FOR(i, 0, n)
		ans = max(ans, f(i));
	cout << ans << endl;
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}