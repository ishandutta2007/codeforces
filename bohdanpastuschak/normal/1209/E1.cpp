#include <bits/stdc++.h>
using namespace std;
 
typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<double> VD;
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

int n, m;

int dist(int x, int y)
{
	return min(abs(x - y), n - abs(x - y));
}

bool ok(PII a, PII b, PII c, PII d)
{
	map<int, VI> mp;
	mp[a.Y].PB(a.X);
	mp[b.Y].PB(b.X);
	mp[c.Y].PB(c.X);
	mp[d.Y].PB(d.X);
		
	int r1 = -1, r2 = -1;
	
	for(auto i: mp)
	{
		if (SZ(i.Y) != 2)
			return 1;
			
		if (r1 == -1)
			r1 = dist(i.Y[0], i.Y[1]);
		else
			r2 = dist(i.Y[0], i.Y[1]);
	}
	
	if (r1 == 1 && r2 == 2)
		return 0;
	if (r2 == 1 && r1 == 2)
		return 0;
	
	return 1;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("In.txt", "w", stdout);

	int t;
	cin >> t;
	while(t--)
	{
		cin >> n >> m;
		vector<pair<int, PII>> a(n * m);
		FOR(i, 0, n)
			FOR(j, 0, m)
			{
				cin >> a[i * m + j].X;
				a[i * m + j].Y = {i , j};
			}

		sort(ALL(a));
		reverse(ALL(a));
		int ans = 0;
		FOR(i, 0, n)
			ans += a[i].X;
		
		if (n == 4)
		{
			ans = 0;
			if (SZ(a) > 12)
				a.resize(12);
			
			FOR(i, 0, SZ(a))
				FOR(j, i + 1, SZ(a))
					FOR(k, j + 1, SZ(a))
						FOR(l, k + 1, SZ(a))
							if (ok(a[i].Y, a[j].Y, a[k].Y, a[l].Y))
								ans = max(ans, a[i].X + a[j].X + a[k].X + a[l].X);
								
		}
	
		cout << ans << endl;
	}

	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}