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

const int N = 1 << 17;
int n, k;
int x[N];
bool was[N];
int first[N];
int last[N];

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);
		
	cin >> n >> k;
	FILL(first, -1);
	FOR(i, 0, k)
	{
		cin >> x[i];
		--x[i];
		last[x[i]] = i;
		if (first[x[i]] == -1)
			first[x[i]] = i;
		was[x[i]] = 1;
	}
	
	int ans = 0;
	FOR(i, 0, n)
	{
		if (!was[i])
		{
			ans += 3;
			if (i == 0)
				ans--;
			if (i == n -1)
				ans--;
			continue;
		}
		
		if (i)
		{
			int pered = first[i];
			if (pered >= last[i - 1])
				ans++;
		}
		
		if (i < n - 1)
		{
			int pered = first[i];
			if (pered >= last[i + 1])
				ans++;
		}
	}
	
	cout << ans << endl;
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}