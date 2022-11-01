#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod=1000000007;

int n,m;
ll dp[11][1005][1005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            dp[1][i][j]=1;
        }
    }
    for(int k=2;k<=m;k++){
        for(int i=1;i<=n;i++){
            for(int j=n;j>=i;j--){
                dp[k][i][j]+=dp[k-1][i][j];
                dp[k][i][j]+=dp[k][i-1][j];
                dp[k][i][j]+=dp[k][i][j+1];
                dp[k][i][j]-=dp[k][i-1][j+1];
                dp[k][i][j]=(dp[k][i][j]%mod+mod)%mod;
            }
        }
    }
    ll ans=0;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            ans+=dp[m][i][j];
        }
    }
    cout<<ans%mod<<endl;

    return 0;
}