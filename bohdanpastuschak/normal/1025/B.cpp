#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define ITER(it, a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define FILL(a, value) memset(a, value, sizeof(a))

#define SZ(a) (int)((a).size())
#define ALL(a) a.begin(), a.end()
#define PB push_back
#define MP make_pair

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;

const double PI = acos(-1.0);
const int INF = 1000 * 1000 * 1000 + 7;
const LL LINF = INF * (LL)INF;

const int MAX = 1 << 20;
int n;
pair<LL, LL> a[MAX];

LL gcd(LL x, LL y)
{
	if (!y)
		return x;
	return gcd(y, x % y);
}

bool is(LL x)
{
	if (x == 1)
		return 0;
		
	for(LL i = 2; i*i <= x; ++i)
		if (x % i== 0)
			return 0;
			
	return 1;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	
	cin >> n;
	FOR(i, 0, n)
		cin >> a[i].first >> a[i].second;
		
	LL ans = 0;
	FOR(i, 0, n)
		ans = gcd(ans, a[i].first * a[i].second);
		
	if (ans == 1)
	{
		cout << -1 << endl;
		return 0;
	}
	
	if ((ans % a[0].first == 0) && is(a[0].first))
	{
		cout << a[0].first << endl;
		return 0;
	}
	
	if ((ans % a[0].second == 0) && is(a[0].second))
	{
		cout << a[0].second << endl;
		return 0;
	}
	
	//cout << ans << endl;
	for(LL i = 2; i* i <= a[0].first; ++i)
	{
		if (a[0].first % i)
			continue;
			
		if (ans % i == 0)
		{
			cout << i << endl;
			return 0;
		}
	
		i = a[0].first / i;
		
		if (ans % i == 0)
		{
			cout << i << endl;
			return 0;
		}
		
		i = a[0].first / i;	
	}
	

	for(LL i = 2; i * i <= a[0].second; ++i)
	{
		if (a[0].second % i)
			continue;
			
		if (ans % i == 0)
		{
			cout << i << endl;
			return 0;
		}
		
		i = a[0].second / i;
		if (ans % i == 0)
		{
			cout << i << endl;
			return 0;
		}

		i = a[0].second / i;
	}

	cout << ans << endl;
	return 0;
}