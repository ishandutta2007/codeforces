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

const int N = 1 << 9;
int n;
int a[N];
int dp[N][N];

int f(int l, int r)
{
	if (dp[l][r] != -1)
		return dp[l][r];
	
	if (l > r)
		return 0;
	
	int res = 1 + f(l + 1, r);
	if (a[l] == a[l + 1])
		res = min(res, 1 + f(l + 2, r));
	
	FOR(k, l + 2, r + 1)
		if (a[k] == a[l])
			res = min(res, f(l + 1, k - 1) + f(k + 1, r));
	return dp[l][r] = res;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("In.txt", "w", stdout);

	cin >> n;
	FOR(i, 0, n)
		cin >> a[i];
	
	FILL(dp, -1);
	FOR(i, 0, n)
		dp[i][i] = 1;
	
	cout << f(0, n - 1) << endl;	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}