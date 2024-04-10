#include <bits/stdc++.h>
using namespace std;
 
typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<double> VD;
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
char used[N];
int in_match[N];

void solve()
{
	cin >> n >> m;
	
	FOR(i, 1, n * 3 + 1)
		used[i] = 0, in_match[i] = 1;
		
	vector<int> par;
	
	FOR(i, 0, m)
	{
		int u, v;
		cin >> u >> v;
		if (!used[u] && !used[v])
		{
			used[u] = 1;
			used[v] = 1;
			in_match[u] = in_match[v] = 0;
			par.push_back(i + 1);
			continue;
		}
	}
	
	if (SZ(par) >= n)
	{
		cout << "Matching" << endl;
		FOR(i, 0, n)
			cout << par[i] << ' ';
		cout << endl;
		return;
	}
	
	int cnt = 0;
	FOR(i, 1, n * 3 + 1)
		cnt += in_match[i];
	
	if (cnt >= n)
	{
		cout << "IndSet" << endl;
		int she = n;
		FOR(i, 1, n * 3 + 1)
			if (she && in_match[i])
			{
				she--;
				cout << i << ' ';
			}
			
		cout << endl;
		return;
	}
	
	assert(0);
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("In.txt", "w", stdout);
			
	int t;
	cin >> t;
	while(t--)
		solve();
		
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}