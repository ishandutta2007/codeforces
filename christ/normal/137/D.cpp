#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using ll = long long;
const int MN = 502;
int dp[MN][MN];
int dp2[MN][MN];
string ree[MN][MN];
int par[MN][MN];
char s[MN], fin[MN];
int main() {
    scanf ("%s",s+1);
    int n = strlen(s+1),K;
    scanf ("%d",&K);
    for (int i = 1; i <= n; i++) dp2[i][i] = 0, ree[i][i] = s[i];
    for (int len = 1; len < n; len++) {
        for (int l = 1; l <= n-len; l++) {
            dp2[l][l+len] = dp2[l+1][l+len-1] + (s[l] != s[l+len]);
            ree[l][l+len] = s[l] + ree[l+1][l+len-1] + s[l];
        }
    }
    memset(dp,0x3f,sizeof dp); dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= K; j++) {
            for (int k = i; k >= 1; k--) if (dp[k-1][j-1] + dp2[k][i] < dp[i][j]){
                dp[i][j] = dp[k-1][j-1]+dp2[k][i];
                par[i][j] = k-1;
            }
        }
    }
    int mn = INT_MAX, cur = n, pal = -1;
    for (int i = 1; i <= K; i++) if (dp[n][i] < mn) {
        mn = dp[n][i];
        pal = i;
    } //
    int ind = 0;
    printf ("%d\n",mn);
    while (pal) {
        for (auto &c : ree[par[cur][pal]+1][cur]) fin[++ind] = c;
        cur = par[cur][pal];
        --pal;
        if (pal) fin[++ind] = '+';
    }
    while (ind) putchar(fin[ind--]);
    putchar(10);
    return 0;
}