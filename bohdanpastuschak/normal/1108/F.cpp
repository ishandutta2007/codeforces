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
int n, m;
int p[MAX];
int sz[MAX];
pair<int, PII> e[MAX];

int find(int i)
{
	if (p[i] == i)
		return i;
	return p[i] = find(p[i]);
}

void unite(int i, int j)
{
	i = find(i);
	j = find(j);
	if (i == j)
		return;
	if (sz[i] < sz[j])
		swap(i, j);
	sz[i] += sz[j];
	p[j] = i;
}

int go(vector<PII>& vec)
{
	vector<PII> ch;
	for(auto i: vec)
		if (find(i.X) != find(i.Y))
			ch.PB(i);

	if (SZ(ch) < 2)
	{
		for(auto i: ch)
			unite(i.X, i.Y);
		
		return 0;
	}
	
	int res = 0;
	for(auto& i: ch)
	{
		if (find(i.X) != find(i.Y))
			unite(i.X, i.Y);
		else
			res++;
	}
	
	return res;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

	cin >> n >> m;
	if (m == n - 1)
	{
		cout << 0 << endl;
		return 0;
	}
	
	int u, v, w;
	FOR(i, 0, m)
	{
		cin >> u >> v >> w;
		e[i] = MP(w, MP(u, v));
	}

	sort(e, e + m);	
	FOR(i, 1, n + 1)
		p[i] = i, sz[i] = 1;
	int ans = 0;
	vector<PII> vec;
	vec.PB(e[0].Y);
	FOR(i, 1, m)
	{
		if (e[i].X != e[i - 1].X)
		{
			ans += go(vec);
			vec.clear();
		}
		
		vec.PB(e[i].Y);
	}

	ans += go(vec);
	cout << ans << endl;
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}