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

int n, m;
int a[1 << 17];

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

	cin >> n >> m;
	FOR(i, 0, n)
		cin >> a[i];
	
	int g = a[0] - 1;
	FOR(i, 1, n)
		g = __gcd(g, a[i] - 1);

	VI v;
	n = g;
	for(int i = 1; i * i <= n; ++i)
		if (n % i == 0)
		{
			v.PB(i);
			if (i * i < n)
				v.PB(n / i);
		}
	
	sort(ALL(v));
	LL ans = 0;
	
	for(auto i: v)
	{
		if (i % 2 == 0)
			continue;
		
		int l = 1;
		for(; l * (LL) i <= m; l += l)
			ans += m - l * i;
	}
	
	cout << ans << endl;
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}