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

const int N = 1 << 17;
int r, n;
int t[N], x[N], y[N];
int dp[N], sdp[N];

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> r >> n;
	FOR(i, 1, n + 1) cin >> t[i] >> x[i] >> y[i];

	FOR(i, 0, n + 1) sdp[i] = dp[i] = -INF;
	dp[0] = 0;
	
	x[0] = y[0] = 1;
	t[0] = 0;

	int mx = -INF;
	FOR(i, 0, n + 1){
		setmax(mx, sdp[i]);
		setmax(dp[i], mx);
				
		int j = i + 1;
		for(; j <= n; ++j){
			const int diff = t[j] - t[i];
			
			if (diff >= abs(x[i] - x[j]) + abs(y[i] - y[j])){
				setmax(dp[j], dp[i] + 1);
			}

			if (diff > 1000){
				break;
			}			
		}

		setmax(sdp[j + 1], dp[i] + 1);
	}

	//FOR(i, 1, n + 1) cout << dp[i] << ' ';
	//cout << endl;
	
	int ans = 0;
	FOR(i, 1, n + 1) setmax(ans, dp[i]);
	cout << ans << endl;
	
    cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}