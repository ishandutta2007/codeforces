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

template<typename T> void setmax(T& x, T y) {x = max(x, y);}
template<typename T> void setmin(T& x, T y) {x = min(x, y);}

const double PI = acos(-1.0);
const LL INF = 1e9 + 47;
const LL LINF = INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int A = 26;
set<int> g[A];
char used[A];
VI order;

void dfs(int v)
{
	order.PB(v);
	used[v] = 1;
	for(auto i: g[v]) if (!used[i]) dfs(i);
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int t;
	cin >> t;
	while(t--)
	{
		FOR(i, 0, A) g[i].clear();
		string s;
		cin >> s;
		if (SZ(s) == 1)
		{
			cout << "YES" << endl;
			FOR(i, 0, A) cout << (char)('a'+ i);
			cout << endl;
			continue;
		}
		
		FOR(i, 0, SZ(s) - 1)
		{
			int u = s[i] - 'a';
			int v = s[i + 1] - 'a';
			g[u].insert(v);
			g[v].insert(u);
		}
		
		bool ok = 1;
		FOR(i, 0, A) ok &= SZ(g[i]) <= 2;
		int OK = 0;
		FOR(i, 0, A) OK += SZ(g[i]) == 1;
		ok &= OK == 2;
		if (!ok)
		{
			cout << "NO" << endl;
			continue;
		}
		
		cout << "YES" << endl;
		FILL(used, 0);
		order.clear();
		FOR(i, 0, A) if (SZ(g[i]) <= 1 && !used[i])
			dfs(i);
		
		for(auto i: order) cout << (char)('a' + i);
		cout << endl;
	}
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}