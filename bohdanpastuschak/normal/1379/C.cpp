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

#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;
		vector<pair<LL, LL>> a(m);
		FOR(i, 0, m) cin >> a[i].X >> a[i].Y;
		LL ans = 0;
		sort(ALL(a));
		vector<LL> s(m);
		s[0] = a[0].X;
		FOR(i, 1, m) s[i] = s[i - 1] + a[i].X;
		if (n <= m){
			RFOR(i, m, m - n) ans += a[i].X;
		}
		
		FOR(i, 0, m){
			if (n == 1){
				setmax(ans, (LL)a[i].X);
				continue;
			}
			
			LL curr = a[i].X;
			auto it = lower_bound(ALL(a), MP(a[i].Y, (int)INF)) - a.begin();
			if (it == m){
				curr += (n - 1) * (LL) a[i].Y;
				setmax(ans, curr);
				continue;
			}
			
			int from = it, to = m - 1;
			int cnt = m - it;
			if (cnt > n - 1){
				from = to - (n - 1) + 1;
				cnt = n - 1;
			}
			
			if (from <= i) curr -= a[i].X, cnt--;
			curr += s[to];
			if (from > 0) curr -= s[from - 1];

			curr += a[i].Y * (LL) (n - 1 - cnt);
			setmax(ans, curr);
		}
		
		cout << ans << endl;
	}
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}