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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1 << 18;
int n, k;
int a[N];
int b[N];
VI g[N];
VI gr[N];
char used[N];
char colir[N];

void add(int x, int y)
{
	g[x].PB(y);
	gr[y].PB(x);
}

VI order;

void dfs1(int v)
{
	used[v] = 1;
	for(auto i: g[v])
		if (used[i] == 0)
			dfs1(i);
	order.PB(v);
}

void dfs2(int v, int cl)
{
	colir[v] = cl;
	used[v] = 1;
	for(auto i: gr[v])
		if (!used[i])
			dfs2(i, cl);
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("In.txt", "w", stdout);
	
	cin >> n >> k;
	FOR(i, 0, n)
		cin >> a[i];
	FOR(i, 0, n)
		cin >> b[i];
	
	FOR(i, 0, n - 1)
		add(a[i], a[i + 1]), add(b[i], b[i + 1]);
	
	FOR(i, 1, n + 1)
		if (!used[i])
			dfs1(i);
	
	reverse(ALL(order));
	FILL(used, 0);
	
	int comps = 0;
	int cl = 0;
	for(auto i: order)
		if (!used[i])
		{
			dfs2(i, cl);
			cl++;
			if (cl == k)
				cl--;
				
			comps++;
		}
	
	if (comps < k)
	{
		cout << "NO" << endl;
		return 0;
	}
	
	cout << "YES" << endl;
	FOR(i, 1, n + 1)
		cout << (char)('a' + colir[i]);
	cout << endl;
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}