#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 1e9 + 7;


int n, a[200005];
PII ord[200005];

struct fwt
{
	int dat[200005];
	void clear()
	{
		rep1(i, n) dat[i] = 0;
	}
	void add(int id, int val)
	{
		for(id ++; id <= n; id += id & -id) dat[id] = (dat[id] + val) % MOD;
	}
	int query(int id)
	{
		int ret = 0;
		for(id ++; id > 0; id -= id & -id) ret = (dat[id] + ret) % MOD;
		return ret;
	}
}tre;

int fr[200005], to[200005], cdp[200005];
void solve()
{
	scanf("%d", &n);
	rep(i, n) scanf("%d", &a[i]);
	rep(i, n) ord[i] = MP(a[i], ~i);
	sort(ord, ord + n);
	rep(i, n) ord[i].second = ~ord[i].second;
	
	tre.clear();
	rep(i, n) {
		int cur = ord[i].second;
		fr[cur] = (tre.query(cur) + 1) % MOD;
		tre.add(cur, fr[cur]);
	}
	tre.clear();
	for(int i = n - 1; i >= 0; i --) {
		int cur = ord[i].second;
		to[cur] = (tre.query(n - 1) - tre.query(cur - 1) + MOD + 1) % MOD;
		tre.add(cur, to[cur]);
	}
	tre.clear();
	int ni = n - 1, nc = -1;
	for(int i = n - 1; i >= 0; i --) {
		int cur = ord[i].second;
		if(cur > nc) {
			for(int j = i + 1; j <= ni; j ++) tre.add(ord[j].second, (MOD - cdp[ord[j].second]) % MOD);
			ni = i; nc = cur; cdp[cur] = 1;
		} else cdp[cur] = (tre.query(n - 1) - tre.query(cur - 1) + MOD) % MOD;
		tre.add(cur, cdp[cur]);
	}
	
	int ans = 0;
	rep(i, n) ans = (ans + 1ULL * fr[i] * (to[i] - cdp[i] + MOD)) % MOD;
	printf("%d\n", ans);
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T --) solve();
	return 0;
}