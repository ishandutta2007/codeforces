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

const int N = 1 << 17;
int n;
LL a[N];
set<int> g[N];
int ans = INF;

void add(int x, int y)
{
	g[x].insert(y);
	g[y].insert(x);
}

char bulo[N];
int d[N];

int bfs(int v, int t)
{
	set<int> buv;
	buv.insert(v);
	
	d[v] = 0;
	queue<int> q;
	q.push(v);
	
	while(!q.empty())
	{
		int x = q.front();
		q.pop();
		
		for(auto i: g[x])
			if (!buv.count(i))
			{
				buv.insert(i);
				d[i] = d[x] + 1;
				q.push(i);
			}
	}
	
	if (!buv.count(t))
		return INF;
		
	return d[t] + 1;
}

int solve(int v, int i)
{
	g[v].erase(i);
	g[i].erase(v);
	int tut = bfs(v, i);	
	add(i, v);
	return tut;
}

int go(int v)
{
	int tut = INF;
	VI vec(ALL(g[v]));
	for(auto i: vec)
		tut = min(tut, solve(v, i));
	return tut;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("In.txt", "w", stdout);
	
	cin >> n;
	FOR(i, 0, n)
		cin >> a[i];
	
	RFOR(i, 60, 0)
	{
		VI tut;
		FOR(j, 0, n)
			if (a[j] & (1LL << i))
				tut.PB(j);
		
		if (SZ(tut) >= 3)
		{
			cout << 3;
			return 0;
		}
		
		for(auto j: tut)
			bulo[j] = 1;
			
		FOR(j, 0, SZ(tut))
			FOR(k, j + 1, SZ(tut))
				add(tut[j], tut[k]);
	}
	
	FOR(i, 0, n)
		if (bulo[i])
			ans = min(ans, go(i));
	
	if (ans == INF)
		ans = -1;
		
	cout << ans << endl;
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}