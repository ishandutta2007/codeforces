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
#define debug(a) cerr << #a << " = " << a << endl;

const double PI = acos(-1.0);
const LL INF = 1e9 + 47;
const LL LINF = INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1 << 9;
int ans[N][N];

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	if (n == 1 && m == 1)
	{
		cout << 0;
		return 0;
	}
	
	if (m == 1)
	{
		FOR(i, 0, n) cout << i + 2 << endl;
		return 0;
	}
	
	FOR(i, 0, n)
	{
		int tut = i + 1;
		FOR(j, 0, m) ans[i][j] = (n + j + 1) * tut;
	}
	
	FOR(i, 0, n)
	{
		FOR(j, 0, m) cout << ans[i][j] << ' ';
		cout << endl;
	}
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}