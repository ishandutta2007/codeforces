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

const int N = 1 << 17;
int n, m;
int a[N];
VI g[N];
VI gr[N];
bool s[N];
bool f[N];

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);
	
	cin >> n >> m;
	FOR(i, 0, n)
		cin >> a[i];
	
	int u, v;
	FOR(i, 0, m)
	{
		cin >> u >> v;
		--u; --v;
		g[u].PB(v);
		gr[v].PB(u);
	}
	
	queue<int> q;
	FOR(i, 0, n)
		if (a[i] == 1)
			q.push(i), s[i] = 1;
	
	while(!q.empty())
	{
		v = q.front();
		q.pop();
		
		for(auto i: g[v])
			if (s[i] == 0)
			{
				s[i] = 1;
				q.push(i);
			}
	}
	
	FOR(i, 0, n)
		if (a[i] == 2)
			q.push(i), f[i] = 1;
	
	while(!q.empty())
	{
		v = q.front();
		q.pop();
		if (a[v] == 1)
			continue;
		for(auto i: gr[v])
			if (f[i] == 0)
			{
				f[i] = 1;
				q.push(i);
			}
	}	
	
	FOR(i, 0, n)
		cout << (s[i] & f[i]) << endl;

	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}