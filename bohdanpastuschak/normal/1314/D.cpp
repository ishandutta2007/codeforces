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

const int K = 14;
const int N = 88;
int n, k;
int a[N][N];
int color[N];
int dp[N][K];
int iter = 0;

inline bool CL()
{
//	iter++;
//	if ((iter & 255)) return false;
	return clock() / (double) CLOCKS_PER_SEC >= 0.3;
}

int main()
{	
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	cin >> n >> k;
	FOR(i, 0, n) FOR(j, 0, n) cin >> a[i][j];
	
	int ans = INF;
	
	while(!CL())
	{
		FOR(i, 0, n) color[i] = rng() & 1;
		FOR(i, 0, n) FOR(j, 0, k + 1) dp[i][j] = INF;
		dp[0][0] = 0;
		
		FOR(i, 0, k) FOR(v, 0, n) FOR(u, 0, n) if (color[u] != color[v])
			setmin(dp[u][i + 1], dp[v][i] + a[v][u]);
		
		setmin(ans, dp[0][k]); 
	}
	
	cout << ans << endl;	
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}