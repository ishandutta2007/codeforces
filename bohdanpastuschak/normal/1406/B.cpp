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
		vector<int> a, b;
		LL ans = -LINF;
		while(n--){
			int x; cin >> x;
			if (x > 0) a.PB(x);
			else if (x < 0) b.PB(x);
			else ans = 0;
		}

		sort(ALL(a));
		sort(ALL(b));
		vector<int> C;
		FOR(i, 0, SZ(a)) if (i < 5 || i + 5 >= SZ(a)) C.PB(a[i]);
		FOR(i, 0, SZ(b)) if (i < 5 || i + 5 >= SZ(b)) C.PB(b[i]);

		a = C;
		if (SZ(a) >= 5){
			FOR(i1, 0, SZ(a)) FOR(i2, 0, i1) FOR(i3, 0, i2) FOR(i4, 0, i3) FOR(i5, 0, i4){
				setmax(ans, 1LL * a[i1] * a[i2] * a[i3] * a[i4] * a[i5]);
			}
		}
		
		cout << ans << endl;		
	}
	
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;	
	return 0;
}