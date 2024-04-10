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

const int N = 1 << 17;
int n, m;
int b[N];
int g[N];

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

	cin >> n >> m;
	FOR(i, 0, n)
		cin >> b[i];
	FOR(i, 0, m)
		cin >> g[i];
	
	sort(b, b + n);
	sort(g, g + m);
	
	if (g[0] < b[n - 1])
	{
		cout << -1 << endl;
		return 0;
	}
	
	if (n == 1)
	{
		LL ans = 0;
		FOR(i, 0, m)
			ans += g[i];
		if (g[0] != b[0])
			ans = -1;
		cout << ans << endl;
		return 0;
	}
	
	LL ans = 0;
	LL sum_b = 0;
	FOR(i, 0, n)
		sum_b += b[i];
	
	ans = sum_b * m;
	FOR(i, 1, m)
		ans += g[i] - b[n - 1];
		
	if (g[0] > b[n - 1])
		ans += g[0] - b[n - 2];
		
	cout << ans << endl;
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}