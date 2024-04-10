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

	int tc; cin >> tc;
	while(tc--){
		int n; cin >> n;
		vector<int> a(n), b(n), c(n);
		FOR(i, 0, n) cin >> a[i];
		FOR(i, 0, n) cin >> b[i];
		FOR(i, 0, n) cin >> c[i];
		vector<int> p(n, -1);
		p[0] = a[0];
		FOR(i, 1, n - 1){
			if (a[i] != p[i - 1]) p[i] = a[i];
			else if (b[i] != p[i - 1]) p[i] = b[i];
			else if (c[i] != p[i - 1]) p[i] = c[i];
		}

		p[n - 1] = a[n - 1];
		if (p[n - 1] == p[n - 2] || p[n - 1] == p[0]) p[n - 1] = b[n - 1];
		if (p[n - 1] == p[n - 2] || p[n - 1] == p[0]) p[n - 1] = c[n - 1];
				
		FOR(i, 0, n) cout << p[i] << ' ';
		cout << endl;
	}
	
    cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}