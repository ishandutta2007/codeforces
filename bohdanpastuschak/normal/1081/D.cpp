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

const int MAX = 1 << 17;
int n, m, k;
pair<int, PII> e[MAX];
bool is[MAX];
int special[MAX];
int p[MAX];
int sz[MAX];
int ans;

int find(int v)
{
	if (p[v] == v)
		return v;
	return p[v] = find(p[v]);
}

void output()
{
	FOR(i, 0, k)
	{
		if (i)
			cout << ' ';
		cout << ans;
	}
	
	exit(0);
}

void unite(int i, int j, int w)
{
	i = find(i);
	j = find(j);
	if (i == j)
		return;
	
	if (sz[i] < sz[j])
		swap(i, j);
	
	sz[i] += sz[j];
	p[j] = i;
	if (sz[i] == k)
	{
		ans = w;
		output();
	}
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

	cin >> n >> m >> k;
	FOR(i, 0, k)
	{
		cin >> special[i];
		is[special[i]] = 1;
	}
	
	int u, v, w;
	FOR(i, 0, m)
	{
		cin >> u >> v >> w;
		e[i] = MP(w, MP(u, v));
	}
	
	sort(e, e + m);

	FOR(i, 1, n + 1)
	{
		p[i] = i;
		sz[i] = is[i];
	}
	
	FOR(i, 0, m)
	{
		u = e[i].Y.X;
		v = e[i].Y.Y;
		w = e[i].X;
		if (find(u) == find(v))
			continue;
		unite(u, v, w);
	}
	
	assert(0);
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}