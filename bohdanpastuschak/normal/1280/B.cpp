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

const double PI = acos(-1.0);
const LL INF = 1e9 + 47;
const LL LINF = INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n, m;
vector<string> a;

void solve()
{
	cin >> n >> m;
	a.resize(n);
	FOR(i, 0, n) cin >> a[i];
	bool ok = false;
	bool all = true;
	FOR(i, 0, n) FOR(j, 0, m) ok |= (a[i][j] == 'A'), all &= (a[i][j] == 'A');
	if (!ok)
	{
		cout << "MORTAL\n";
		return;
	}
	
	//ans <= 4;
	if (all)
	{
		cout << "0\n";
		return;
	}
	
	bool can1 = false;
	
	bool tut = true;
	FOR(i, 0, n) tut &= a[i][0] == 'A';
	if (tut) can1 = true;
	tut = true;
	FOR(i, 0, n) tut &= a[i][m - 1] == 'A';
	if (tut) can1 = true;
	
	tut = true;
	FOR(i, 0, m) tut &= a[0][i] == 'A';
	if (tut) can1 = true;
	tut = true;
	FOR(i, 0, m) tut &= a[n - 1][i] == 'A';
	if (tut) can1 = true;
	
	if (can1)
	{
		cout << "1\n";
		return;
	}
	
	bool can2 = false;
	if (a[0][0] == 'A' || a[0][m - 1] == 'A' || 
		a[n - 1][0] == 'A' || a[n - 1][m - 1] == 'A') can2 = true;
	
	FOR(i, 0, n)
	{
		tut = true;
		FOR(j, 0, m) tut &= a[i][j] == 'A';
		can2 |= tut;
	}
	
	FOR(j, 0, m)
	{
		tut = true;
		FOR(i, 0, n) tut &= a[i][j] == 'A';
		can2 |= tut;
	}
	
	if (can2)
	{
		cout << "2\n";
		return;
	}
	
	bool can3 = false;
	FOR(i, 0, n) FOR(j, 0, m) if (a[i][j] == 'A')
	{
		if (i == 0 || i == n - 1 || j == 0 || j == m - 1)
			can3 = true;
	}
	
	if (can3)
		cout << "3\n";
	else
		cout << "4\n";
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int t;
	cin >> t;
	while(t--) solve();	
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}