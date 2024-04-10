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
int n, m, q;
vector<int> in[N];
int sz[N];

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("In.txt", "w", stdout);
	
	cin >> n >> m;
	while(m--)
	{
		int u, v;
		cin >> u >> v;
		if (u > v)
			swap(u, v);
		
		in[u].PB(v);
		sz[v]++;
	}
	
	LL ans = 0;
	
	FOR(i, 1, n + 1)
		ans += SZ(in[i]) * (LL) sz[i];
	
	cout << ans << endl;
	
	cin >> q;
	while(q--)
	{
		int v;
		cin >> v;
		
		ans -= SZ(in[v]) * (LL) sz[v];
		
		for(auto i: in[v])
		{			
			sz[i]--;
			ans += sz[i] - SZ(in[i]);
			in[i].PB(v);
		}			
		
		sz[v] += SZ(in[v]);
		in[v].clear();
		
		cout << ans << endl;
	}
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}