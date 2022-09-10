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

const int N = 5000 + 7;
int n, k;
int a[1 << 19];
LL dp[N][N];

void onowy(LL& x, LL y)
{
	x = min(x, y);
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("In.txt", "w", stdout);

	cin >> n >> k;
	FOR(i, 0, n)
		cin >> a[i];
	
	sort(a, a + n);
	int x = k * (n / k + 1) - n;	
	FOR(i, 0, N)
		FOR(j, 0, N)
			dp[i][j] = LINF;
	
	dp[0][0] = 0;
	FOR(i, 0, x + 1)
		FOR(j, 0, k - x + 1)
		{
			if (i + j == k)
				continue;
				
			int vje = i * (n / k) + j * (n / k + 1);
			onowy(dp[i + 1][j], dp[i][j] + a[vje + n / k - 1] - a[vje]);
			onowy(dp[i][j + 1], dp[i][j] + a[vje + n / k] - a[vje]);
		}
	
	cout << dp[x][k - x] << endl;
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}