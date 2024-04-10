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
const LL INF = 1e9 + 47;
const LL LINF = INF * INF;

const int mod = 1e9 + 7;

inline int add(int x, int y)
{
	if (x + y < mod)
		return x + y;
	return x + y - mod;
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

const int MAX = 1 << 20;
int cnt[MAX];
int a[MAX];
int n, x;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);
	
	cin >> n;
	FOR(i, 0, n)
	{
		cin >> x;
		cnt[x]++;
	}
	
	int ans = 0;
	
	FOR(i, 2, MAX)
		for(int j = i + i; j < MAX; j += i)
			cnt[i] = add(cnt[i], cnt[j]);
	
	FOR(i, 2, MAX)
		if (cnt[i])
			a[i] = mult(power(2, cnt[i] - 1), cnt[i]);
	
	RFOR(i, MAX, 2)
		for(int j = i + i; j < MAX; j += i)
			a[i] = add(a[i], mod - a[j]);
	
	FOR(i, 2, MAX)
		ans = add(ans, mult(i, a[i]));
	
	cout << ans << endl;
	cerr << "Time elapsed : " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}