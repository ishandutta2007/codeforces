#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
typedef long long int LLI;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
#define MOD 998244353

int adjMat[18];
vector<pair<int,LLI> > dp[1 << 18];
int main() {
    int i;
    int n,m,a,b;
    scanf("%d %d",&n,&m);
    for (i = 0; i < m; i++) {
        scanf("%d %d",&a,&b);
        a--,b--;
        adjMat[a] |= (1LL << b);
        adjMat[b] |= (1LL << a);
    }

    int j,k;
    dp[0].pb(mp((1 << n)-1,1));
    for (i = 0; i < (1 << n); i++) {
        sort(dp[i].begin(),dp[i].end());
        int p = 0;
        for (j = 0; j < dp[i].size(); j++) {
            if ((p > 0) && (dp[i][j].first == dp[i][p-1].first)) dp[i][p-1].second += dp[i][j].second;
            else dp[i][p++] = dp[i][j];
        }
        for (j = 0; j < p; j++) {
            int u = dp[i][j].first;
            for (k = 0; k < n; k++) {
                if (u & (1 << k)) {
                    u ^= (1 << k);
                    dp[i | (1 << k)].pb(mp(u | (adjMat[k] & (~i)),dp[i][j].second));
                }
            }
        }
        if (i < (1 << n)-1) dp[i].clear();
    }
    printf("%lld\n",(dp[(1 << n)-1][0].second*m/2) % MOD);

    return 0;
}