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

const int N = 1 << 19;
int n, m;
PII e[N];
int p[N];
int sz[N];
set<int> g[N];
vector<PII> ans;

int find(int x)
{
	if (p[x] == x)
		return x;
	return p[x] = find(p[x]);
}

bool unite(int i, int j)
{
	int x = find(i);
	int y = find(j);
	if (x == y)
		return false;
	
	ans.PB({i, j});
	if (sz[x] < sz[y])
		swap(x, y);
	sz[x] += sz[y];
	p[y] = x;
	return true;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("In.txt", "w", stdout);
	
	cin >> n >> m;
	FOR(i, 1, n + 1)
		p[i] = i, sz[i] = 1;
		
	FOR(i, 0, m)
	{
		int u, v;
		cin >> u >> v;
		if (u > v)	
			swap(u, v);
		g[u].insert(v);
		g[v].insert(u);
		e[i] = {u, v};
	}
	
	int s, t, ds, dt;
	cin >> s >> t >> ds >> dt;
	
	bool bulo = 0;
	map<int, int> comps, compt;
	FOR(i, 0, m)
		if (e[i].X != s && e[i].X != t && 
			e[i].Y != s && e[i].Y != t)
				unite(e[i].X, e[i].Y);
		else
		{
			if (e[i] == MP(s, t) || e[i] == MP(t, s))
			{
				bulo = 1;
				continue;
			}
			
			if (e[i].X != s && e[i].X != t)
				swap(e[i].X, e[i].Y);
				
			if (e[i].X == s)
				comps[find(e[i].Y)] = e[i].Y;
			else
				compt[find(e[i].Y)] = e[i].Y;
		}
	
	bool united = 0;
	set<int> kek;
	for(auto i: comps)
		if (compt.count(i.X))
		{
			kek.insert(i.X);
			if (united)
				continue;
				
			ds--;
			dt--;
			unite(s, i.Y);
			unite(t, compt[i.X]);
			united = 1;
		}
	
	for(auto i: comps)
		if (!kek.count(i.X))
			ds -= unite(s, i.Y);
	
	for(auto i: compt)
		if (!kek.count(i.X))
			dt -= unite(t, i.Y);
	
	for(auto i: kek)
		if (ds > dt)
			ds -= unite(s, comps[i]);
		else
			dt -= unite(t, compt[i]);
	
		
	if (find(s) != find(t))
	{
		assert(!united);
		assert(bulo);
		ds -= 1;
		dt -= 1;
		unite(s, t);
	}
	
	if (ds < 0 || dt < 0)
	{
		cout << "No" << endl;
		return 0;
	}
	
	cout << "Yes" << endl;
	for(auto i: ans)
		cout << i.X << ' ' << i.Y << endl;
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}