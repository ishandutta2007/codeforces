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

int solve(vector<int>& a){
	int ans = 0;
	FOR(i, 0, SZ(a) - 2){
		if (a[i] == a[i + 1] && a[i] == a[i + 2]){
			
			FOR(j, i, SZ(a)) if (a[i] != a[j]){
				vector<int> b;
				FOR(x, 0, i) b.PB(a[x]);
				FOR(x, j, SZ(a)) b.PB(a[x]);
				return SZ(a) - SZ(b) + solve(b);
			}
			
			return SZ(a) - i;
		}
	}
	
	return ans;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n, k, x;
	cin >> n >> k >> x;
	
	vector<int> c(n);
	FOR(i, 0, n) cin >> c[i];
	int ans = 0;
	FOR(i, 0, n + 1){
		vector<int> a;
		FOR(j, 0, i) a.PB(c[j]);
		a.PB(x);
		FOR(j, i, n) a.PB(c[j]);
		setmax(ans, solve(a));
	}
	
	cout << max(0, -1 + ans) << endl;
	
    cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}