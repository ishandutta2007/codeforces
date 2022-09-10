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

const int N = 1 << 19;
int n;
int a[N];
int best = -1;
int res[N];

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	cin >> n;
	FOR(i, 0, n) cin >> a[i];
	LL ans = 0;
	
	FOR(i, 0, n)
	{
		LL tut = a[i];
		int last = a[i];
		RFOR(j, i, 0)
		{
			setmin(last, a[j]);
			tut += last;
		}
		
		last = a[i];
		FOR(j, i + 1, n)
		{
			setmin(last, a[j]);
			tut += last;
		}
		
		if (tut > ans)
		{
			ans = tut;
			best = i;
		}
	}
	
	cerr << ans << endl;
	
	int last = a[best];
	res[best] = a[best];
	RFOR(j, best, 0)
	{
		setmin(last, a[j]);
		res[j] = last;
	}
	
	last = a[best];
	FOR(j, best + 1, n) 
	{
		setmin(last, a[j]);
		res[j] = last;
	}
	
	FOR(i, 0, n) cout << res[i] << ' ';
	cout << endl;
	
	//cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}