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

inline int mult(int x, int y, int p)
{
	return x * (LL) y % p;
}

const int N = 1 << 19;
int a[N];
map<int, int> mp;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("In.txt", "w", stdout);

	int n, p, k;
	cin >> n >> p >> k;
	FOR(i, 0, n)
	{
		cin >> a[i];
		int val = mult(a[i], a[i], p);
		val = mult(val, val, p);
		int v = mult(a[i], k, p);
		val -= v;
		val += p;
		val %= p;
		mp[val]++;
	}

	LL ans = 0;

	for(auto i: mp)
		ans += i.Y * (LL) (i.Y - 1) / 2;

	cout << ans << endl;

	return 0;
}