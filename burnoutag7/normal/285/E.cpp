#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod=1e9+7;

int fact[1005],inv[1005];

inline int chs(const int &n,const int &r){
    return (ll)fact[n]*inv[n-r]%mod*inv[r]%mod;
}

int n,k;
int dp[1005][1005][4],suf[1005];//index good_chosen if_values_i_and_i+1_are_available(lowbit2highbit)

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    fact[0]=inv[0]=inv[1]=1;
    for(int i=1;i<=1000;i++)fact[i]=(ll)fact[i-1]*i%mod;
    for(int i=2;i<=1000;i++)inv[i]=(ll)(mod-mod/i)*inv[mod%i]%mod;
    for(int i=1;i<=1000;i++)inv[i]=(ll)inv[i-1]*inv[i]%mod;

    cin>>n>>k;
    dp[0][0][2]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=i;j++){
            for(int ps=0;ps<4;ps++){
                if((ps&1)&&j)dp[i][j][ps>>1|2]=(dp[i][j][ps>>1|2]+dp[i-1][j-1][ps])%mod;
                if(i<n&&j)dp[i][j][ps>>1]=(dp[i][j][ps>>1]+dp[i-1][j-1][ps])%mod;
                dp[i][j][ps>>1|2]=(dp[i][j][ps>>1|2]+dp[i-1][j][ps])%mod;
            }
        }
    }
    for(int i=0;i<=n;i++){
        for(int s=0;s<4;s++)suf[i]=(suf[i]+dp[n][i][s])%mod;
        for(int j=1;j<=n-i;j++)suf[i]=(ll)suf[i]*j%mod;
    }
    for(int i=n-1;i>=0;i--){
        for(int j=i+1;j<=n;j++){
            suf[i]=(suf[i]-(ll)suf[j]*chs(j,i)%mod+mod)%mod;
        }
    }
    cout<<suf[k]<<endl;

    return 0;
}