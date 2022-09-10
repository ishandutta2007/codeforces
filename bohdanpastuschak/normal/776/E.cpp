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

LL phi(LL n)
{
	LL res = n;
	for(LL i = 2; i * i <= n; ++i)
		if (n % i == 0)
		{
			while(n % i == 0)
				n /= i;
			res /= i;
			res *= i - 1;
		}
	
	if (n > 1)
	{
		res /= n;
		res *= n - 1;
	}
	
	return res;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

	LL n, k;
	cin >> n >> k;
	k = (k + 1) / 2;
	while(k--)
	{
		if (n == 1)
			break;
		
		n = phi(n);
	}
	
	cout << (n % (int)(1e9 + 7)) << endl;
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}