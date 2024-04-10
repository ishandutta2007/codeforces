#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int n, m;
int f[4096];
int dp[4096];
int dat[15][2005];
PII maxv[2005]; 

void solve()
{
	scanf("%d%d", &n, &m);
	rep(i, n) rep(j, m) scanf("%d", &dat[i][j]);
	rep(i, m) maxv[i] = MP(0, i);
	rep(i, n) rep(j, m) maxv[j] = max(maxv[j], MP(dat[i][j], j));
	sort(maxv, maxv + m);
	reverse(maxv, maxv + m);
	
	rep(i, 1 << n) dp[i] = 0;
	rep(i, min(n, m)) {
		int cid = maxv[i].second;
		
		rep(j, 1 << n) f[j] = 0;
		rep(j, 1 << n) {
			int cur = 0, cj = j;
			rep(k, n) if(j >> k & 1) cur += dat[k][cid];
			rep(k, n) {
				f[cj] = max(f[cj], cur);
				cj <<= 1;
				if(cj >> n & 1) cj ^= (1 << n) ^ 1;
			}
		}
		
		for(int j = (1 << n) - 1; j >= 0; j --)
		for(int k = j; k > 0; k = k - 1 & j)
		f[j] = max(f[j], f[j ^ k] + dp[k]);
		rep(j, 1 << n) dp[j] = f[j];
	}
	
	printf("%d\n", dp[(1 << n) - 1]);
} 

int main()
{
	int T;
	scanf("%d", &T);
	while(T --) solve();
	return 0;
}