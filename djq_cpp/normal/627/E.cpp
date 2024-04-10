#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int r, c, n, k;
int x[3005], y[3005];
LL ans;
vector<int> hvy[3005];
int pre[3005], nxt[3005], cnt[3005];

void remove_p(int id)
{
	pre[nxt[id]] = pre[id];
	nxt[pre[id]] = nxt[id];
}

int s0[15], s1[15], ps0[15], ps1[15];
int remove_v(int id)
{
	int t0 = 0, t1 = 0;
	for(int i = id; i != 0 && t0 < k; i = pre[i]) s0[t0 ++] = i;
	for(int i = id; i != c + 1 && t1 < k; i = nxt[i]) s1[t1 ++] = i;
	
	for(int i = 1; i < t0; i ++) ps0[i] = ps0[i - 1] + cnt[s0[i]];
	for(int i = 1; i < t1; i ++) ps1[i] = ps1[i - 1] + cnt[s1[i]];
	
	int ret = 0;
	int j = t1 - 1;
	rep(i, t0) {
		while(j > 0 && ps0[i] + ps1[j] + cnt[id] > k) j --;
		if(ps0[i] + ps1[j] + cnt[id] == k) ret += (s0[i] - pre[s0[i]]) * (nxt[s1[j]] - s1[j]);
	}
	
	cnt[id] --;
	if(cnt[id] == 0) remove_p(id);
	return ret;
}

void getans(int begx)
{
	nxt[0] = 1;
	rep1(i, c) {
		pre[i] = i - 1;
		nxt[i] = i + 1;
	}
	pre[c + 1] = c;
	
	for(int i = begx; i <= r; i ++) rep(j, hvy[i].size()) {
		int cy = hvy[i][j];
		cnt[cy] ++;
	}
	
	rep1(i, c) if(cnt[i] == 0) remove_p(i);
	
	for(int i = r; i >= begx; i --) {
		int ca = 0;
		rep(j, hvy[i].size()) {
			int cy = hvy[i][j];
			ca += remove_v(cy); 
		}
		ans += 1LL * (r - i + 1) * ca;
	}
}

int main()
{
	scanf("%d%d%d%d", &r, &c, &n, &k);
	rep(i, n) scanf("%d%d", &x[i], &y[i]);
	
	rep(i, n) hvy[x[i]].push_back(y[i]);
	
	rep1(i, r) getans(i);
	
	printf("%lld\n", ans);
	return 0;
}