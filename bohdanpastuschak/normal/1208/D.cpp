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

const int N = 1 << 18;
int n;
LL s[N];
int a[N];

LL f[N];

void add(int x, int y)
{
	for(; x < n; x |= x + 1)
		f[x] += y;
}

LL sum(int x)
{
	LL res = 0;
	for(; x >= 0; x = (x & (x + 1)) - 1)
		res += f[x];
	return res;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("In.txt", "w", stdout);
	
	cin >> n;
	FOR(i, 1, n + 1)
		add(i, i);
		
	FOR(i, 0, n)
		cin >> s[i];
	
	set<int> unused;
	FOR(i, 1, n + 1)
		unused.insert(i);
	
	RFOR(i, n, 0)
	{
		int l = *unused.begin(), r = *unused.rbegin(), m;
		int FND = -1;
		
		while(1)
		{
			if (r == *unused.lower_bound(l))
				break;

			m = *unused.lower_bound((l + r) >> 1);
		
			LL tut = sum(m - 1);
			if (tut == s[i])
			{
				FND = m;
				break;
			}
			
			if (tut > s[i])
			{
				auto it = unused.lower_bound(m);
				--it;
				r = *it;
			}				
			else
			{
				l = *unused.upper_bound(m);
			}
		}
		
		if (FND == -1)
		{
			if (sum(l - 1) < s[i])
				FND = *unused.upper_bound(l);
			else
				FND = l;
		}
		
		l = FND;
		assert(sum(l - 1) == s[i]);
		a[i] = l;
		add(l, -l);
		unused.erase(l);
	}
	
	FOR(i, 0, n)
		cout << a[i] << ' ';
	cout << endl;
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}