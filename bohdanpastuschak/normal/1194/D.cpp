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

LL get_lth(LL m, LL l)
{
	if (l == 0)
		return 0;
	
	return l / m * (3 * m + 1) + 3 * (l % m);
}

bool solve(LL n, LL k)
{
	if (k % 3)
		return (n % 3) > 0;
	
	if (n < k)
		return (n % 3) > 0;
	
	LL m = k / 3;
	LL L = 0, R = INF, M;
	while(R - L > 1)
	{
		M = (L + R) >> 1;
		LL tut = get_lth(m, M);
		if (tut < n)
			L = M;
		else
			R = M;
	}
	
	if (get_lth(m, L) == n)
		return 0;
	if (get_lth(m, R) == n)
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
		LL n, k;
		cin >> n >> k;
		if (solve(n, k))
			cout << "Alice" << endl;
		else
			cout << "Bob" << endl;
	}
	
//	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}