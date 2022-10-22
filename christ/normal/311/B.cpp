#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
#define io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
const int MN = 1e5+3;
int dist[MN], t[MN]; ll dp[MN][105],psa[MN];
void solve (int l, int r, int j, int dl, int dr) {
	int i = l+r>>1;
	int ed = min(dr,i);
	int des = -1;
	for (int k = dl; k <= ed; k++) {
		ll att = dp[k-1][j-1]+(ll)t[i]*(i-k)-psa[i-1]+psa[k-1];
		if (att < dp[i][j]) {
			des = k;
			dp[i][j] = att;
		}
	}
	if (i-1 >= l) solve(l,i-1,j,dl,des);
	if (i+1 <= r) solve(i+1,r,j,des,dr);
}
int main () {
	int n,m,p;
	scanf ("%d %d %d",&n,&m,&p);
	for (int i = 2; i <= n; i++) scanf ("%d",&dist[i]), dist[i] += dist[i-1];
	for (int i = 1; i <= m; i++) {
		int h; scanf ("%d %d",&h,&t[i]); t[i] -= dist[h];
	}
	sort(t+1,t+1+m); memset(dp,0x3f,sizeof dp); dp[0][0] = 0;
	for (int i = 1; i <= m; i++) psa[i] = psa[i-1] + t[i];
	for (int j = 1; j <= p; j++) {
		solve(j,m,j,1,m);
	}
	printf ("%lld\n",dp[m][p]);
	return 0;
}