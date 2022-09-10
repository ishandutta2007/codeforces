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
#define debug(a) cerr << #a << " = " << a << endl;

const double PI = acos(-1.0);
const LL INF = 1e9;
const LL LINF = INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n, k;
string s;

void solve()
{
	cin >> n >> k >> s;
	vector<PII> ans;
	
	FOR(i, 0, 2 * (k - 1))
	{
		char maje;
		if (i & 1) maje = ')';
		else maje = '(';
		
		FOR(j, i, n) if (s[j] == maje)
		{
			ans.PB({i, j});
			reverse(s.begin() + i, s.begin() + j + 1);
			break;
		}
		
		assert(s[i] == maje);
	}
	
	int vidr = (n - 2 * (k - 1)) / 2;
	int start = 2 * (k - 1);
	
	FOR(i, start, n)
	{
		char maje;
		if (i - start < vidr) maje = '(';
		else maje = ')';
		
		FOR(j, i, n) if (s[j] == maje)
		{
			ans.PB({i, j});
			reverse(s.begin() + i, s.begin() + j + 1);
			break;
		}
		
		assert(s[i] == maje);
	}	
	
	cout << SZ(ans) << endl;
	for(auto i: ans) cout << i.X + 1 << ' ' << i.Y + 1 << endl;
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