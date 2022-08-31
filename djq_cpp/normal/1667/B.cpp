#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;

int n, dp[500005];
LL a[500005];
vector<LL> val;
struct fwt
{
	int m, val[500005];
	void clear(int cm)
	{
		m = cm;
		rep1(i, m) val[i] = -INF; 
	}
	void ins(int id, int x)
	{
		for(id ++; id <= m; id += id & -id) val[id] = max(val[id], x);
	}
	int query(int id)
	{
		int ret = -INF;
		for(id ++; id > 0; id -= id & -id) ret = max(ret, val[id]);
		return ret;
	}
}t0, t1;
void solve()
{
	scanf("%d", &n);
	rep1(i, n) scanf("%lld", &a[i]);
	rep1(i, n) a[i] += a[i - 1];
	val.clear();
	rep(i, n + 1) val.push_back(a[i]);
	sort(val.begin(), val.end());
	val.resize(unique(val.begin(), val.end()) - val.begin());
	
	t0.clear(n + 1);
	t1.clear(n + 1);
	rep(i, n + 1) {
		int cur = lower_bound(val.begin(), val.end(), a[i]) - val.begin();
		if(i == 0) dp[i] = 0;
		else dp[i] = max(dp[i - 1] - 1, max(t0.query(cur), t1.query(cur) + i));
		t0.ins(cur, dp[i]);
		t1.ins(cur + 1, dp[i] - i);
	}
	printf("%d\n", dp[n]);
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T --) solve();
	return 0;
}