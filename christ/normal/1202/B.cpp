#include <bits/stdc++.h>
using namespace std;
char a[2000005];
int diffs[20];
int prepro[11][11][11];
int ans[11][11];
int dp[1001];
int main() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            memset(dp,0x3f,sizeof dp);
            dp[0] = 0;
            for (int l = 1; l <= 1000; l++) {
                if (l >= i) dp[l] = min(dp[l],dp[l-i]+1);
                if (l >= j) dp[l] = min(dp[l],dp[l-j]+1);
            }
            for (int k = 0; k < 10; k++) {
                prepro[i][j][k] = INT_MAX;
                for (int cur = (k==0&&i!=0&&j!=0)?10:k; cur <= 1000; cur += 10) if (dp[cur] < 100000) prepro[i][j][k] = min(prepro[i][j][k],dp[cur]);
            }
        }
    }
    scanf ("%s",a); int len = strlen(a);
    for (int i = 1; i < len; i++) {
        int o = a[i-1]-'0', t = a[i] - '0';
        if (t < o) {diffs[t+10-o]++;}
        else {diffs[t-o]++;}
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            int ret = 0;
            for (int k = 0; k < 10; k++) if (diffs[k]) {
                if (prepro[i][j][k] > 100000) {printf (" -1 "); goto fail;}
                ret += max(prepro[i][j][k]-1,0) * diffs[k];
            }
            printf ("%d ",ret);
            fail:;
        }
        printf ("\n");
    }
    return 0;
}