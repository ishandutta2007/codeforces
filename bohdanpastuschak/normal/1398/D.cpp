#include <bits/stdc++.h>
using namespace std;

//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef long double db;

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

template<typename T> void print(const T& a, ostream& out){	
	for(auto i: a) out << i << ' ';
	out << endl;
}

const double PI = acos(-1.0);
const LL INF = 1e9 + 47;
const LL LINF = INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 207;
int dp[N][N][N];

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int R, G, B;
	cin >> R >> G >> B;
	vector<int> r(R), g(G), b(B);
	FOR(i, 0, R) cin >> r[i];
	FOR(i, 0, G) cin >> g[i];
	FOR(i, 0, B) cin >> b[i];

	sort(ALL(r));
	sort(ALL(g));
	sort(ALL(b));

	FOR(i, 0, R + 1) FOR(j, 0, G + 1) FOR(k, 0, B + 1){
		setmax(dp[i + 1][j][k], dp[i][j][k]);
		setmax(dp[i][j + 1][k], dp[i][j][k]);
		setmax(dp[i][j][k + 1], dp[i][j][k]);
		setmax(dp[i + 1][j + 1][k], dp[i][j][k] + r[i] * g[j]);
		setmax(dp[i + 1][j][k + 1], dp[i][j][k] + r[i] * b[k]);
		setmax(dp[i][j + 1][k + 1], dp[i][j][k] + b[k] * g[j]);
	}

	cout << dp[R][G][B] << endl;
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}