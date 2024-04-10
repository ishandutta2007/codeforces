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

const int N = 1 << 18;
int n, m, k;
VI g[N], gr[N];
int path[N];
int d[N];

void bfs(int v)
{
	FILL(d, -1);
	d[v] = 0;
	queue<int> q;
	q.push(v);
	while(!q.empty())
	{
		v = q.front();
		q.pop();
		
		for(auto i: gr[v]) if (d[i] == -1)
		{
			d[i] = d[v] + 1;
			q.push(i);
		}
	}
}

int find_min()
{
	int ans = 0;
	int curr = path[0];
	FOR(i, 1, k)
	{
		int nxt = path[i];
		if (d[curr] < d[nxt] + 1) ans++;
		curr = nxt;
	}
		
	return ans;
}

int find_max()
{
	int ans = 0;
	
	int curr = path[0];
	FOR(i, 1, k)
	{
		int nxt = path[i];
	
		//    nxt,  ans += 0
		
		bool je = false;
		for(auto to: g[curr])
			if (d[to] == d[curr] - 1 && to != nxt)
				je = true;
		
		ans += je;
		curr = nxt;
	}
	
	return ans;
}

int main()
{	
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);	
	
	cin >> n >> m;
	while(m--)
	{
		int u, v;
		cin >> u >> v;
		g[u].PB(v);
		gr[v].PB(u);
	}
	
	cin >> k;
	FOR(i, 0, k) cin >> path[i];
	bfs(path[k - 1]);
	
	int mn = find_min();
	int mx = find_max();
	cout << mn << ' ' << mx << endl;
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}