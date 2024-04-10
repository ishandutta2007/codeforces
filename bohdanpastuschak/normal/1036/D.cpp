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

const int N = 1 << 19;
int n, m;
LL a[N], b[N];

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("In.txt", "w", stdout);

	cin >> n;
	FOR(i, 0, n)
		cin >> a[i];
	cin >> m;
	FOR(i, 0, m)
		cin >> b[i];
	
	LL s1 = 0, s2 = 0;
	FOR(i, 0, n)
		s1 += a[i];
	FOR(i, 0, m)
		s2 += b[i];
	
	if (s1 != s2)
	{
		cout << -1;
		return 0;
	}
	
	int len = 0;
	while(n && m)
	{
		
		if (a[n - 1] == b[m - 1])
		{
			len++;
			n--;
			m--;
			continue;
		}
		
		if (a[n - 1] < b[m - 1])
		{
			a[n - 2] += a[n - 1];
			--n;
			continue;
		}
		
		b[m - 2] += b[m - 1];
		--m;
		continue;
	}
	
	assert(n + m == 0);
	cout << len << endl;
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}