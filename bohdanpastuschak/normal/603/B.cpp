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

const int MAX = 1 << 20;
VI g[MAX];
int p, k;

inline int mult(int x, int y)
{
	return x * (LL) y % p;
}

char U[MAX];

void dfs(int v)
{
	U[v] = 1;
	for(auto i: g[v])
		if (!U[i])
			dfs(i);
}

const int MOD = 1e9 + 7;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);
	
	cin >> p >> k;
	FOR(i, 1, p)
		g[i].PB(mult(i, k));
	
	int ans = 1;
	FOR(i, 1, p)
	{
		if (!U[i])
			dfs(i), ans = ans * (LL) p % MOD;
	}
	
	if (k == 1)
		ans = ans * (LL) p % MOD;
	
	cout << ans << endl;
	cerr << "Time elapsed : " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}