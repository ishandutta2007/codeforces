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

const int N = 1 << 10;
int a[N][N];

bool check(int n)
{
	int tut = -1;
	FOR(i, 0, n)
	{
		int xr = 0;
		FOR(j, 0, n)
			xr ^= a[i][j];
		
		if (tut == -1)
			tut = xr;
			
		if (xr != tut)
			return 0;
	}
	
	FOR(i, 0, n)
	{
		int xr = 0;
		FOR(j, 0, n)
			xr ^= a[j][i];
			
		if (xr != tut)
			return 0;
	}
	
	return 1;
}

void go(int n)
{
	FOR(i, 0, n)
	{
		FOR(j, 0, n)
			cout << a[i][j] << ' ';
		cout << endl;
	}	
}

void solve(int n)
{
	vector<int> v;
	for(int i = 0; i < n * n; i += 2)
		v.PB(i);
	for(int i = 1; i < n * n; i += 2)
		v.PB(i);
	
	int ptr = 0;
	FOR(i, 0, n)
		FOR(j, 0, n)
			a[i][j] = v[ptr++];
	
	assert(check(n));
	go(n);
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("In.txt", "w", stdout);
	
	int n;
	cin >> n;
	solve(n);
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}