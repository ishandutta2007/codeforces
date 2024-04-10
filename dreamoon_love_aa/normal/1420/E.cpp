#include<bits/stdc++.h>
#define SZ(X) ((int)(X).size())
#define MP make_pair
#define PB emplace_back
using namespace std;
const int MAX_N = 81;
const int MAX_V = MAX_N * (MAX_N - 1) /2 ;
int a[MAX_N];
int sum[MAX_N];
int dp[2][MAX_N][MAX_N][MAX_V];
int cnt[MAX_N];
void update(int &x,int v) {
    if(x < v) {
        x = v;
    }
}
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    int zero_cnt = 0;
    for(int i = 1; i <= n; i++) {
        if(a[i] == 0) {
            zero_cnt++;
        }
        else {
            cnt[zero_cnt]++;
        }
    }
    if(zero_cnt == 0 || zero_cnt == n) {
        for(int i = 0; i <= n * (n - 1) / 2; i++) {
            printf("0");
            if(i < n * (n - 1) / 2) {
                printf(" ");
            } else {
                printf("\n");
            }
        }
        return 0;
    }
    for(int i = 0; i <= zero_cnt; i++) {
        sum[i] = cnt[i];
        if(i) {
            sum[i] += sum[i - 1];
        }
    }
    int now = 0;
    int nxt = 1;
    int one_cnt = n - zero_cnt;
    memset(dp,-1,sizeof(dp));
    for(int i = 0; i <= one_cnt; i++) {
        dp[now][i][0][abs(i-sum[0])] = 0;
    }
    int max_v = n * (n - 1) / 2;
    for(int i = 1; i <= zero_cnt; i++) {
        memset(dp[nxt], -1, sizeof(dp[nxt]));
        for(int j = 0; j <= one_cnt; j++) {
            for(int k = j; k <= one_cnt; k++) {
                for(int lt_pos = 0; lt_pos < i; lt_pos++) {
                    for(int v = 0; v <= max_v; v++) {
                        if(dp[now][j][lt_pos][v] == -1) {
                            continue;
                        }
                        if(k == j) {
                            update(dp[nxt][k][lt_pos][v + abs(k - sum[i])], dp[now][j][lt_pos][v]);
                        } else{
                            update(dp[nxt][k][i][v + abs(k - sum[i])], dp[now][j][lt_pos][v] + (zero_cnt - i) * (i - lt_pos));
                        }
                    }
                }
            }
        }
        swap(now,nxt);
    }
    int ma = 0;
    for(int i = 0; i <= max_v; i++) {
        for(int j = 0; j <= zero_cnt; j++) {
            ma = max(ma, dp[now][one_cnt][j][i]);
        }
        printf("%d", ma);
        if(i < max_v) {
            printf(" ");
        } else {
            printf("\n");
        }
    }
    return 0;
}