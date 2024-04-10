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

const int N = 1 << 17;
int n;
int a[N];

void solve(int l)
{
	if (l >= n - 1) return;	
	int id = l;
	FOR(i, l + 1, n)
		if (a[i] < a[id]) id = i;
	
	RFOR(i, id, l) swap(a[i], a[i + 1]);
	
	solve(max(l + 1, id));
}

void solve()
{
	cin >> n;
	FOR(i, 0, n) cin >> a[i];
	
	solve(0);
	
	FOR(i, 0, n)
	{
		if (i) cout << ' ';
		cout << a[i];
	}
	
	cout << endl;
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