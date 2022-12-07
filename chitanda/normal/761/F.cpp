//int!
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define FOR(i, l, r) for(int i = l; i <= r; i++)
#define ROF(i, r, l) for(int i = r; i >= l; i--)
#define all(a) a.begin(), a.end()
inline int ckmax(int &a, int b) { return a < b ? a = b, 1 : 0; }
inline int ckmin(int &a, int b) { return a > b ? a = b, 1 : 0; }
#define clean(a) memset(a, 0, sizeof(a))
typedef long long ll;

const int maxn = 1010, maxk = 300100;
int n, m, k;
int a[maxk], b[maxk], c[maxk], d[maxk];
char e[maxk];
ll cnt[2][maxn][maxn], sum[maxn][maxn];
ll res[maxk];
char mp[maxn][maxn];

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= n; ++i)
		scanf("%s", mp[i] + 1);
	for(int i = 1; i <= k; ++i)
		scanf("%d%d%d%d %c", a + i, b + i, c + i, d + i, e + i);
	for(int ch = 'a'; ch <= 'z'; ++ch){
		memset(cnt, 0, sizeof(cnt));
		for(int i = 1; i <= k; ++i){
			bool t = e[i] > ch;
			cnt[t][a[i]][b[i]]++;
			cnt[t][c[i] + 1][b[i]]--;
			cnt[t][a[i]][d[i] + 1]--;
			cnt[t][c[i] + 1][d[i] + 1]++;
		}
		
		for(int t = 0; t < 2; ++t)
			for(int i = 1; i <= n; ++i)
				for(int j = 1; j <= m; ++j)
					cnt[t][i][j] += cnt[t][i - 1][j] + cnt[t][i][j - 1] - cnt[t][i - 1][j - 1];
		
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= m; ++j){
				bool t = mp[i][j] > ch;
				cnt[t][i][j] += k - cnt[0][i][j] - cnt[1][i][j];
				sum[i][j] = cnt[t ^ 1][i][j];
			}

		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= m; ++j){
				for(int t = 0; t < 2; ++t)
					cnt[t][i][j] += cnt[t][i - 1][j] + cnt[t][i][j - 1] - cnt[t][i - 1][j - 1];
				sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
			}

		for(int i = 1; i <= k; ++i){
			ll tmp = sum[n][m]; bool t = e[i] <= ch;
			tmp -= sum[c[i]][d[i]] - sum[a[i] - 1][d[i]] - sum[c[i]][b[i] - 1] + sum[a[i] - 1][b[i] - 1];
			tmp += cnt[t][c[i]][d[i]] - cnt[t][a[i] - 1][d[i]] - cnt[t][c[i]][b[i] - 1] + cnt[t][a[i] - 1][b[i] - 1];
			res[i] += tmp;
		}
	}

	ll ans = 1LL << 60;
	for(int i = 1; i <= k; ++i)
		ans = min(ans, res[i]);
	printf("%lld\n", ans);
  return 0;
}
/*
                   _ooOoo_
                  o8888888o
                  88" . "88
                  (| -_- |)
                  O\  =  /O
               ____/`---'\____
             .'  \\|     |//  `.
            /  \\|||  :  |||//  \
           /  _||||| -:- |||||-  \
           |   | \\\  -  /// |   |
           | \_|  ''\---/''  |   |
           \  .-\__  `-`  ___/-. /
         ___`. .'  /--.--\  `. . __
      ."" '<  `.___\_<|>_/___.'  >'"".
     | | :  `- \`.;`\ _ /`;.`/ - ` : | |
     \  \ `-.   \_ __\ /__ _/   .-` /  /
======`-.____`-.___\_____/___.-`____.-'======
                   `=---='
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
                BUG
*/