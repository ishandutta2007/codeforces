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

const int N = 1 << 19;
int n;
VI g[N];
int e[N];
int d[N];
int p[N];
bool ban[N];

void bfs(vector<int> vec)
{
	FILL(d, -1);

	queue<int> q;
	for(auto v: vec) d[v] = 0, q.push(v);

	while(!q.empty())
	{
		int v = q.front();
		q.pop();
		
		for(auto I: g[v])
		{
			int i = e[I];
			if (d[i] == -1)
			{
				p[i] = v;
				d[i] = d[v] + 1;
				q.push(i);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	cin >> n;
	FOR(i, 0, n - 1)
	{
		int u, v;
		cin >> u >> v;
		e[i << 1] = v;
		e[(i << 1) | 1] = u;
		g[u].PB(i << 1);
		g[v].PB((i << 1) | 1);
	}
	
	bfs({1});
	int mx = 1;
	FOR(i, 1, n + 1) if (d[i] > d[mx]) mx = i;
	bfs({mx});
	int smx = 1;
	FOR(i, 1, n + 1) if (d[i] > d[smx]) smx = i;
	
	
	int ans = 0;
	int now = smx;
	VI path;
	while(now != mx)
	{
		ans++;
		path.PB(now);
		now = p[now];
	}
	
	path.PB(mx);
	
	bfs(path);
	int tr = -1;
	FOR(i, 1, n + 1) if (i != mx && i != smx && (tr == -1 || d[i] > d[tr])) tr = i;
	ans += d[tr];	
	cout << ans << endl;
	cout << mx << ' ' << smx << ' ' << tr << endl;
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}