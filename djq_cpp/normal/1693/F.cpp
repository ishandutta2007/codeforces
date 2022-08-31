#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;

struct segt
{
	int tre[524288];
	void clear(int n)
	{
		for(int l = 262144, r = 262145 + n; l > 0; l >>= 1, r >>= 1)
		for(int i = l; i <= r; i ++) tre[i] = INF;
	}
	void modify(int id, int val)
	{
		for(id |= 262144; id >= 1; id >>= 1) tre[id] = min(tre[id], val);
	}
	int query(int l, int r)
	{
		int ret = INF;
		for(l |= 262144, r |= 262144; l < r; l >>= 1, r >>= 1) {
			if(l & 1) ret = min(ret, tre[l ++]);
			if(!(r & 1)) ret = min(ret, tre[r --]);
		}
		if(l == r) ret = min(ret, tre[l]);
		return ret;
	}
}t0, t1;

int n, dp[200005], ps[2][200005];
char ch[200005];
void solve()
{
	scanf("%d%s", &n, ch);
	rep(i, n) ch[i] -= '0';
	int s = 0;
	rep(i, n) s += ch[i] == 1 ? 1 : -1;
	if(s > 0) {
		reverse(ch, ch + n);
		rep(i, n) ch[i] ^= 1;
	}
	rep(i, 2) rep(j, n) ps[i][j + 1] = ps[i][j] + (ch[j] == i);
	
	t0.clear(n); t1.clear(n);
	rep(i, n + 1) dp[i] = ps[1][i] ? INF : 0;
	rep(i, n + 1) {
		int cur = max(ps[0][i] - ps[1][i], 0);
		dp[i] = min(dp[i], t0.query(0, cur) + cur + 1);
		dp[i] = min(dp[i], t1.query(cur, n) + 1);
		cur = ps[0][i];
		t0.modify(cur, dp[i] - cur);
		t1.modify(cur, dp[i]);
	}
	printf("%d\n", ps[1][ps[0][n]] == 0 ? 0 : dp[n]);
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T --) solve();
	return 0;
}