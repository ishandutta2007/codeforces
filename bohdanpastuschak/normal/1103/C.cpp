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

const int MAX = 1 << 18;
int n, m, k;
VI g[MAX];
int depth[MAX];
int batya[MAX];
VI synky[MAX];
VI lifty[MAX];
char used[MAX];

void dfs(int v, int p = 0)
{
	used[v] = 1;
	batya[v] = p;
	for(auto i: g[v])
	{
		if (i == p)
			continue;
		if (used[i])
			lifty[v].PB(i);
		else
		{
			depth[i] = depth[v] + 1;
			dfs(i, v);
			synky[v].PB(i);
		}
	}
}

int cmp(int x, int y)
{
	return depth[x] > depth[y];
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);
	
	cin >> n >> m >> k;
	int u, v;
	while(m--)
	{
		cin >> u >> v;
		g[u].PB(v);
		g[v].PB(u);
	}

	depth[1] = 1;
	dfs(1);
	FOR(i, 1, n + 1)
		if (depth[i] >= (n + k - 1) / k)
		{
			cout << "PATH" << endl;
			VI ans;
			while(i)
			{
				ans.PB(i);
				i = batya[i];
			}
			
			cout << SZ(ans) << endl;
			for(auto i: ans)
				cout << i << ' ';
			cout << endl;
			return 0;
		}
	
	cout << "CYCLES" << endl;
	int cnt = 0;
	for(int i = 1; i <= n && cnt < k; ++i)
	{
		if (SZ(synky[i]))
			continue;
		
		cnt++;
		sort(ALL(lifty[i]), cmp);
		u = lifty[i][0];
		v = lifty[i][1];
		VI ans;
		int lenu = -depth[u] + depth[i] + 1;
		int lenv = -depth[v] + depth[i] + 1;
				
		if (lenu % 3)
		{
			int x = i;
			while(x != u)
			{
				ans.PB(x);
				x = batya[x];
			}
			ans.PB(u);
		}
		else
		{
			if (lenv % 3)
			{
				int x = i;
				while(x != v)
				{
					ans.PB(x);
					x = batya[x];
				}
				ans.PB(v);
			}
			else
			{
				ans.PB(i);
				int x = u;
				while(x != v)
				{
					ans.PB(x);
					x = batya[x];
				}
				ans.PB(v);
			}
		}
		
		cout << SZ(ans) << endl;
		for(auto i: ans)
			cout << i << ' ';
		cout << endl;
	}
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}