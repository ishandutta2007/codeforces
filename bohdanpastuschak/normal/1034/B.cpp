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

int dx[] = {0, 1, 2, 3, 2, 1, 0, -1, -2, -3, -2, -1};
int dy[] = {3, 2, 1, 0, -1, -2, -3, -2, -1, 0, 1, 2};
LL n, m;

bool ok(int x, int y)
{
	return x >= 0 && x < n && y >= 0 && y < m;
}

int odyn()
{
	int ans = 0;
	int rem = m % 6;
	ans = 6 * (m / 6);
	if (rem == 4)
		ans += 2;
	if (rem == 5)
		ans += 4;
	
	return ans;
}

const int MAX = 25;
vector<PII> g[MAX][MAX];
char used[MAX][MAX];
PII mt[MAX][MAX];

bool kuhn(int x, int y)
{
	if (used[x][y])
		return 0;
	
	used[x][y] = 1;
	FOR(i, 0, SZ(g[x][y]))
	{
		PII to = g[x][y][i];
		if (mt[to.X][to.Y] == MP(-1, -1))
		{
			mt[to.X][to.Y] = MP(x, y);
			return 1;
		}
	}
	
	FOR(i, 0, SZ(g[x][y]))
	{
		PII to = g[x][y][i];
		if (kuhn(mt[to.X][to.Y].X, mt[to.X][to.Y].Y))
		{
			mt[to.X][to.Y] = MP(x, y);
			return 1;
		}
	}
	
	return 0;
}

void CLEAR()
{
	FOR(i,0 , MAX)
		FOR(j,0, MAX)
			mt[i][j] = MP(-1, -1), used[i][j] = 0, g[i][j].clear();
}

int brute()
{
	CLEAR();
	FOR(i, 0, n)
		FOR(j, 0, m)
		{	
			if ((i + j) & 1)
				continue;
			
			FOR(k, 0, 12)		
			{
				int x = i + dx[k];
				int y = j + dy[k];
				if (!ok(x, y))
					continue;
				
				g[i][j].PB(MP(x, y));
			}
		}
	
	int ans = 0;
	FOR(i, 0, n)
		FOR(j, 0, m)
		{
			if ((i + j) & 1)
				continue;
			
			FOR(x, 0, n)
				FOR(y, 0, m)	
					used[x][y] = 0;
			
			ans += kuhn(i, j);
		}
	
	ans *= 2;
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

	cin >> n >> m;
	
	if (n > m)
		swap(n, m);
	
	if (n == 1)
	{
		cout << odyn() << endl;
		return 0;
	}
	
	if (m < MAX)
	{
		cout << brute() << endl;
		return 0;
	}
	
	LL ans = n * m;
	if (ans & 1)
		--ans;
	cout << ans << endl;
	
	cerr << "Time elapsed : " <<  clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}