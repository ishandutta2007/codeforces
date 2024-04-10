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
const LL INF = 1e9 + 47;
const LL LINF = INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int LCM = 2520;
int dp[125][LCM * 3][3];
VI arr[125];

int f(int id, int k, int last)
{
	if (k <= 0) return 0;
	if (dp[id][k][last] != -1) return dp[id][k][last];
	int& res = dp[id][k][last];
	res = 0;
	set<int> S;
	
	FOR(nxt, 0, 3)
	{
		if (last && last == nxt) continue;
		S.insert(f(id, k - arr[id][nxt], nxt));
	}
	
	while(S.count(res)) res++;
	return res;
}

int Id;

inline int ComputeGrundy(LL x, int y)
{
	if (x < 2 * LCM) return f(Id, x, y);
	return f(Id, (x % (2 * LCM)) + LCM, y);
}

int n;
LL b[1 << 19];
map<VI, int> Mapa;

void solve()
{
	cin >> n;
	vector<int> x(3);
	FOR(i, 0, 3) cin >> x[i];
	Id = Mapa[x];
	int xr = 0;
	FOR(i, 0, n)
	{
		cin >> b[i];
		xr ^= ComputeGrundy(b[i], 0);
	}
	
	int ans = 0;
	FOR(i, 0, n) 
	{
		xr ^= ComputeGrundy(b[i], 0);
		FOR(last, 0, 3)
		{
			int tut = ComputeGrundy(b[i] - arr[Id][last], last);
			ans += xr == tut;
		}
		
		xr ^= ComputeGrundy(b[i], 0);
	}
	
	cout << ans << endl;	
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int ptr = 0;
	FOR(x, 1, 6) FOR(y, 1, 6) FOR(z, 1, 6)
		Mapa[{x, y, z}] = ptr, arr[ptr++] = {x, y, z};
	
	FILL(dp, -1);
	
	int t = 1;
	cin >> t;
	while(t--)
		solve();
		
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}