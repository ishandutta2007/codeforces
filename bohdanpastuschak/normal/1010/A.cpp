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

const int MAX = 1e3 + 47;

int n, m;
int a[MAX];
int b[MAX];

bool ok(double x)
{
	double m0 = m + x;
	
	m0 = m0 - m0 / a[0];
	FOR(i, 1, n)
	{
		m0 = m0 - m0 / b[i];
		m0 = m0 - m0 / a[i];
	}
	
	m0 = m0 - m0 / b[0];
	return m0 >= m;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);
	
	cin >> n >> m;
	FOR(i, 0, n)
		cin >> a[i];
	FOR(i, 0, n)
		cin >> b[i];
	
	FOR(i, 0, n)
		if (a[i] == 1 || b[i] == 1)
		{
			cout << -1 << endl;
			return 0;
		}
	
	
	double L = 0, R = INF, M;
	
	FOR(iter, 0, 100)
	{
		M = (L + R) / 2.0;
		if (ok(M))
			R = M;
		else
			L = M;
	}
	
	double ans = (L + R) / 2.0;
	cout << fixed << setprecision(10) << ans << endl;
	
	cerr << "Time elapsed: " << clock() / (double) CLOCKS_PER_SEC << endl;
	return 0;	
}