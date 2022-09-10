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

const int mod = 1e9 + 7;
inline int add(int x, int y)
{
	if (x + y < mod)
		return x + y;
	return x + y - mod;
}

const int MAX = 1 << 20;
int n;
int a[MAX];
int dp[MAX];
VI d[MAX];

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

	//n = 100000;
	cin >> n;
	FOR(i, 1, n + 1)
	{
		cin >> a[i];
		//a[i] = 1e6 + 3;
		for(int j = 1; j * j <= a[i]; ++j)
			if (a[i] % j == 0)
			{
				d[i].PB(j);
				if (a[i] != j * j)
					d[i].PB(a[i] / j);
			}
		
		sort(ALL(d[i]));
	}
	
	dp[0] = 1;
	FOR(i, 1, n + 1)
	{
		RFOR(j, SZ(d[i]), 0)
		{
			int tut = d[i][j];
			dp[tut] = add(dp[tut - 1], dp[tut]);
		}
	}
	
	int ans = 0;
	FOR(i, 1, MAX)
		ans = add(ans, dp[i]);
	cout << ans << endl;
	
	
	cerr << "Time elapsed : " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}