#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int n, m, a[1000005], b[1000005];
PII perm[1000005];
struct fwt
{
	int dat[1000005];
	void clear()
	{
		rep1(i, n) dat[i] = 0;
	}
	void add(int id, int val)
	{
		for(id ++; id <= n; id += id & -id) dat[id] += val;
	}
	int query(int id)
	{
		int ret = 0;
		for(id ++; id > 0; id -= id & -id) ret += dat[id];
		return ret;
	}
}tre;

LL ans;
priority_queue<int> que;
void addnew(int x)
{
	if(que.empty()) {
		que.push(x);
	} else if(x >= que.top()) que.push(x);
	else {
		ans += que.top() - x;
		que.push(x); que.push(x); que.pop();
	}
}
void solve()
{
	scanf("%d%d", &n, &m);
	rep(i, n) scanf("%d", &a[i]);
	rep(i, m) scanf("%d", &b[i]);
	sort(b, b + m);
	rep(i, n) perm[i] = MP(a[i], i);
	sort(perm, perm + n);
	ans = 0;
	tre.clear();
	rep(i, n) {
		ans += 2 * (i - tre.query(perm[i].second));
		tre.add(perm[i].second, 1);
	}
	while(!que.empty()) que.pop();
	rep(i, n) {
		int r = upper_bound(b, b + m, a[i]) - b, l = lower_bound(b, b + m, a[i]) - b; 
		addnew(r); addnew(l); ans -= r - l;
	}
	assert(ans % 2 == 0);
	printf("%lld\n", ans / 2);
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T --) solve();
	return 0;
}