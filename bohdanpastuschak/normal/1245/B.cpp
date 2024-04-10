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
const LL INF = 1e9;
const LL LINF = INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);
	
	int t;
	cin >> t;
	while(t--)
	{
		int n, a, b, c;
		cin >> n >> a >> b >> c;
		string s;
		cin >> s;
		string ans(n, 0);
		int bad = 0;
		
		FOR(i, 0, n)
		{
			if (s[i] == 'R' && b)
			{
				ans[i] = 'P';
				--b;
				continue;
			}
			
			if (s[i] == 'P' && c)
			{
				ans[i] = 'S';
				--c;
				continue;
			}
			
			if (s[i] == 'S' && a)
			{
				ans[i] = 'R';
				--a;
				continue;
			}
			
			bad++;
		}
		
		if (bad > n - bad)
		{
			cout << "NO\n";
			continue;
		}
		
		FOR(i, 0, n)
			if (ans[i] == 0)
			{
				if (a)
					ans[i] = 'R', --a;
				else if (b)
					ans[i] = 'P', --b;
					else if (c)
						ans[i] = 'S', --c;
						else assert(0);
			}
			
		cout << "YES\n" << ans << '\n';				
	}
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}