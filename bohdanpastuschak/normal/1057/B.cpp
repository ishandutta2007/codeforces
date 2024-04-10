#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC target("sse4")

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

int a[1 << 20];
int p[1 << 20];

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("In.txt", "w", stdout);

	int n;
	cin >> n;
	FOR(i, 0, n)
		cin >> a[i];
	
	p[0] = a[0];
	FOR(i, 1, n)	
		p[i] = p[i - 1] + a[i];
	
	int ans = 0;
	FOR(l, 0, n)
		FOR(len, 1, n - l + 1)
		{
			int tut = p[len + l - 1];
			if (l)
				tut -= p[l - 1];
			if (tut > 100 * len)
				ans = max(ans, len);
		}
	cout << ans << endl;
	cerr << "Time elapsed : " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}