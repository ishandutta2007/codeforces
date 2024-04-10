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
const LL INF = 1e9 + 47;
const LL LINF = INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1 << 17;
int n;
int a[N];

int mult(int x, int y)
{
	return x * (LL) y % 1000000007;
}

int power(int x, LL y)
{
	int r = 1;
	while(y)
	{
		if (y & 1)	
			r = mult(r, x);
		x = mult(x, x);
		y >>= 1;
	}
	
	return r;
}

int vh(int x)
{
	map<int, int> cnt;
	FOR(i, 0, n)
		cnt[a[n - 1] - a[i]]++;
	
	for (int i = 0; ; i++)
	{
		if (cnt[i] % x)
			return i;
		cnt[i + 1] += cnt[i] / x;
	}	
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("In.txt", "w", stdout);

	int x;
	cin >> n >> x;
	FOR(i, 0, n)
		cin >> a[i];
	
	LL A = 0;
	FOR(i, 0, n - 1)
		A += a[i];
	int ans = power(x, A);
	ans = mult(ans, power(x, min(a[n - 1], vh(x))));	
	cout << ans << endl;
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}