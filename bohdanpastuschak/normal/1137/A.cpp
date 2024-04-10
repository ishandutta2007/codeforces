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

const int MAX = 1 << 10;
int n, m;
int a[MAX][MAX];
VI row[MAX];
VI col[MAX];

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

	cin >> n >> m;
	FOR(i, 0, n)
		FOR(j, 0, m)
			cin >> a[i][j];
	
	FOR(i, 0, n)
	{
		FOR(j, 0, m)
			row[i].PB(a[i][j]);
		sort(ALL(row[i]));
		row[i].resize(unique(ALL(row[i])) - row[i].begin());
	}
	
	FOR(j, 0, m)
	{
		FOR(i, 0, n)
			col[j].PB(a[i][j]);
		sort(ALL(col[j]));
		col[j].resize(unique(ALL(col[j])) - col[j].begin());
	}
	
	FOR(i, 0, n)
	{
		FOR(j, 0, m)
		{
			int tut = 1;
			int less_row = lower_bound(ALL(row[i]), a[i][j]) - row[i].begin();
			int less_column = lower_bound(ALL(col[j]), a[i][j]) - col[j].begin();
			
			int big_row = SZ(row[i]) - 1 - less_row;
			int big_column = SZ(col[j]) - 1 - less_column;
						
			tut += max(less_row, less_column);
			tut += max(big_row, big_column);
			cout << tut << ' ';
		}
		
		cout << endl;
	}
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}