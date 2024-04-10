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

template<typename T> void setmax(T& x, T y) {x = max(x, y);}
template<typename T> void setmin(T& x, T y) {x = min(x, y);}

const double PI = acos(-1.0);
const LL INF = 1e9 + 47;
const LL LINF = INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 400 + 7;
int dp[N][N];

inline bool go(string& a, string& l, string& r)
{
	FOR(i, 0, SZ(a) + 1) FOR(j, 0, SZ(l) + 1) dp[i][j] = -INF;
	dp[0][0] = 0;
	FOR(i, 0, SZ(a)) FOR(j, 0, SZ(l) + 1)
	{
		if (dp[i][j] < 0) continue;
		if (a[i] == l[j]) setmax(dp[i + 1][j + 1], dp[i][j]);
		if (dp[i][j] < SZ(r) && a[i] == r[dp[i][j]])
			setmax(dp[i + 1][j], dp[i][j] + 1);		
		setmax(dp[i + 1][j], dp[i][j]);	
	}	
	
	return dp[SZ(a)][SZ(l)] == SZ(r);
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int t;
	cin >> t;
	while(t--)
	{
		string a, b;
		cin >> a >> b;
		
		bool ok = false;
		for(int i = 0; i < SZ(b) && !ok; ++i)
		{
			string l, r;
			FOR(j, 0, i + 1) l += b[j];
			FOR(j, i + 1, SZ(b)) r += b[j];
			ok |= go(a, l, r);
		}
		
		cout << (ok ? "YES\n" : "NO\n");
	}
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}