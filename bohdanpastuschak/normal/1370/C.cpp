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

const int N = 1 << 10;
int dp[N];

int f(int x){
	if (dp[x] != -1) return dp[x];
	if (x == 1) return 0;
	dp[x] = 0;
	dp[x] |= !f(x - 1);
	for(int i = 3; i <= x; i += 2) if(x % i == 0)
		dp[x] |= !f(x / i);
	return dp[x];
}

bool is(int n){
	if (n == 1) return false;
	for(int i = 2; i * i <= n; i++){
		if (n % i == 0) return false;
	}
	return true;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
		
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		bool ok = true;
		if (n != 2 && __builtin_popcount(n) == 1) ok = false;
		if (n % 2 == 0 && is(n / 2)) ok = false;
		cout << (ok ? "Ashishgup\n" : "FastestFinger\n");
	}
	
    cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}