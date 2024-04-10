#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int n, k, s, a[16];
bitset<2005> dp[65536];
int dep[16];

int main()
{
	scanf("%d%d", &n, &k);
	rep(i, n) scanf("%d", &a[i]);
	rep(i, n) s += a[i];
	
	dp[0][0] = 1;
	rep(i, 1 << n) {
		for(int j = s / k; j >= 1; j --) dp[i][j] = dp[i][j] || dp[i][j * k];
		rep(j, n) if(!(i >> j & 1)) dp[i | 1 << j] |= dp[i] << a[j];
	}
	
	printf(dp[(1 << n) - 1][1] ? "YES\n" : "NO\n");
	if(!dp[(1 << n) - 1][1]) return 0;
	
	int cmask = (1 << n) - 1, cs = 1, cdep = 0;
	while(cmask != 0) {
		if(cs != 0 && cs * k <= s && dp[cmask][cs * k]) {
			cdep ++;
			cs *= k;
			continue;
		}
		rep(i, n) if((cmask >> i & 1) && cs >= a[i] && dp[cmask ^ 1 << i][cs - a[i]]) {
			dep[i] = cdep;
			cmask ^= 1 << i;
			cs -= a[i];
			break;
		}
	}
	
	priority_queue<PII> que;
	rep(i, n) que.push(MP(dep[i], a[i]));
	while(que.size() > 1) {
		PII c0 = que.top(); que.pop();
		PII c1 = que.top(); que.pop();
		printf("%d %d\n", c0.second, c1.second);
		c0.second += c1.second;
		while(c0.second % k == 0) {
			c0.second /= k;
			c0.first --;
		}
		que.push(c0);
	}
	return 0;
}