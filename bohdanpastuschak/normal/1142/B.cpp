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
const LL INF = 1e9;
const LL LINF = INF * INF;

const int LOG = 18;
const int MAX = 1 << LOG;
int n, m, q;
int p[MAX];
int a[MAX];
VI v[MAX];
int kinec[MAX];
int id[MAX];
int t[MAX << 1];
int go[MAX];
int dp[MAX][LOG];

void build (int v, int tl, int tr) {
	if (tl == tr)
		t[v] = kinec[tl];
	else {
		int tm = (tl + tr) / 2;
		build (v*2, tl, tm);
		build (v*2+1, tm+1, tr);
		t[v] = min(t[v*2],t[v*2+1]);
	}
}

int min (int v, int tl, int tr, int l, int r) {
	if (l > r)
		return INF;
	if (l == tl && r == tr)
		return t[v];
	int tm = (tl + tr) / 2;
	return min( min(v*2, tl, tm, l, min(r,tm))
		, min(v*2+1, tm+1, tr, max(l,tm+1), r));
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

	cin >> n >> m >> q;
	FOR(i, 0, n)
	{
		cin >> p[i];
		id[p[i]] = i;
	}
	
	FOR(i, 0, m)
	{
		cin >> a[i];
		v[a[i]].PB(i);
	}
	
	FOR(i, 1, n + 1)
		v[i].PB(m);
	
	if (n == 1)
	{
		FOR(i, 0, q)
			cout << 1;
		return 0;
	}
	
	FOR(i, 0, m)
	{
		int tut = id[a[i]];
		int nast = p[(tut + 1) % n];
		
		go[i] = *lower_bound(ALL(v[nast]), i);
	}
	
	FOR(i, 0, LOG)
		dp[m][i] = m;
	
	RFOR(i, m, 0)
	{
		dp[i][0] = go[i];
		FOR(j, 1, LOG)
			dp[i][j] = dp[dp[i][j - 1]][j - 1];
	}	
	
	FOR(i, 0, m)
	{
		int treba = n - 1, zara = i;
		RFOR(j, LOG, 0)
		{
			if (treba >= (1 << j))
			{
				zara = dp[zara][j];
				treba -= 1 << j;
			}
		}
		
		kinec[i] = zara;
	}
	
	int l, r;
	build(1, 0, m - 1);
	while(q--)
	{
		cin >> l >> r;
		--l; --r;
		int best = min(1, 0, m - 1, l, r);
		if (best > r)
			cout << 0;
		else
			cout << 1;
	}		

	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}