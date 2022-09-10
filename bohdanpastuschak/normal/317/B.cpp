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

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

const int MAGIC = 70;

int dp[MAGIC * 2][MAGIC * 2][2];

bool ok(int x, int y)
{
	return x >= 0 && x < MAGIC * 2 && y >= 0 && y < MAGIC * 2;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("In.txt", "w", stdout);
	
	int n;
	cin >> n;
	
	dp[MAGIC][MAGIC][0] = n;
	int curr = 0;
	
	while(1)
	{
		bool ye = 0;
		curr ^= 1;
		FOR(i, 0, MAGIC * 2)
			FOR(j, 0, MAGIC * 2)
			{
				dp[i][j][curr] = dp[i][j][curr ^ 1] % 4;
				FOR(k, 0, 4)
				{
					int I = i + dx[k];
					int J = j + dy[k];
					if (!ok(I, J))
						continue;
						
					dp[i][j][curr] += dp[I][J][curr ^ 1] / 4;
				}
				
				ye |= (dp[i][j][curr] > dp[i][j][curr ^ 1] % 4);
			}
		
		if (!ye)
			break;
	}
	
	int t;
	cin >> t;
	while(t--)
	{
		int x, y;
		cin >> x >> y;
		x += MAGIC;
		y += MAGIC;
		
		if (!ok(x, y))
			cout << "0\n";
		else
			cout << dp[x][y][curr] << '\n';
	}
	
				
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}