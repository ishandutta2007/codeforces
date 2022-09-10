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
#define debug(a) cout << #a << " = " << a << endl;

const double PI = acos(-1.0);
const LL INF = 1e9 + 47;
const LL LINF = INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 100 + 7;
int n;
int a[N];
bool was[N];
int dp[N][N][N][2];

void onowy(int& x, int y)
{
	x = min(x, y);
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> n;
	FOR(i, 1, n + 1)
	{
		cin >> a[i];
		was[a[i]] = true;
		if (a[i] == 0) a[i] = -1;
		else a[i] &= 1;
	}
	
	int cnt_even = 0, cnt_odd = 0;
	FOR(i, 1, n + 1) if (!was[i])
	{
		if (i & 1) cnt_odd++;
		else cnt_even++;
	}
	
	FOR(i, 0, N) FOR(j, 0, N) FOR(k, 0, N) FOR(x, 0, 2) dp[i][j][k][x] = INF;
	
	if (a[1] == -1)
	{
		dp[1][0][1][0] = 0;
		dp[1][1][0][1] = 0;
	}
	else
	{
		dp[1][0][0][a[1]] = 0;
	}
	
	FOR(i, 2, n + 1)
	{
		FOR(odd, 0, cnt_odd + 1)
		{
			FOR(even, 0, cnt_even + 1)
			{
				FOR(k, 0, 2)
				{
					if (a[i] != -1)
					{
						onowy(dp[i][odd][even][a[i]], 
							  dp[i - 1][odd][even][k] + (k != a[i]));
						continue;
					}
					
					onowy(dp[i][odd + 1][even][1],
						  dp[i - 1][odd][even][k] + (k == 0));
					onowy(dp[i][odd][even + 1][0],
						  dp[i - 1][odd][even][k] + (k == 1));
				}	
			}
		}
	}
	
	int ans = INF;
	
	if (a[n] == -1)
		ans = min(dp[n][cnt_odd][cnt_even][0], dp[n][cnt_odd][cnt_even][1]);
	else
		ans = dp[n][cnt_odd][cnt_even][a[n]];
	
	assert(ans < INF);
	cout << ans << endl;
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}