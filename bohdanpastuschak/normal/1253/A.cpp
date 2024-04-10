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
#define debug(a) cerr << #a << " = " << a << endl;

const double PI = acos(-1.0);
const LL INF = 1e9;
const LL LINF = INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1 << 17;
int n;
int a[N];
int b[N];

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

	int t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		FOR(i, 0, n) cin >> a[i];
		FOR(i, 0, n) cin >> b[i];
		FOR(i, 0, n) b[i] -= a[i];
		
		bool ok = 1;
		bool poc = 0, kin = 0;
		int zn = -1;
		FOR(i, 0, n)
		{
			if (b[i] < 0) 
			{
				ok = 0;
				continue;
			}
			
			if (b[i] == 0)
			{
				if (!poc) continue;
				kin = 1;
				zn = -1;
				continue;
			}
			
			if (zn == -1)
			{
				if (kin) ok = 0;
				poc = 1;
				zn = b[i];
				continue;
			}		
			
			if (zn != b[i]) ok = 0;
		}
		
		if (ok) cout << "YES\n";
		else cout << "NO\n";
	}
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}