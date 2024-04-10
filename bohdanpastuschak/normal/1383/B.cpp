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

string W = "WIN";
string L = "LOSE";
string D = "DRAW";

string solve(vector<int>& a, int n){
	int xr = 0;
	for(auto i: a) xr ^= i;
	if (xr == 0) return D;
	if (n % 2 == 0) return W;
	int bt = -1;
	RFOR(i, 30, 0) if (xr & (1 << i)){
		bt = i;
		break;
	}

	int cnt = 0;
	FOR(i, 0, n) cnt += (a[i] & (1 << bt)) > 0;
	if (cnt % 4 == 1) return W;
	else return L;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> a(n);
		FOR(i, 0, n) cin >> a[i];
		cout << solve(a, n) << '\n';
	}
		
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}