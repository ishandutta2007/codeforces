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

const int mod = 1e9 + 7;

int add(int x, int y)
{
	if (x + y < mod)
		return x + y;
	return x + y - mod;
}

int mult(int x, int y)
{
	return x * (LL) y % mod;
}

int power(int x, int y)
{
	int r = 1;
	while(y)
	{
		if (y & 1)
			r = mult(r, x);
		x = mult(x, x);
		y >>= 1;
	}
	
	return r;
}

map<int, int> mp;

int f(int n)
{
	if (n == 1)
		return 1;
	if (mp.count(n))
		return mp[n];
	
	int res = 0;
	
	for(int i = 1; i * i <= n; ++i)
	{
		if (n % i)
			continue;
		
		res = add(res, f(i));
		if (i != 1 && i * i != n)
			res = add(res, f(n / i));
	}
	
	res = add(mod - res, power(2, n - 1));
	return mp[n] = res;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);
	
	LL y, x;
	cin >> y >> x;
	if (x % y)
	{
		cout << 0;
		return 0;
	}
	
	cout << f (x / y) << endl;	
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}