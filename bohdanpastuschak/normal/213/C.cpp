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

const int N = 300 + 7;
int n;
int a[N][N];
int dp[2*N][N][N];

void onowy(int& x, int y)
{
	x = max(x, y);
}

bool ok(int d, int i)
{
	return i >= 0 && i <= d;
}

int get(int d, int i)
{
	return a[i][d - i];
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("In.txt", "w", stdout);
	
	cin >> n;
	FOR(i, 0, n)
		FOR(j, 0, n)
			cin >> a[i][j];
	
	FOR(i, 0, 2*n)
		FOR(j, 0, n)
			FOR(k, 0, n)
				dp[i][j][k] = -INF;
	
	dp[0][0][0] = a[0][0];
	
	FOR(d, 0, 2 * n - 2)
		FOR(i, 0, d + 1)
			FOR(j, 0, d + 1)
				FOR(di, 0, 2)
					FOR(dj, 0, 2)
					{
						int I = i + di, J = j + dj;
						
						int cost = get(d + 1, I);
						if (I != J)
							cost += get(d + 1, J);
							
						onowy(dp[d + 1][I][J], dp[d][i][j] + cost);
					}
	
	cout << dp[2 * n - 2][n - 1][n - 1] << endl;
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}