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

const int N = 1 << 20;
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
		FOR(i, 0, n) cin >> a[i];
		bool ok = true;
		
		int g = -1, s, b;
		FOR(i, 1, n) if (a[i] != a[i - 1])
		{
			g = i;
			break;
		}
		
		int last = -1;
		RFOR(i, n / 2, 0) if (a[i] != a[i + 1])
		{
			last = i;
			break;
		}
		
		if (g == -1 || g + g > n || last == -1)
		{
			cout << "0 0 0\n";
			continue;
		}		
		
		s = 0, b = 0;
		FOR(i, g, last + 1)	
		{
			if (a[i] != a[i + 1])
			{
				if (i >= g + g)
				{
					s = i - g + 1;
					b = last + 1 - g - s;
					break;
				}
			}
		}			
		
		if (g >= b) ok = 0;
		if (g >= s) ok = 0;
		
		if (ok) cout << g << ' ' << s << ' ' << b << '\n';
		else cout << "0 0 0\n";
	}	
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}