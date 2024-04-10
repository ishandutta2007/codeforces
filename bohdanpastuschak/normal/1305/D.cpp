#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")

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
const LL INF = 1e9 + 47;
const LL LINF = INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1 << 10;
int n;
VI g[N];
bool used[N];

int lca(int u, int v)
{
	cout << "? " << u << ' ' << v << endl;
	fflush(stdout);
	cin >> u;
	assert(u > 0);
	return u;
}

void answer(int x)
{
	cout << "! " << x << endl;
	fflush(stdout);
	exit(0);
}

int main()
{	
	cin >> n;
	FOR(i, 0, n - 1)
	{
		int u, v;
		cin >> u >> v;
		g[u].PB(v);
		g[v].PB(u);
	}
	
	int je = n;
	while(je > 1)
	{
		int x = -1, y = -1;
		FOR(i, 1, n + 1) if (SZ(g[i]) == 1)
		{
			if (x == -1) x = i;
			else y = i;
		}
		
		assert(y > 0);
		int res = lca(x, y);
		if (res == x) answer(x);
		if (res == y) answer(y);
		
		g[x].clear();
		g[y].clear();
		used[x] = used[y] = 1;
		je -= 2;
		
		FOR(i, 1, n + 1) 
		{
			FOR(J, 0, SZ(g[i]))
			{
				if (g[i][J] == x || g[i][J] == y)
				{
					swap(g[i][J], g[i].back());
					g[i].pop_back();
					J--;
				}
			}
		}		
	}
		
	if (je == 1)
	{
		FOR(i, 1, n + 1) if (!used[i])
			answer(i);
	}	
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}