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
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)((a).size())
#define FILL(a, value) memset(a, value, sizeof(a))
#define debug(a) cerr << #a << " = " << a << endl;

const double PI = acos(-1.0);
const LL INF = 1e9 + 47;
const LL LINF = INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1 << 7;
int n, m;
int a[N][N];
int u[N];

vector<int> solve(int x)
{
	vector<PII> vec;
	FOR(i, 0, m) vec.PB({a[i][x] - a[i][n - 1], i});
	sort(ALL(vec));
	reverse(ALL(vec));
	vector<int> res;
	int sum = 0;
	for(auto i: vec)
	{
		if (sum + i.X < 0) break;
		sum += i.X;
		res.PB(i.Y);
	}
	
	return res;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	cin >> n >> m;
	FOR(i, 0, m) FOR(j, 0, n) cin >> a[i][j];	
	vector<int> ans;
	
	FOR(i, 0, n - 1)
	{
		VI tut = solve(i);
		if (SZ(tut) > SZ(ans)) ans = tut;
	}
	
	VI res;
	for(auto i: ans) u[i] = 1;
	FOR(i, 0, m) if (!u[i]) res.PB(i);	
	cout << SZ(res) << endl;
	FOR(i, 0, SZ(res))
	{
		if (i) cout << ' ';
		cout << res[i] + 1;
	}
	cout << endl;
	
	cerr << "Time elapsed: " << clock() / (double) CLOCKS_PER_SEC << endl;
	return 0;
}