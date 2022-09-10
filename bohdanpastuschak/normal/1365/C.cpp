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
mt19937 rng(58);

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	FOR(i, 0, n) cin >> a[i], a[i]--;
	FOR(i, 0, n) cin >> b[i], b[i]--;
	int ans = 0;
	vector<int> mp(n);
	FOR(i, 0, n) mp[b[i]] = i;
	FOR(i, 0, n) a[i] = mp[a[i]];
	
	vector<int> df(n, 0);
	FOR(i, 0, n) df[(a[i] - i + n) % n]++;
	FOR(i, 0, n) setmax(ans, df[i]);
		
	cout << ans << endl;
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}