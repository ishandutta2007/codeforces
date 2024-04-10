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

inline int mult(int x, int y)
{
	return x * (LL) y % mod;
}

const int MAX = 1 << 17;
int n, x, y;
PII a[MAX];

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

	cin >> n >> x >> y;
	FOR(i, 0, n)
		cin >> a[i].X >> a[i].Y;
	
	x -= y;
	int ans = 0;
	vector<PII> opens;
	FOR(i, 0, n)
		opens.push_back({a[i].X, i});
	sort(ALL(opens));
	multiset<int> active;
	
	FOR(i, 0, n)
	{
		PII tut = opens[i];
		
		auto it = active.upper_bound(tut.X);
		if (it != active.begin())
		{
			--it;
			int chas = *it;
			LL cost_save = y * (LL)(tut.X - chas);
			if (cost_save < x)
			{
				ans = add(ans, cost_save);
				ans = add(ans, mult(y, a[tut.Y].Y - a[tut.Y].X + 1));
				
				active.erase(it);
				active.insert(a[tut.Y].Y + 1);
				continue;
			}
			
			while(SZ(active) && *active.begin() < tut.X)
				active.erase(active.begin());
		}
		
		active.insert(a[tut.Y].Y + 1);
		ans = add(ans, add(x, mult(a[tut.Y].Y  - a[tut.Y].X + 1, y)));
	}
	
	cout << ans << endl;
	cerr << "Time elapsed : " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}