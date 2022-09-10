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
const LL INF = 1e9;
const LL LINF = INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1 << 10;
int n, m, d;
int c[N];
int ans[N];
int l[N];

void bad()
{
	cout << "NO" << endl;
	exit(0);
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);
	
	cin >> n >> m >> d;
	FOR(i, 0, m) cin >> c[i];
	
	int curr = 0;
	FOR(i, 0, m)
	{
		l[i] = curr + d;
		curr = l[i] + c[i] - 1;
	}
	
	if (curr + d <= n) bad();
	l[m] = n + 1;
	RFOR(i, m, 0) l[i] = min(l[i], l[i + 1] - c[i]);
	if (l[0] < 0) bad();
	
	FOR(i, 0, m) FOR(j, l[i], l[i] + c[i]) ans[j] = i + 1;
	cout << "YES" << endl;		
	FOR(i, 1, n + 1)
		cout << ans[i] << ' ';
	cout << endl;
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}