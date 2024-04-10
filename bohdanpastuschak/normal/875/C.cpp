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

void bad()
{
	cout << "No" << endl;
	exit(0);
}

const int N = 1 << 17;
int n, m;
vector<int> a[N];
int len[N];
char cap[N];//1 - yes, 2 - no
VI must[N];
char used[N];

void postav(int x, char y)
{
	if (cap[x] == 0)
		cap[x] = y;
	if (cap[x] == y)
		return;
	bad();
}

void dfs(int v)
{
	used[v] = 1;
	for(auto i: must[v])	
		if (!used[i])
		{
			postav(i, 1);
			dfs(i);
		}
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("In.txt", "w", stdout);
	
	cin >> n >> m;
	FOR(i, 0, n)
	{
		cin >> len[i];
		a[i].resize(len[i]);
		for(auto& j: a[i])	
			cin >> j;
	}
	
	FOR(i, 0, n - 1)
	{
		int j = i + 1;
		int x = 0;
		while(x < len[i] && x < len[j] && a[i][x] == a[j][x])
			++x;
		
		if (x == len[i])
			continue;
		
		if (x == len[j])
			bad();
		
		if (a[i][x] > a[j][x])
		{
			postav(a[i][x], 1);
			postav(a[j][x], 2);
		}
		else
			must[a[j][x]].PB(a[i][x]);
	}
	
	FOR(i, 1, m + 1)
		if (used[i] == 0 && cap[i] == 1)
			dfs(i);
	
	cout << "Yes" << endl;	
	vector<int> ans;
	FOR(i, 1, m + 1)
		if (cap[i] == 1)
			ans.PB(i);
	
	cout << SZ(ans) << endl;
	for(auto i: ans)
		cout << i << ' ';
	cout << endl;
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}