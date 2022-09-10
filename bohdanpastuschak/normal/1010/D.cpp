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

const double PI = acos(-1.0);
const LL INF = 1e9;
const LL LINF = 1e18;

const int MAX = 1 << 20;

int n;
string type[MAX];
VI syny[MAX];
bool znach[MAX];

bool pochatkovi[MAX];

bool dfs(int v)
{
	//cout << "dfs: " << v << " " << type[v] <<  endl;
	if (type[v] == "IN")
	{
		//cout << v << " " << znach[v] << endl;
		return pochatkovi[v] = znach[v];	
	}
	
	if (type[v] == "NOT")
		return pochatkovi[v] = !dfs(syny[v][0]);
	
	if (type[v] == "OR")
		return pochatkovi[v] = dfs(syny[v][0]) | dfs(syny[v][1]);
	
	if (type[v] == "XOR")
		return pochatkovi[v] = dfs(syny[v][0]) ^ dfs(syny[v][1]);
		
	if (type[v] == "AND")
		return pochatkovi[v] = dfs(syny[v][0]) & dfs(syny[v][1]);
	
	assert(0);
}

bool can[MAX];

void solve(int v)
{
	//cout << v << " ";
	if (type[v] == "IN")
	{
		can[v] = 1;
		return;
	}
	
	if (type[v] == "OR")
	{
		if (pochatkovi[syny[v][0]] && pochatkovi[syny[v][1]])
			return;
		
		if (pochatkovi[syny[v][0]] == 0 && pochatkovi[syny[v][1]] == 0)
		{
			solve(syny[v][0]);
			solve(syny[v][1]);
			return;
		}
		
		if (pochatkovi[syny[v][0]])
			solve(syny[v][0]);
		
		if (pochatkovi[syny[v][1]])
			solve(syny[v][1]);
		
		return;
	}
	
	if (type[v] == "NOT")
	{
		solve(syny[v][0]);
		return;
	}
	
	if (type[v] == "AND")
	{
		if (pochatkovi[syny[v][0]] == 0 && pochatkovi[syny[v][1]] == 0)
			return;
		
		if (pochatkovi[syny[v][0]] == 1 && pochatkovi[syny[v][1]] == 1)
		{
			solve(syny[v][1]);
			solve(syny[v][0]);
			return;
		}
		
		if (pochatkovi[syny[v][1]] == 0)
			solve(syny[v][1]);
		
		if (pochatkovi[syny[v][0]] == 0)
			solve(syny[v][0]);
				
		return;
	}
	
	if (type[v] == "XOR")
	{
		solve(syny[v][1]);
		solve(syny[v][0]);
		return;
	}
	
	assert(0);
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);
	
	cin >> n;
	int u, v;
	FOR(i, 0, n)
	{
		cin >> type[i];
		if (type[i] == "IN" || type[i] == "NOT")
			cin >> u;
		else
			cin >> u >> v;
		
		if (type[i] == "IN")
			 znach[i] = u;
		else
		{
			if (type[i] == "NOT")
			{
				syny[i].PB(u - 1);
				
			}
			else
			{
				syny[i].PB(u - 1);
				syny[i].PB(v - 1);
				
			}
		}
	}
	
	dfs(0);
//	FOR(i, 0, n)
//		cout << pochatkovi[i] << endl;
//	
	solve(0);
	
	
	//cout << pochatkovi[0] << endl;
	FOR(i, 0, n)
	{
		if (type[i] != "IN")
			continue;
		
		//cout << can[i];
		cout << (can[i] ^ pochatkovi[0]);
	}
	
	cout << endl;
	cerr << "Time elapsed: " << clock() / (double) CLOCKS_PER_SEC << endl;
	return 0;
}