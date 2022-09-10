#include <bits/stdc++.h>
using namespace std;
 
typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<double> VD;
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

const int N = 10;
int n;
string s;

void solve()
{
	cin >> n >> s;
	FOR(i, 0, n)
		s[i] -= '0';
	
	FOR(d, 0, 10)
	{
		int lst_less = -1, lst_more = -1;
		bool ok = 1;
		string ans(n, '1');
		FOR(i, 0, n)
		{
			if (s[i] == d)
			{
				if (lst_more <= s[i])
				{
					lst_more = s[i];
					ans[i] = '2';
					continue;
				}
				
				ans[i] = '1';
				lst_less = s[i];
				continue;
			}
			
			if (s[i] < d)
			{
				ans[i] = '1';
				if (s[i] < lst_less)
					ok = 0;
				lst_less = s[i];
			}
			else
			{
				ans[i] = '2';
				if (s[i] < lst_more)
					ok = 0;
				lst_more = s[i];
			}
		}
		
		if (!ok)
			continue;
		
		cout << ans << '\n';
		return;
	}	
	
	cout << "-\n";
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("In.txt", "w", stdout);

	int t;
	cin >> t;
	while(t--)
		solve();
		
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}