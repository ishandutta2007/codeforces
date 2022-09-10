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

const int N = 51;
int n;
string s[N];
char dp[N][N][N][N];

void onowy(char& x, char y)
{
	x = min(x, y);
}

inline char get(int i, int j, int k, int l)
{
	if (dp[i][j][k][l] != -1)
		return dp[i][j][k][l];
		
	char res = max(k - i + 1, l - j + 1);
	FOR(x, i, k)
		onowy(res, get(i, j, x, l) + get(x + 1, j, k, l));
	FOR(y, j, l)
		onowy(res, get(i, j, k, y) + get(i, y + 1, k, l));
	return dp[i][j][k][l] = res;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("In.txt", "w", stdout);
		
	cin >> n;
	FOR(i, 0, n)
		cin >> s[i];
	
	FILL(dp, -1);
	FOR(i, 0, n)
		FOR(j, 0, n)
			if (s[i][j] == '#')
				dp[i][j][i][j] = 1;
			else
				dp[i][j][i][j] = 0;

	cout << (int)get(0, 0, n - 1, n - 1) << endl;
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}