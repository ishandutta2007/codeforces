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

const int N = 1 << 18;
int n, m, k;
VI g[N];
int special[N];
int d1[N];
int dn[N];

void bfs(int* d, int v)
{
	d[v] = 0;
	queue<int> q;
	q.push(v);
	while(!q.empty())
	{
		v = q.front();
		q.pop();
		
		for(auto i: g[v]) if (d[i] == -1)
		{
			d[i] = d[v] + 1;
			q.push(i);
		}
	}	
}

int cmp(int x, int y)
{
	return dn[x] < dn[y];
}

inline int cost(int x, int y)
{
	int res = d1[x] + dn[x];
	setmin(res, d1[y] + dn[y]);
	setmin(res, d1[x] + dn[y] + 1);
	setmin(res, d1[y] + dn[x] + 1);	
	return res;
}

int mx_suf[N];

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	cin >> n >> m >> k;
	FOR(i, 0, k) cin >> special[i];
	
	FOR(i, 0, m)
	{
		int u, v;
		cin >> u >> v;
		g[u].PB(v);
		g[v].PB(u);
	}
	
	FILL(d1, -1);
	FILL(dn, -1);
	bfs(d1, 1);
	bfs(dn, n);
	
	int ans = 1;	
	
	sort(special, special + k, cmp);
	mx_suf[k - 1] = special[k - 1];
	RFOR(i, k - 1, 0)
	{
		mx_suf[i] = mx_suf[i + 1];
		if (d1[mx_suf[i]] < d1[special[i]])
			mx_suf[i] = special[i];
	}
	
	FOR(i, 0, k - 1)
		setmax(ans, cost(special[i], mx_suf[i + 1]));
		
	setmin(ans, d1[n]);	
	cout << ans << endl;	
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}