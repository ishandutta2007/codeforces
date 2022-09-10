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

const double PI = acos(-1.0);
const LL INF = 1e9;
const LL LINF = 1e18;
const int MAX = 2e5 + 47;

int n;
int a[MAX];
PII cost[MAX];

int near_sq(int x)
{
	int sq = sqrt(x);
	int res = x - sq * sq;
	sq++;
	res = min(res, abs(x - sq * sq));
	return res;
}

bool is(int x)
{
	return near_sq(x) == 0;
}

int cmp(PII x, PII y)
{
	if (x.X < y.X)
		return 1;
	if (x.X > y.X)
		return 0;

	return x.Y > y.Y;
}

int cmp2(PII x, PII y)
{
	return x < y;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

	cin >> n;
	FOR(i, 0, n)
		cin >> a[i];

	FOR(i, 0, n)
	{
		cost[i].X = near_sq(a[i]);
		if (cost[i].X > 0)
			cost[i].Y = 0;
		else
			cost[i].Y += 1 + (a[i] == 0);
		//cout << cost[i].X << "  " << cost[i].Y << endl;
	}

	LL ans = 0;
	LL curr = 0;
	sort(cost, cost + n, cmp);
	FOR(i, 0, n / 2)
		curr += cost[i].X;
	FOR(i, n / 2, n)
		curr += cost[i].Y;

	ans = curr;
	curr = 0;

	sort(cost, cost + n, cmp2);
	FOR(i, 0, n / 2)
		curr += cost[i].X;
	FOR(i, n / 2, n)
		curr += cost[i].Y;

	ans = min(ans, curr);


	cout << ans << endl;
	return 0;
}