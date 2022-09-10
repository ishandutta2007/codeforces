#include <bits/stdc++.h>
using namespace std;
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,avx")

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
 
template<typename T> void setmax(T& x, T y) {x = max(x, y);}
template<typename T> void setmin(T& x, T y) {x = min(x, y);}
 
const double PI = acos(-1.0);
const int INF = 1e9 + 47;
const LL LINF = 1LL * INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAX = 107;

vector<int> g[MAX];
int sz[MAX];
int dp[MAX][MAX][2], dp1[MAX][MAX][2];
pair<int, int> par[MAX][MAX][2];

void dfsDP(int v)
{
	FOR(i, 0, 2)
	{
		dp1[v][0][i] = 0;
		dp1[v][1][i] = 0;
	}
	sz[v] = 1;
	int u = v;
	for(int to: g[v])
	{
		dfsDP(to);
		FOR(k, 1, sz[v] + sz[to] + 1)
			FOR(l, 0, 2)
				dp1[to][k][l] = INT_MAX;
		FOR(k, 1, sz[v] + 1)
			FOR(lyshU, 0, 2)
				FOR(j, 0, sz[to] + 1)
					FOR(lyshTo, 0, 2)
						if(!lyshU || !lyshTo)
						{
							int val = dp1[u][k][lyshU] + dp[to][j][lyshTo] + (j == 0 ? 0 : 1);
							if(val < dp1[to][k + j][lyshU ^ lyshTo])
							{
								dp1[to][k + j][lyshU ^ lyshTo] = val;
								par[to][k + j][lyshU ^ lyshTo] = {j, lyshTo};
							}
					}
		sz[v] += sz[to];
		u = to;
	}
	FOR(k, 0, sz[v] + 1)
		FOR(l, 0, 2)
			dp[v][k][l] = dp1[u][k][l] + (k && !l);
}

void dfsRestore(int v, int k, int lysh)
{
	cout << v + 1 << " ";
	vector<pair<int, int> > go;
	int lyshSynok = -1, lyshCnt = 0;
	RFOR(i, SZ(g[v]), 0)
	{
		auto [cntI, lyshI] = par[g[v][i]][k][lysh];
		if(cntI)
		{
			if(lyshI)
			{
				lyshSynok = g[v][i];
				lyshCnt = cntI;
				lysh = false;
			}
			else
				go.push_back({g[v][i], cntI});
			k -= cntI;
		}
	}
	for(auto [to, cnt]: go)
	{
		dfsRestore(to, cnt, false);
		cout << v + 1 << " ";
	}
	if(lyshSynok != -1)
		dfsRestore(lyshSynok, lyshCnt, true);
}


int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		int k, n;
		cin >> n >> k;
		FOR(i, 1, n)
		{
			int p;
			cin >> p;
			p--;
			g[p].push_back(i);
		}
		dfsDP(0); 
		cout << dp[0][k][1] << "\n";
		dfsRestore(0, k, true);
		cout << "\n";
		FOR(i, 0, n)
			g[i].clear();
		/*cerr << "---" << "\n";
		FOR(i, 0, n)
			FOR(j, 0, k + 1)
				FOR(l, 0, 2)
					cerr << i << " " << j << " " << l << " " << dp[i][j][l] << " " << dp1[i][j][l] << endl;*/
	}	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}