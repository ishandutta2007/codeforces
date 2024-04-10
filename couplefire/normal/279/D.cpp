#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define inf 168430090
int n;
int a[30], dp[1<<24];
 
int bits(int st){
    int ret = 0;
    while (st) st &= (st - 1), ret ++;
    return ret;
}
 
int dfs(int k, int st){
    if (dp[st] > -1) return dp[st];
    int ret = inf, now = (st - (1 << k)) | (1 << (k - 1));
    for (int i = 0; i < k; ++ i){
        for (int j = i; j < k; ++ j){
            if (a[i] + a[j] != a[k]) continue;
            ret = min(ret, max(bits(st), dfs(k - 1, now | (1 << i) | (1 << j))));
        }
    }
    dp[st] = ret;
    return ret;
}
 
int main(){
 
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
    }
    memset(dp, -1, sizeof(dp));
    dp[1] = 1;
    int ans = dfs(n - 1, (1 << (n - 1)));
    if (ans == inf) ans = -1;
    printf("%d\n", ans);
    return 0;
}