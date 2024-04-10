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

const double PI = acos(-1.0);
const LL INF = 1e9;
const LL LINF = 1e18;

int gcd(int x, int y)
{
	if (!y)
		return x;
	return gcd(y, x % y);
}

const int MAX = 1e5 + 47;

int n, k;
int a[MAX];
bool ok[MAX];

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

	cin >> n >> k;
	FOR(i, 0, n)
		cin >> a[i], a[i] %= k;
	
	VI ans;
	int g = k;
	FOR(i, 0, n)
		g = gcd(g, a[i]);
	
	if (g == 0)
		ok[0] = 1;
	else
	{
		FOR(i, 0, k)
			if (i % g == 0)
				ans.PB(i);
	}
	
	FOR(i, 0, k)
		if (ok[i])
			ans.PB(i);
	
	cout << SZ(ans) << endl;
	FOR(i, 0, SZ(ans))
		cout << ans[i] << " "; 
	
	cerr << "Time elapsed: " << clock() / (double) CLOCKS_PER_SEC << endl;
	return 0;
}