// https://codeforces.com/problemset/problem/1093/F
#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005
#define MAXK 105
#define MOD 998244353
long long dp[MAXN][MAXK] = {0};
int num[MAXN][MAXK] = {0};
long long sum[MAXN] = {0};
int arr[MAXN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k, len; cin >> n >> k >> len;
    arr[0] = 0;
    for(int i = 0; i<n; i++) cin >> arr[i+1];
    for(int i = 1; i<=k; i++){
        for(int j = 1; j<=n; j++) num[j][i] = num[j-1][i]+(arr[j] == i || arr[j] == -1)-(arr[max(j-len, 0)] == i || arr[max(j-len, 0)] == -1);
    }
    sum[0] = 1;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=k; j++){
            if(arr[i] != -1 && arr[i] != j) continue;
            dp[i][j] = sum[i-1];
            if(num[i][j] == len) dp[i][j] -= sum[i-len]-dp[i-len][j];
            dp[i][j] %= MOD;
            if(dp[i][j] < 0) dp[i][j] += MOD;
            sum[i] += dp[i][j]; sum[i] %= MOD;
        }
    }
    // cout << num[3][1] << endl;
    cout << sum[n] << endl;
}