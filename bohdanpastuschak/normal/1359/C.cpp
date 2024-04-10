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

LL solve(){
	int h, c, t;
	cin >> h >> c >> t;
	if (t == h) return 1;
	if (2 * t <= h + c) return 2;
	//t > (h + c) / 2
	
	LL l = 0, r = INF, m;
	while(r - l > 1){
		m = (l + r) >> 1;
		LL val = m * (LL) (h + c) + h;
		if (val >= t * (LL) (2 * m + 1)){
			l = m;
		}else{
			r = m;
		}
	}
	
	m = l;
	LL val = 0;
	val += (2 * m + 3) * (m * (h + c) + h);
	val += (2 * m + 1) * ((m + 1) * (h + c) + h);
	if (val <= 2 * t * (2 * m + 1) * (2 * m + 3))
		return 2 * m + 1;
	else
		return 2 * m + 3;	
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int t = 1;
	cin >> t;
	while(t--){
		//solve();
		cout << solve() << endl;
	}
	
    cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}