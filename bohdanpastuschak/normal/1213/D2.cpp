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
int n, k;
int a[N];
VI d[N];

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("In.txt", "w", stdout);
	
	cin >> n >> k;
	FOR(i, 0, n)
		cin >> a[i];
	
	FOR(i, 0, n)
		d[a[i]].PB(0);
	
	RFOR(i, N, 0)
	{
		int l = i * 2;
		int r = i * 2 + 1;
		if (l < N)
		{
			for(auto j: d[l])
				d[i].PB(j + 1);
		}
		
		if (r < N)
		{
			for(auto j: d[r])
				d[i].PB(j + 1);
		}
		
		sort(ALL(d[i]));
	}
	
	LL ans = LINF;
	FOR(i, 0, N)
	{
		if ((int)d[i].size() < k)
			continue;
		LL curr = 0;
		FOR(j, 0, k)
			curr += d[i][j];
		ans = min(ans, curr);
	}
	
	cout << ans << endl;
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}