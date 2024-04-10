#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+100;
int a[maxn];
typedef long long ll;
ll dp[maxn];
int main(){
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        scanf("%d",a+i);
    }
    dp[0] = 1ll * a[0] * (n+1 - a[0]);
    for (int i=1;i<n;i++){
        if (a[i] == a[i-1]){
            dp[i] = dp[i-1];
        }else if (a[i] >a[i-1]){
            dp[i] = dp[i-1] + 1ll * (n + 1 - a[i]) * (a[i] - a[i-1]);
        }else{
            dp[i] = dp[i-1] + 1ll * a[i] * (a[i-1] - a[i]);
        }
    }
    cout<<dp[n-1]<<endl;
    return 0;
}