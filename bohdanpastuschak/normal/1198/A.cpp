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
int a[N];

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("In.txt", "w", stdout);
		
	cin >> n >> m;
	m *= 8;
	FOR(i, 0, n)
		cin >> a[i];
	
	sort(a, a + n);
	VI b(n);
	FOR(i, 0, n)
		b[i] = a[i];
	
	b.resize(unique(ALL(b)) - b.begin());
	
	int log2k = m / n;
	if (log2k >= 19)
	{
		cout << 0;
		return 0;
	}
	
	int k = 1 << (log2k);
	
	if (k >= SZ(b))
	{
		cout << 0;
		return 0;
	}
		
	int ans = n;
	
	FOR(i, 0, n)
	{
		int pos = lower_bound(ALL(b), a[i]) - b.begin();
		int nxt = min(SZ(b) - 1, pos + k - 1);
		
		int first_more = upper_bound(a, a + n, b[nxt]) - a;
		int curr = n - first_more;
		curr += i;
		ans = min(ans, curr);
	}
				
	cout << ans << endl;
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}