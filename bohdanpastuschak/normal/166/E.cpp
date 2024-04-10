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

const int N = 10000000 + 47;
const int mod = 1e9 + 7;
int f[N][2];

inline int add(int x, int y)
{
	if (x + y < mod)
		return x + y;
	return x + y - mod;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);
	
	f[0][0] = 1;
	FOR(i, 1, N)
	{
		f[i][0] = add(f[i - 1][1], add(f[i - 1][1], f[i - 1][1]));
		f[i][1] = add(f[i - 1][0], add(f[i - 1][1], f[i - 1][1]));
	}
	
	int n;
	cin >> n;
	cout << f[n][0] << endl;
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}