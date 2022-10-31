#include <bits/stdc++.h>
using namespace std;
const int md=1e9+7;

int n;
int dp[2][20005];
int z;
int ans;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    int x=0,y=1;
    dp[x][10000]=1;
    for (int i=1;i<=n;++i){
        swap(x,y);
        cin>>z;
        for (int j=0;j<=20000;++j){
            dp[x][j]=0;
            if (j>=z) dp[x][j]=dp[y][j-z];
            if (j+z<=20000) dp[x][j]=(dp[x][j]+dp[y][j+z])%md;
        }
        ans=(ans+dp[x][10000])%md;
        dp[x][10000]=(dp[x][10000]+1)%md;
    }
    cout<<ans;
}