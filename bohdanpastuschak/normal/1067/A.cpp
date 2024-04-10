#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC target("sse4")

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

const int mod = 998244353;

inline int add(int x, int y)
{
	if (x + y < mod)
		return x + y;
	return x + y - mod;
}

const int M = 1e5 + 7;
const int N = 200 + 1;
int n;
int a[M];
int dp[M][N][2];
int pref[N][2];

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("sum.in", "r", stdin);
	//freopen("sum.out", "w", stdout);
	//freopen("In.txt", "r", stdin);

	cin >> n;
	FOR(i, 0, n)
		cin >> a[i];

	if (a[0] == -1)
		FOR(i, 1, N)
		dp[0][i][0] = 1;
	else
		dp[0][a[0]][0] = 1;
	
	FOR(i, 1, n)
	{
		FOR(j, 1, N)
			FOR(k, 0, 2)
				pref[j][k] = add(pref[j - 1][k], dp[i - 1][j][k]);
		
		
		FOR(j, 1, N)
		{
			dp[i][j][0] = add(pref[j - 1][0], pref[j - 1][1]);
			dp[i][j][1] = add(dp[i - 1][j][0], dp[i - 1][j][1]);
			dp[i][j][1] = add(dp[i][j][1], add(pref[N - 1][1], mod - pref[j][1]));
		}
		
		if(a[i] != -1)
		{
			FOR(j, 1, N)
			{
				if(j == a[i])
					continue;
				
				dp[i][j][0] = dp[i][j][1] = 0;
			}
		}
	}
	
	int ans = 0;
	FOR(i, 1, N)
		ans = add(ans, dp[n - 1][i][1]);
	cout << ans << endl;	
	cerr << "Time elapsed : " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}