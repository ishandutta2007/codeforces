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

const double PI = acos(-1.0);
const LL INF = 1e9 + 47;
const LL LINF = INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1 << 18;
int n;
int a[N];

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		FOR(i, 0, n + n) cin >> a[i];
		int ans = INF;
		map<int, int> lst;
		lst[0] = 2 * n;
		int diff = 0;
		RFOR(i, n + n, n) 
		{
			if (a[i] == 1) diff++;
			else diff--;			
			lst[diff] = i;
		}
		
		diff = 0;
		FOR(i, 0, n)
		{
			if (a[i] == 1) diff++;
			else diff--;			
		}		
		
		RFOR(i, n, -1)
		{
			if (lst.count(-diff))
				ans = min(ans, n - i + lst[-diff] - n - 1);
			if (i == -1) break;
			if (a[i] == 1) diff--;
			else diff++;			
		}
		
		cout << ans << endl;
	}
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}