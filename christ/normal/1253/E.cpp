#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int MN = 81, MM = 2e5+1, INF = 2e9;
int dp[MN][MM];
int main() {
    int n,m;
    scanf ("%d%d",&n,&m);
    vector<pii> ant(n+1);
    for (int i = 1; i <= n; i++) scanf ("%d%d",&ant[i].first,&ant[i].second);
    sort(ant.begin()+1,ant.end());
    memset(dp,0x3f,sizeof dp);
    for (int i = 0; i < MN; i++) dp[i][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m*2; j++) {
            dp[i][j] = dp[i-1][j];
            if (ant[i].first > j) continue;
            dp[i][j] = min(dp[i][j],dp[i-1][max(0,ant[i].first-max(j-ant[i].first,ant[i].second)-1)]+max(0,j-ant[i].first-ant[i].second));
        }
        for (int j = m*2-1; j >= 1; j--) {
            dp[i][j] = min(dp[i][j],dp[i][j+1]);
        }
    }
    int ret = INT_MAX;
    for (int i = m; i <= m*2; i++) ret = min(ret,dp[n][i]);
    assert(ret < 1e9);
    printf ("%d\n",ret);
	return 0;
}
//11649,6796