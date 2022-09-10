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

bool ok(LL x, LL k, LL n)
{
    return k * (k + 1) / 2 <= n / x;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

    LL n, k;
    cin >> n >> k;
    
    if (k > INF || k * (k + 1) / 2 > n)
    {
        cout << -1 << endl;
        return 0;
    }
    
    LL mx = -1;
    for(LL i= 1; i * i <= n; ++i)
    {
        if (n % i)
            continue;
        
        if (ok(i, k, n))
            mx = max(mx, i);
        if (ok(n / i, k, n))
            mx = max(mx, n / i);
    }
    
    FOR(i, 0, k - 1)
        cout << mx * (i + 1)<< " ", n -= mx * (i + 1);
    cout << n << endl;
    
	cerr << "Time elapsed : " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}