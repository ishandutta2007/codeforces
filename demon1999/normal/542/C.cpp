/*















*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
#define zhfs main
#define mp(a, b) make_pair(a, b)
#define fi first
#define se second
#define re return
#define forn(i, n) for (int i = 1; i <= n; i++)
const int MAXN = 207;
int a[MAXN];
ll gcd(ll x, ll y)
{
	if (y == 0) re x;
	re gcd(y, x % y);
}
ll lcm(ll x, ll y)
{
	re x / gcd(x, y) * y;
}
int was[MAXN];
int zhfs()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	ll res = 1;
	int mn = 0;
	for (int i = 1; i <= n; i++)
	{
		memset(was, false, sizeof(was));
		int v = i, d = 1;
		while (!was[v])
		{
			was[v] = d;
			v = a[v];
			d++;
		}
		res = lcm(res, d - was[v]);
		mn = max(mn, was[v] - 1);
	}
	ll ans = res;
	while (ans < mn) ans += res;
	printf("%lld\n", ans);
}