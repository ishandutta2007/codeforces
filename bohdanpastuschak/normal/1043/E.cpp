#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC target("sse4")

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

const int MAX = 3e5 + 7;
int n, m;
VI g[MAX];
PII a[MAX];
LL ans[MAX];

int get(int x, int y)
{
	return min(a[x].X + a[y].Y, a[x].Y + a[y].X);
}

pair<PII, int> s[MAX];

int cmp(pair<PII, int> x, pair<PII, int> y)
{
	return x.X.X - x.X.Y < y.X.X - y.X.Y;
}

LL sumx[MAX];
LL sumy[MAX];

LL sumax(int x, int y)
{
	if (x > y)
		return 0;
	LL res = sumx[y];
	if (x)
		res -= sumx[x - 1];
	return res;
}

LL sumay(int x, int y)
{
	if (x > y)
		return 0;
	LL res = sumy[y];
	if (x)
		res -= sumy[x - 1];
	return res;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

	cin >> n >> m;
	FOR(i, 0, n)
		cin >> a[i].X >> a[i].Y;
	
	int u, v;
	FOR(i, 0, m)
	{
		cin >> u >> v;
		--u; --v;
		g[u].PB(v);
		g[v].PB(u);
	}
	
	FOR(i, 0, n)
		s[i] = MP(a[i], i);
	
	sort(s, s + n, cmp);

	sumx[0] = s[0].X.X;
	sumy[0] = s[0].X.Y;
	FOR(i, 1, n)
	{
		sumx[i] = sumx[i - 1] + s[i].X.X;
		sumy[i] = sumy[i - 1] + s[i].X.Y;
	}

	FOR(i, 0, n)	
	{
		ans[s[i].Y] += s[i].X.Y * (LL) i + s[i].X.X * (LL) (n - i - 1);
		ans[s[i].Y] += sumay(i + 1, n - 1);
		ans[s[i].Y] += sumax(0, i - 1);
	}
	
	FOR(i, 0, n)
		for(auto j: g[i])
			ans[i] -= get(i, j);
	
	FOR(i, 0, n)
		cout << ans[i] << " ";
	cout << endl;
	cerr << "Time elapsed : " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}