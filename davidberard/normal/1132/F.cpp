#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

int n;

const int NMAX = 550;
char s[NMAX];
int dp[NMAX][NMAX];
int of[30];
int nxt[NMAX][30];
const int INF = 0x3f3f3f3f;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    memset(dp, INF, sizeof dp);
    cin >> n;
    cin >> (s+1);
    for(int i=1;i<=n;++i) {
        for(int j=0;j<i;++j) {
            dp[i][j] = 0;
        }
    }
    for(int i=1;i<=n;++i) s[i] -= 'a';
    for(int i=0;i<30;++i) of[i] = NMAX;
    for(int i=n;i>=0;--i) {
        for(int j=0;j<30;++j) {
            nxt[i][j] = of[j];
        }
        of[s[i]] = i;
    }
    for(int i=1;i<=n;++i) dp[i][i] = 1;
    for(int len=1;len<n;++len) {
        for(int i=1;i+len<=n;++i) {
            int j = i+len;
            for(int k=i;k<j;++k) {
                dp[i][j] = min(dp[i][j], dp[i][k]+dp[k+1][j]-(s[k] == s[j]));
            }
            //dp[i][j] = dp[nxt[i][s[j]]+1][j] + dp[i][nxt[i][s[j]]] - (nxt[i][s[j]] != j);
        }
    }
    cout << dp[1][n] << endl;
    return 0;
}