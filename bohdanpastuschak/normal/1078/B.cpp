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

const int MAX = 107;
const int M = MAX * MAX;
int n;
int cnt[MAX];
int S = 0;
char dp[MAX][M];

int ask(int x)
{
	int ans = 0;
	FOR(k, 1, cnt[x] + 1)
		if (dp[k][k * x] == 1 || dp[n - k][S - k * x] == 1)
			ans = k;
	return ans;
}

inline void go(char& x, char y)
{
	x += y;
	x = min(x, (char)2);
}

char DP[MAX][M][2];

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

	cin >> n;
	int x;
	FOR(i, 0, n)
	{
		cin >> x;
		S += x;
		cnt[x]++;
	}
	
	int rzn = 0;
	FOR(i, 0, MAX)
		rzn += cnt[i] > 0;
	
	if (rzn < 3)
	{
		cout << n << endl;
		return 0;
	}
	 
	DP[0][0][0] = 1;
	int curr = 0;
	FOR(i, 0, MAX - 1)
	{
		FOR(j, 0, MAX)
			FOR(k, 0, M)
				DP[j][k][curr ^ 1] = 0;

		FOR(j, 0, MAX)
			FOR(k, 0, M)
			{
				if (!DP[j][k][curr])
					continue;
				
				FOR(c, 0, cnt[i] + 1)
				{
					if (k + i * c >= M)
						break;
					
					go(DP[j + c][k + i * c][curr ^ 1], DP[j][k][curr]);
				}
			}
		
		curr ^= 1;
	}
	
	FOR(i, 0, MAX)
		FOR(j, 0, M)
			dp[i][j] = DP[i][j][curr];
			
	int ans = 0;
	FOR(i, 0, MAX)
		if (cnt[i])
			ans = max(ans, ask(i));
	
	cout << ans << endl;
	cerr << "Time elapsed : " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}