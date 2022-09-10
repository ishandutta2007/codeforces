#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
 
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

const int N = 1 << 21;
int n;
int a[N];
int mn_suf[N];

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("In.txt", "w", stdout);

	cin >> n;
	FOR(i, 0, n)
		cin >> a[i];
	
	sort(a, a + n);
	n = unique(a, a + n) - a;
	FOR(i, 0, N)
		mn_suf[i] = -1;
	FOR(i, 0, n)
		mn_suf[a[i]] = a[i];
	FOR(i, 1, N)
		mn_suf[i] = max(mn_suf[i - 1], mn_suf[i]);
			
	int ans = 0;
	FOR(i, 0, n)
		for(int j = a[i] + a[i]; j < N; j += a[i])
			ans = max(ans, mn_suf[j - 1] % a[i]);
			
	cout << ans << endl;
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}