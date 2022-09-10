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

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("In.txt", "w", stdout);
	
	string s;
	cin >> s;
	if (SZ(s) & 1)
		s.pop_back();
		
	int n = SZ(s);
	
	string poc, kin;
	int x = 0, y = n - 1;		
	while(SZ(poc) + SZ(kin) < n / 2)
	{
		if (x == y)
		{
			poc += s[x];
			continue;
		}
		
		assert(x < y);
		if (s[x] == s[y])
		{
			poc.PB(s[x]);
			if (x != y)
				kin.PB(s[y]);
			++x, --y;
			continue;
		}
		
		if (s[x + 1] == s[y])
		{
			++x;
			poc.PB(s[x]);
			if (x != y)
				kin.PB(s[y]);
			++x, --y;
			continue;
		}
		
		if (s[x] == s[y - 1])
		{
			--y;
			poc.PB(s[x]);
			if (x != y)
				kin.PB(s[y]);
			++x, --y;
			continue;
		}
		
		++x;
		--y;
		assert(s[x] == s[y]);
	}
			
	reverse(ALL(kin));
	poc += kin;
	cout << poc << endl;
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}