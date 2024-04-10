#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
lli dp[2][203][1003];
lli arr[201];
lli mod=1e9+7;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    int fg=1;
    dp[0][0][0]=1;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    sort(arr+1,arr+n+1);
    for(int i=1;i<=n;i++){
        for(int j=0;j<=i;j++){
            for(int l=0;l<=k;l++){
                dp[fg][j][l]=0;
                int val=l-j*(arr[i]-arr[i-1]);
                if(j&&val+(arr[i]-arr[i-1])>=0)dp[fg][j][l] = (dp[fg][j][l] + dp[!fg][j - 1][val+(arr[i]-arr[i-1])])%mod;//make group
                if(val>=0) {
                    dp[fg][j][l] = (dp[fg][j][l] + (dp[!fg][j][val]*j%mod))%mod;//join group
                    if(val-(arr[i]-arr[i-1])>=0)dp[fg][j][l] = (dp[fg][j][l] + (dp[!fg][j+1][val-(arr[i]-arr[i-1])]*(j+1)%mod))%mod;//join and close group
                    dp[fg][j][l] = (dp[fg][j][l] + dp[!fg][j][val])%mod;//make and close group
                }
            }
        }
        fg^=1;
    }
    lli ans=0;
    for(int i=0;i<=k;i++){
        ans=(ans+dp[!fg][0][i])%mod;
    }
    printf("%lli\n",ans);
    return 0;
}