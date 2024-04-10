#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int NMAX = 4040;
const int INF = 0x3f3f3f3f;

int dp[NMAX][NMAX];
int la[256], lb[256];

char a[NMAX], b[NMAX];
int n, m;
int ti, td, tr, te;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> ti >> td >> tr >> te;
    cin >> (a+1) >> (b+1);
    n = strlen(a+1);
    m = strlen(b+1);
    memset(dp, INF, sizeof dp);
    dp[0][0] = 0;
    for(int i=0;i<=m;++i) {
        dp[0][i] = ti*i;
    }
    for(int i=0;i<=n;++i) {
        dp[i][0] = td*i;
    }
    memset(la, 0, sizeof la);
    for(int i=1;i<=n;++i) {
        memset(lb, 0, sizeof lb);
        for(int j=1;j<=m;++j) {
            if(a[i] == b[j]) {
                dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
            }
            dp[i][j] = min(dp[i][j], dp[i-1][j]+td);
            dp[i][j] = min(dp[i][j], dp[i][j-1]+ti);
            dp[i][j] = min(dp[i][j], dp[i-1][j-1]+tr);
            //cerr << " look for replace " << b[j] << " at " << la[b[j]] << " and " << a[i] << " at " << lb[a[i]] << endl;
            if(la[b[j]] && lb[a[i]]) {
                int v = dp[la[b[j]]-1][lb[a[i]]-1] + td*(i-la[b[j]]-1) + ti*(j-lb[a[i]]-1) + te;
                //cerr << " replace costs " << v << endl;
                dp[i][j] = min(dp[i][j], v);
            }
            //cerr << "! dp " << i << " " << j << " = " << dp[i][j] << endl;
            lb[b[j]] = j;
        }
        la[a[i]] = i;
    }
    cout << dp[n][m] << endl;
    return 0;
}