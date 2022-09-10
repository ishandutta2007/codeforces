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
const LL INF = 2e9 + 47;
const LL LINF = INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1 << 18;
int n, m, k;
int ta, tb;
int a[N];
int b[N];

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("In.txt", "w", stdout);
	
	cin >> n >> m >> ta >> tb >> k;
	FOR(i, 0, n)
		cin >> a[i];
	FOR(i, 0, m)
		cin >> b[i];
	
	if (k >= n || k >= m)
	{
		cout << -1;
		return 0;
	}
	
	int best = 0;
	
	FOR(i, 0, k + 1)
	{		
		int she = k - i;
		int bude_v_b = a[i] + ta;
		int first = lower_bound(b, b + m, bude_v_b) - b;
		if (first + she >= m)
			best = INF;
		else
			best = max(best, b[first + she] + tb);
	}
	
	if (best == INF)
		best = -1;
	cout << best << endl;
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}