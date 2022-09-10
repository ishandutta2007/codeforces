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

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<int> a(n + 1);
		FOR(i, 1, n + 1) cin >> a[i];
		vector<vector<int>> b(n + 1, {0});
		FOR(i, 1, n + 1){
			b[a[i]].PB(i);
		}
		FOR(i, 1, n + 1) b[i].PB(n + 1);

		vector<int> ans(n + 1, INF);
		FOR(i, 1, n + 1){
			const auto& c = b[i];
			if (SZ(c) == 0){
				continue;
			}

			int mx = 0;
			FOR(j, 1, SZ(c)) setmax(mx, c[j] - c[j - 1]);
			if (mx <= n){
				setmin(ans[mx], i);
			}
		}
		
		FOR(i, 1, n + 1) setmin(ans[i], ans[i - 1]);
		FOR(i, 1, n + 1) cout << (ans[i] == INF ? -1 : ans[i]) << ' ';
		cout << endl;
	}
    cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}