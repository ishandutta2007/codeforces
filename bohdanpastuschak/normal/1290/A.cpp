#include <bits/stdc++.h>
using namespace std;
 
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

const int N = 3500 + 47;
int n, m, k;
int a[N];

void solve()
{
	cin >> n >> m >> k;
	m--;
	k = min(k, m);
	FOR(i, 0, n) cin >> a[i];
	int ans = 0;
	int zle = m - k;	
	FOR(l, 0, k + 1) 
	{
		int L = l, R = n - 1 - (k - l);
		
		int tut = INF;
		FOR(livo, 0, zle + 1)
		{
			int Le = L + livo;
			int pravo = zle - livo;
			int Ri = R - pravo;
			int H = max(a[Le], a[Ri]);
			setmin(tut, H);
		}
		
		setmax(ans, tut);
	}
	
	cout << ans << endl;
}

int main()	
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while(t--) solve();
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}