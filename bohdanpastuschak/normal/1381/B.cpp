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

const int N = 1 << 12;
int n;
int p[N];

bool solve(){
	vector<int> a;
	int r = n * 2;
	while(r > 0){
		int mx = -1, pos = -1;
		FOR(i, 0, r) if (p[i] > mx){
			mx = p[i];
			pos = i;
		}

		a.PB(r - pos);
		r = pos;
	}

	const int m = SZ(a);
	
	vector<vector<char>> dp(m + 1, vector<char>(n + 1, 0));
	dp[0][0] = 1;
	FOR(i, 0, m){
		const int A = a[i];
		dp[i + 1] = dp[i];
		FOR(j, 0, n + 1) if (dp[i][j] && j + A <= n){
			dp[i + 1][j + A] = true;
		}
	}

	return dp[m][n];
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	int C = 0;
	while(t--){
		cin >> n;
		FOR(i, 0, n + n) cin >> p[i];
		int curr = solve();
		C += curr;
		cout << (curr ? "YES\n" : "NO\n");		
	}

	debug(C)
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}