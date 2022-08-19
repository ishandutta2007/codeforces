#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int n, a[1005];
int grp[1005];
int ans[1005][1005];
int sz[1005], hvd[2005];
bool del[1005];
int maxa;

int main()
{
	scanf("%d", &n);
	rep(i, n) scanf("%d", &a[i]);
	rep(i, n) maxa = max(maxa, a[i]);
	maxa ++;
	
	rep(i, n) {
		rep(j, maxa) sz[j] = 0;
		rep(j, maxa) sz[grp[j]] ++;
		int cur = -1;
		rep(j, maxa) if(sz[j] > 1) cur = j;
		if(cur == -1) {
			rep(j, maxa) ans[j][i] = j < a[i];
			continue;
		}
		rep(j, maxa) ans[j][i] = -1;
		rep(j, maxa) if(grp[j] == cur) {
			ans[j][i] = 0;
			break;
		}
		for(int j = maxa - 1; j >= 0; j --) if(grp[j] == cur) {
			ans[j][i] = 1;
			break;
		}
		int hv = a[i] - 1;
		rep(j, maxa) {
			if(ans[j][i] != -1) continue;
			ans[j][i] = hv > 0;
			hv --;
		}
		
		rep(j, maxa) grp[j] = grp[j] * 2 + ans[j][i];
		rep(j, 2 * maxa) hvd[j] = -1;
		rep(j, maxa) hvd[grp[j]] = 0;
		int hs = 0;
		rep(j, 2 * maxa) if(hvd[j] == 0) hvd[j] = hs ++;
		rep(j, maxa) grp[j] = hvd[grp[j]];
	}
	
	int cnt = 0;
	rep(i, maxa) {
		bool ok = false;
		rep(j, n) if(ans[i][j]) ok = true;
		del[i] = !ok;
		cnt += del[i];
	}
	
	printf("%d\n", maxa - cnt);
	rep(i, maxa) {
		if(del[i]) continue;
		rep(j, n) printf("%d", ans[i][j]);
		printf("\n");
	}
	return 0;
}