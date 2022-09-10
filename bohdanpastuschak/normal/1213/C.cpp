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
#define ITER(it, a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)((a).size())
#define FILL(a, value) memset(a, value, sizeof(a))
#define debug(a) cout << #a << " = " << a << endl;

const double PI = acos(-1.0);
const LL INF = 1e9 + 47;
const LL LINF = INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("In.txt", "w", stdout);
	
	int t;
	cin >> t;
	while(t--)
	{
		LL n, m;
		cin >> n >> m;
		
		LL ans = 0;
		if (n / m <= 100)
		{
			for(LL i = m; i <= n; i += m)
				ans += i % 10;
		}
		else
		{
			VI bulo;
			for(LL i = m; i <= n; i += m)
			{
				int x = i % 10;
				bool ok = 1;
				for(auto j: bulo)
					if (j == x)
						ok = 0;
				
				if (ok)
					bulo.PB(x);
				else
					break;
			}
			
			LL all = n / m;
			int sum = 0;
			for(auto i: bulo)
				sum += i;
			
			ans += sum * (all / SZ(bulo));
			int rem = all % SZ(bulo);
			FOR(i, 0, rem)
				ans += bulo[i];
		}
		
		cout << ans << endl;
	}
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}