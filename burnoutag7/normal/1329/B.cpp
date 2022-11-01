#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[55][55];

ll solve(ll d,ll mod){
    ll ans=0;
    dp[0][0]=1;
    for(int i=1;(1ll<<(i-1))<=d;i++){
        for(int j=i;(1ll<<(j-1))<=d;j++){
            dp[i][j]=0;
            for(int k=i-1;k<j;k++){
                dp[i][j]=(dp[i][j]+dp[i-1][k])%mod;
            }
            dp[i][j]=dp[i][j]*(min(d+1,1ll<<j)-(1ll<<(j-1)))%mod;
            ans=(ans+dp[i][j])%mod;
        }
    }
    return ans;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--){
        ll dream,moon;
        cin>>dream>>moon;
        cout<<solve(dream,moon)<<endl;
    }

    return 0;
}