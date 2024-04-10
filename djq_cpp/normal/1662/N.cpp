#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int n, a[1505][1505];
struct fwt
{
	int dat[1505];
	void add(int id, int x)
	{
		dat[0] += x; return;
		for(; id <= n; id += id & -id) dat[id] += x;
	}
	int query(int id)
	{
		return dat[0];
		int ret = 0;
		for(; id > 0; id -= id & -id) ret += dat[id];
		return ret;
	}
}r[1505], c[1505];

int x[2250005], y[2250005];

int main()
{
	scanf("%d", &n);
	rep1(i, n) rep1(j, n) {
		scanf("%d", &a[i][j]);
		x[a[i][j]] = i; y[a[i][j]] = j;
	}
	
	LL ans = 0;
	rep1(i, n * n) {
		ans += r[x[i]].query(y[i]) * c[y[i]].query(x[i]);
		r[x[i]].add(y[i], 1);
		c[y[i]].add(x[i], 1);
	}
	ans = 2LL * n * n * (n - 1) * (n - 1) / 4 - ans;
	printf("%lld\n", ans);
	return 0;
}