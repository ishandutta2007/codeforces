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
const LL INF = 1e9 + 47;
const LL LINF = INF * INF;

const int MAX = 2e5 + 47;
int n, m;
VI r[MAX];
VI c[MAX];
char used[MAX];
char U[MAX];

void dfs(int colonka)
{
	used[colonka] = 1;
	FOR(i, 0, SZ(c[colonka]))
	{
		int to = c[colonka][i];
		if (U[to])
			continue;
		
		U[to] = 1;
		FOR(j, 0, SZ(r[to]))
		{
			int tut = r[to][j];
			if (used[tut])
				continue;
			
			dfs(tut);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);
	
	int n, m, q, x, y;
	cin >> n >> m >> q;
	while(q--)
	{
		cin >> x >> y;
		r[x].PB(y);
		c[y].PB(x);
	}
	
	int ans = 0;	
	FOR(i, 1, n + 1)
		if (SZ(r[i]) == 0)
			++ans;
	
	FOR(i, 1, m + 1)
		if (used[i] == 0)
			++ans, dfs(i);
	
	--ans;
	cout << ans << endl;
	cerr << "Time elapsed : " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}