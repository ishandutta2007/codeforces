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

const int MAX = 5000 + 7;
LL n, m;
VI g[MAX];

int dist(int i, int j)
{
	if (i <= j)
		return j - i;
	return j - i + n;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

	cin >> n >> m;
	int u, v;
	FOR(i, 0, m)
	{
		cin >> u >> v;
		--u; --v;
		g[u].PB(v);
	}
	
	FOR(i, 0, n)
	{
		sort(ALL(g[i]));
		VI vec, nv;
		FOR(j, 0, SZ(g[i]))
			if (g[i][j] < i)
				vec.PB(g[i][j]);
			else
				nv.PB(g[i][j]);
		reverse(ALL(nv));
		reverse(ALL(vec));
		for(auto j: nv)
			vec.PB(j);
		g[i] = vec;
	}
	
	FOR(i, 0, n)
	{
		int tut = 0;
		FOR(j, 0, n)
		{
			if (SZ(g[j]) == 0)
				continue;
			
			int curr = n * (SZ(g[j]) - 1) + dist(i, j) + dist(j, g[j].back());	
			tut = max(tut, curr);
		}
		
		if (i)
			cout << ' ';
		cout << tut;
	}

	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}