/*






le
toucan
has
arrived*/
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
const int MAXN = 100 * 1000 + 7;
int a[MAXN], b[MAXN];
int zhfs()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	int n, p;
	scanf("%d %d", &n, &p);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d %d", &a[i], &b[i]);
	}
	ld l = 0, r = (ld)1e20;
	while (1.0 * clock() / CLOCKS_PER_SEC < 1.7)
	{
		ld m = (l + r) / 2.0;
		ld needTime = 0;
		for (int i = 1; i <= n; i++)
		{
			ld needPow = m * a[i] - b[i];
			if (needPow < 0) needPow = 0;
			needTime += 1.0 * needPow / p;
		}
		if (needTime <= m)
		{
			l = m;
		}
		else
		{
			r = m;
		}
	}
	if (l > (ld)1e19)
	{
		printf("-1\n");
	}
	else
	{
		printf("%.20lf\n", (double)l);
	}
}