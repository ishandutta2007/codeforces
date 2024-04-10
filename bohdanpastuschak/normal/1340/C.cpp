#include <bits/stdc++.h>
using namespace std;

//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

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
const LL INF = 2.1e9 + 47;
const LL LINF = INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int M = 10000 + 7;
const int G = 1000 + 7;
const int S = 1.5e7;//2 * M * G;
int n, m;
int d[M];
int green, red;
int dp[M][G];
pair<PII, int> q[S];
int qt, qh;

inline bool go(int& x, int y)
{
	if (x <= y) return false;
	x = y;
	return true;
}

inline void test(int v, int bude, int vje, int len)
{
	if (bude > green) return;
	if (bude == green)
	{
		if (v == m)
		{
			setmin(dp[v][0], vje + len);
		}
		else
		{			
			if (go(dp[v][0], vje + len + red))
				q[qt++] = {{v, 0}, dp[v][0]};
		}
	}	
	else
	{
		if (go(dp[v][bude], vje + len))
			q[qt++] = {{v, bude}, dp[v][bude]};
	}
	
	if (qt == S) qt = 0;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	cin >> n >> m;
	FOR(i, 0, m) cin >> d[i];
	sort(d, d + m);
	m--;
	cin >> green >> red;
	
	FOR(i, 0, M) FOR(j, 0, G) dp[i][j] = INF;
	
	dp[0][0] = 0;
	q[qt++] = {{0, 0}, 0LL};
	while(qt != qh)
	{
		int v = q[qh].X.X, chas = q[qh].X.Y;
		if (dp[v][chas] != q[qh].Y)
		{
			qh++;
			if (qh == S) qh = 0;
			continue;
		}
		
		qh++;
		if (qh == S) qh = 0;
		
		if (v != 0) test(v - 1, chas + d[v] - d[v - 1], dp[v][chas], d[v] - d[v - 1]);
		if (v != m) test(v + 1, chas + d[v + 1] - d[v], dp[v][chas], d[v + 1] - d[v]);
	}
	
	int ans = INF;
	FOR(i, 0, green) setmin(ans, dp[m][i]);
	
	if (ans == INF) ans = -1;
	cout << ans << endl;
	
    cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}