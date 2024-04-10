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

#define FOR(i, a, b) for(LL i = (a); i < (b); ++i)
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

inline pair<int, int> get(int x, int y, int n)
{
	if (y < n) return {x, y + 1};
	if (x + 1 < n) return {x + 1, x + 2};
	return {1, -1};
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int t;
	cin >> t;
	while(t--)
	{
		LL n, l, r;
		cin >> n >> l >> r;
		if (l == n * (n - 1) + 1)
		{
			cout << 1 << endl;
			continue;
		}
		
		LL Len = r - l + 1;
		
		int x = 1;
		while(true)
		{
			if (l > 2 * (n - x))
			{
				l -= 2 * (n - x);
				x++;
			}
			else break;
		}
		
		int y = x + 1;
		
		vector<int> Ans;
		while(SZ(Ans) < 2 * n + Len)
		{
			Ans.PB(x);
			if (y == -1) break;
			Ans.PB(y);
			auto tut = get(x, y, n);
			x = tut.X;
			y = tut.Y;			
		}
		
		LL from = l - 1;
		
		FOR(i, from, from + Len) cout << Ans[i] << ' ';		
		
		cout << endl;
	}	
		
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}