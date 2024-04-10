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
#define debug(a) cerr << #a << " = " << a << endl;

const double PI = acos(-1.0);
const LL INF = 1e9;
const LL LINF = INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1 << 17;
int n;
int a[N];

LL get(VI& c)
{
	int md = c[SZ(c) / 2];
	LL ans = 0;
	FOR(i, 0, SZ(c)) ans += abs(c[i] - md);
	return ans;
}

LL solve(int x)
{
	LL ans = 0;
	VI curr;
	FOR(i, 0, n)
	{
		if (a[i] == 0) continue;
		curr.PB(i);
		if (SZ(curr) == x)
		{
			ans += get(curr);
			curr.clear();
		}
	}	
	
	assert(SZ(curr) == 0);	
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

	cin >> n;
	FOR(i, 0, n) cin >> a[i];
	int s = 0;
	FOR(i, 0, n) s += a[i];
	
	if (s == 1)
	{
		cout << -1;
		return 0;
	}
	
	LL ans = LINF;
	FOR(i, 2, s + 1) if (s % i == 0)
		ans = min(ans, solve(i));
		
	if (ans == LINF) ans = -1;
	cout << ans << endl;
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}