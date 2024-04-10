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

inline int add(int x, int y)
{
	if (x + y >= mod)
		return x + y - mod;
	return x + y;
}

inline int mult(int x, int y)
{
	return x * (LL) y % mod;
}

inline int power(int x, int y)
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

LL n, k;
const int N = 10000 + 7;
VI prob[N];
int inv[N];

int get(LL p, int a)
{
	FOR(i, 0, k + 1)
		prob[i].assign(a + 1, 0);
	
	prob[k][a] = 1;
	RFOR(i, k + 1, 1)
		FOR(j, 0, a + 1)
			FOR(z, 0, j + 1)
				prob[i - 1][z] = add(prob[i - 1][z], mult(prob[i][j], inv[j + 1]));
	
	int res = 0;
	FOR(i, 0, a + 1)
		res = add(res, mult(prob[0][i], power(p % mod, i)));
	return res;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

	cin >> n >> k;
	int ans = 1;
	FOR(i, 1, N)
		inv[i] = power(i,  mod - 2);
	
	for(LL i = 2; i * i <= n; ++i)
	{
		if (n % i)
			continue;
		int cnt = 0;
		while(n % i == 0)
			n /= i, cnt++;
		
		ans = mult(ans, get(i, cnt));
	}
	
	if (n > 1)
		ans = mult(ans, get(n, 1));
	
	cout << ans << endl;
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}