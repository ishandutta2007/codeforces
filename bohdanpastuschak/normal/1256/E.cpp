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
int n;
PII a[N];
int ans[N];
int res;
int dp[N];
int batya[N];
int color[N];
int naj_id[N];

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);
	
	cin >> n;
	FOR(i, 1, n + 1) cin >> a[i].X, a[i].Y = i;
	sort(a + 1, a + n + 1);
	FOR(i, 1, n + 1) dp[i] = INF;
	FOR(i, 3, n + 1)
	{
		dp[i] = a[i].X;
		batya[i] = naj_id[max(0, i - 3)];
		dp[i] += dp[batya[i]] - a[batya[i] + 1].X;
		naj_id[i] = naj_id[i - 1];
		if (dp[i] - a[i + 1].X < dp[naj_id[i]] - a[naj_id[i] + 1].X)
			naj_id[i] = i;
	}
	
	int k = 1;
	int zara = n;
	while(zara)
	{
		int kin = batya[zara];
		FOR(i, kin + 1, zara + 1)
			color[a[i].Y] = k;
			
		k++;
		zara = kin;
	}
	
	cout << dp[n] << ' ' << k - 1 << endl;
	FOR(i, 1, n + 1)
		cout << color[i] << ' ';
	cout << endl;
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}