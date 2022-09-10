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

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

	LL n, k, a, b;
	cin >> n >> k >> a >> b;
	LL A = n * k;
	LL mn = A, mx = 1;
	
	VI rem;
	FOR(l, 0, k)
	{
		bool ok = 0;
		if ((l + a + b) % k == 0)
			ok = 1;
		if ((l + a - b) % k == 0)
			ok = 1;
		if ((l - a + b) % k == 0)
			ok = 1;
		if ((l - a - b) % k == 0)
			ok = 1;
		if (!ok)
			continue;
		
		rem.PB(l);
	}

	FOR(i, 0, n)
		for(auto j: rem)
		{
			LL bude = i * k + j;
			mn = min(mn, A / __gcd(A, bude));
			mx = max(mx, A / __gcd(A, bude));
		}	
	
	cout << mn << ' ' << mx << endl;
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}