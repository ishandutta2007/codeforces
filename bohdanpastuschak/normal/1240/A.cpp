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

const int N = 1 << 18;
int n, x, y, a, b;
int p[N];
LL k;
LL LCM;

bool ok(int m)
{
	int obi = m / LCM;
	int A = m / a - obi;
	int B = m / b - obi;
	LL vje = 0;
	FOR(i, 0, obi)
		vje += p[i] * (x + y);
	FOR(i, obi, obi + A)
		vje += p[i] * x;
	FOR(i, obi + A, obi + A + B)
		vje += p[i] * y;
	return vje >= k;
}

void solve()
{
	cin >> n;
	FOR(i, 0, n)
		cin >> p[i], p[i] /= 100;
	
	sort(p, p + n);
	reverse(p, p + n);
	
	cin >> x >> a;
	cin >> y >> b;
	if (x < y)
	{
		swap(a, b);
		swap(x, y);
	}
	
	cin >> k;
	LCM = a * (LL) b / __gcd(a, b);
	
	int l = 0, r = n, m;
	if (!ok(n))
	{
		cout << -1 << endl;
		return;
	}
	
	while(r - l > 1)
	{
		m = (l + r) >> 1;
		if (ok(m))
			r = m;
		else
			l = m;
	}
	
	cout << r << endl;
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