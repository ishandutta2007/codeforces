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
const LL INF = 1e9 + 47;
const LL LINF = INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int mp[256];
int mp2[256];

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("In.txt", "w", stdout);
	
	int t;
	cin >> t;
	while(t--)
	{
		string a, b, c;
		FILL(mp, 0);
		FILL(mp2, 0);
		cin >> a >> b >> c;
		int n = SZ(a);
		int m = SZ(b);
		int x = 0, y = 0;
		FOR(i, 0, SZ(c))
			mp2[c[i]]++;
			
		while(x < n)
		{
			while(y < m && a[x] != b[y])
				mp[b[y]]++, y++;
				
			if (y < m)
				x++, y++;
			else
				break;
		}
		
		while(y < m)
			mp[b[y]]++, y++;
		
		bool ok = 1;
		ok &= x == n;
		
		FOR(i, 0, 256)
			ok &= mp[i] <= mp2[i];
			
		if (ok)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
		
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}