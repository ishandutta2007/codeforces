#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC target("sse4")

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
const LL INF = 1e9 + 47;
const LL LINF = INF * INF;

int n, m;
int r[1 << 7];
int c[1 << 7];
int a[1 << 7][1 << 7];

int main()
{ 
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);
	
	cin >> n >> m;
	FOR(i, 0, n)
		cin >> r[i];
	FOR(i, 0, m)
		cin >> c[i];
	
	int x = 0;
	FOR(i, 0, n)
		x ^= r[i];
	FOR(i, 0, m)
		x ^= c[i];
	
	if (x)
	{
		cout << "NO" << endl;
		return 0;
	}
	
	FOR(i, 0, m - 1)
		a[n - 1][i] = c[i], x ^= c[i];
	
	a[n - 1][m - 1] = r[n - 1] ^ x;
	FOR(i, 0, n - 1)
		a[i][m - 1] = r[i];
	
	cout << "YES" << endl;
	FOR(i, 0, n)
	{
		FOR(j, 0, m)
		{
			if (j)
				cout << " ";
			cout << a[i][j];
		}
		
		cout << endl;
	}
	
	cerr << "Time elapsed : " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}