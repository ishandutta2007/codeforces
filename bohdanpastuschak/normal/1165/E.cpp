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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1 << 18;
int n;
int a[N];
int b[N];
LL v[N];

const int mod = 998244353;

void add(int& x, int y)
{
	x += y;
	if (x >= mod)
		x -= mod;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("In.txt", "w", stdout);
	
	cin >> n;
	
	FOR(i, 1, n + 1)
		cin >> a[i];
	FOR(i, 1, n + 1)
		cin >> b[i];
	
	FOR(i, 1, n + 1)	
		v[i] = a[i] * (LL) i * (n + 1 - i);
	
	sort(v + 1, v + n + 1);
	sort(b + 1, b + n + 1);
	reverse(b + 1, b + n + 1);
	int ans = 0;
	
	FOR(i, 1, n + 1)
	{
		v[i] %= mod;
		//cout << v[i] << ' ' << b[i] << endl;
		v[i] *= b[i];
		add(ans, v[i] % mod);
	}
	
	cout << ans << endl;
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}