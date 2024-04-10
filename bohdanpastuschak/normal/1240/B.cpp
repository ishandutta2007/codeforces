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

const int LOG = 19;
const int N = 1 << LOG;
int n;
int a[N];
int l[N];
int r[N];

void solve()
{
	cin >> n;
	FOR(i, 0, n)
		l[i] = -1, r[i] = -1;
		
	FOR(i, 0, n)
	{
		cin >> a[i];
		a[i]--;
		
		if (l[a[i]] == -1)
			l[a[i]] = i;
		r[a[i]] = i;
	}
	
	int ans = 0;
	int najdali = 0;
	int curr = 0;
	int all = 0;
	
	FOR(i, 0, n)
	{
		if (l[i] == -1)
			continue;
		
		all++;
		if (l[i] < najdali)
		{
			ans = max(ans, curr);
			curr = 1;
			najdali = r[i];
			continue;
		}
		
		najdali = max(najdali, r[i]);
		curr++;
	}
	
	ans = max(ans, curr);	
	cout << all - ans << endl;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

	int t;
	cin >> t;
	while(t--)
		solve();
		
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}