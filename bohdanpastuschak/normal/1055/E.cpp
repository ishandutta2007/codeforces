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

const int MAX = 1500 + 7;
int n, m, s, k;
int a[MAX];
PII q[MAX];
PII nq[MAX];
int ye[MAX];
bool norma[MAX];
int dp[MAX][MAX];
int SS[MAX];
int to[MAX];

inline int get(int x, int y)
{
	if (x)
		return SS[y] - SS[x - 1];
	return SS[y];
}

bool can(int x)
{
	FOR(i, 0, n)
		ye[i] = a[i] <= x;
	
	SS[0] = ye[0];
	FOR(i, 1, n)
		SS[i] = SS[i - 1] + ye[i];
	
	FILL(to, -1);
	FOR(j, 0, s)
		FOR(i, q[j].X, q[j].Y + 1)
			to[i] = max(to[i], q[j].Y);
	
	FOR(i, 0, n + 1)
		FOR(j, 0, m + 1)
			dp[i][j] = 0;
	
	FOR(i, 0, n)
	{
		FOR(j, 0, m + 1)
		{
			dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
			if (to[i] != -1 && j != m)
				dp[to[i] + 1][j + 1] = max(dp[to[i] + 1][j + 1], dp[i][j] + get(i, to[i]));
		}		
	}
	
	int ans = 0;
	FOR(i, 0, m + 1)
		ans = max(ans, dp[n][i]);
	return ans >= k;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);
	
	cin >> n >> s >> m >> k;
	FOR(i, 0, n)
		cin >> a[i];
	
	FOR(i, 0, s)
	{
		cin >> q[i].X >> q[i].Y;
		q[i].X--;
		q[i].Y--;
	}
	
	FOR(i, 0, s)
	{
		norma[i] = 1;
		FOR(j, 0, s)
		{
			if (!norma[j] || i == j)
				continue;
			
			if (q[j].X <= q[i].X && q[j].Y >= q[i].Y)
				norma[i] = 0;
		}
	}
	
	int TS = 0;
	FOR(i, 0, s)
		if (norma[i])
			nq[TS++] = q[i];
	
	s = TS;
	FOR(i, 0, s)
		q[i] = nq[i];
	
	sort(q, q + s);
	int l = 1, r = INF, m;
	while(r - l > 1)
	{
		m = (l + r) >> 1;
		if (can(m))
			r = m;
		else
			l = m;
	}
	
	m = l;
	if (!can(l))
		m = r;
	
	if (m > 1000 * 1000 * 1000)
		m = -1;
	
	cout << m << endl;	
	cerr << "Time elapsed : " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}