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

template<typename T> void setmax(T& x, T y) {x = max(x, y);}
template<typename T> void setmin(T& x, T y) {x = min(x, y);}

const double PI = acos(-1.0);
const LL INF = 1e9 + 47;
const LL LINF = INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		vector<PII> a(n);
		FOR(i, 0, n) cin >> a[i].X >> a[i].Y;
		sort(ALL(a));
		bool ok = 1;
		FOR(i, 1, n) if (a[i].Y < a[i - 1].Y) ok = 0;
		if (!ok)
		{
			cout << "NO\n";
			continue;
		}
		
		cout << "YES\n";
		int x = 0, y = 0;
		string ans;
		FOR(i, 0, n)
		{
			int xx = a[i].X, yy = a[i].Y;
			while(x < xx) ans += 'R', x++;
			while(y < yy) ans += 'U', y++;
			assert(x == xx && y == yy);
		}
		
		cout << ans << '\n';
	}
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}