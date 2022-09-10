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

const int N = 1 << 18;
int n, m, k, q;
VI a[N];
int b[N];
LL dp[N][2];
int kin[N][2];
VI ye;

int dist(int col1, int col2)
{
	int ans = INF;
	auto it = lower_bound(b, b + q, col1) - b;
	if (it != q)
		ans = min(ans, b[it]-col1 + abs(b[it] - col2));
	if (it)
		ans = min(ans, col1 - b[it - 1] + abs(b[it - 1] - col2));
	
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("In.txt", "w", stdout);
	
	cin >> n >> m >> k >> q;
	int last_row = -1;
	
	FILL(kin, -1);
	a[1].PB(1);
	FOR(i, 0, k)
	{
		int x, y;
		cin >> x >> y;
		a[x].PB(y);
		last_row = max(last_row, x);
	}
	
	FOR(i, 1, n + 1)
	{
		sort(ALL(a[i]));
		if (SZ(a[i]) == 0)
			continue;
		
		ye.PB(i);	
		kin[i][0] = a[i][0];
		kin[i][1] = a[i].back();
	}
	
	FOR(i, 0, q)
		cin >> b[i];
	sort(b, b + q);
	
	FOR(i, 1, n + 1)
		FOR(j, 0, 2)
			dp[i][j] = LINF;
		
	dp[1][1] = kin[1][1] - kin[1][0];
	
	int i = 1;
	while(i < last_row)
	{
		int nxt = *upper_bound(ALL(ye), i);
		int len = nxt - i;
		
		FOR(j, 0, 2)
			FOR(l, 0, 2)
			{
				LL tut = dp[i][j] + len;
				tut += dist(kin[i][j], kin[nxt][l ^ 1]);				
				tut += abs(kin[nxt][l ^ 1] - kin[nxt][l]);
				dp[nxt][l] = min(dp[nxt][l], tut);
			}			
		
		i = nxt;
	}
	
	LL ans = dp[last_row][1];
	if (last_row > 1)
		ans = min(ans, dp[last_row][0]);
		
	cout << ans << endl;
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}