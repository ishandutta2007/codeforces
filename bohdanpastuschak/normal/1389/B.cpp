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

int solve(){
	int n, k, z;
	cin >> n >> k >> z;
	vector<int> a(n);
	FOR(i, 0, n) cin >> a[i];
	vector<vector<vector<int>>> dp(n + 1, vector<VI>(z + 1, vector<int>(2, -INF)));
	dp[0][0][0] = a[0];
	FOR(cnt, 0, k){
		FOR(pravo, max(0, cnt - z), cnt + 1) FOR(lst, 0, 2){
			int livo = cnt - pravo;
			 if (dp[cnt][livo][lst] != -INF){
				int now = pravo - livo;
				if (now + 1 < n) setmax(dp[cnt + 1][livo][0], dp[cnt][livo][lst] + a[now + 1]);
				if (now - 1 >= 0 && livo < z && !lst) setmax(dp[cnt + 1][livo + 1][1], dp[cnt][livo][lst] + a[now - 1]);
			 }
		}
	}

	int ans = 0;
	FOR(j, 0, z + 1) FOR(t, 0, 2) setmax(ans, dp[k][j][t]);
	return ans;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int tc; cin >> tc;
	while(tc--){
		//solve();
		cout << solve() << '\n';
	}
	
    cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}