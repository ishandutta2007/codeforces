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

int main()
{	
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int t;
	cin >> t;
	while(t--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		vector<int> all;
		FOR(i, 1, 8) all.PB(i);
		
		int ans = 0;
		FOR(mask, 0, 1 << 7)
		{
			int A = 0, B = 0, C = 0;
			FOR(i, 0, 7) if (mask & (1 << i))
			{
				A += all[i] & 1;
				B += (all[i] >> 1) & 1;
				C += (all[i] >> 2) & 1;
			}
			
			if (A > a) continue;
			if (B > b) continue;
			if (C > c) continue;
			setmax(ans, __builtin_popcount(mask));
		}
		
		cout << ans << endl;
	}
	
	//cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}