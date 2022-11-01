#include<bits/stdc++.h>
using namespace std;

int n,k;
char s[205],ta,tb;
int dp[205][205][205];//index ops ta_occ : pairs

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    cin>>s+1;
    cin>>ta>>tb;
    if(ta==tb){
        int occ=0;
        for(int i=1;i<=n;i++)occ+=s[i]==ta;
        occ=min(n,occ+k);
        cout<<occ*(occ-1)/2<<endl;
        return 0;
    }
    memset(dp,0x80,sizeof(dp));
    dp[0][0][0]=0;
    for(int i=1;i<=n;i++){//index
        for(int j=0;j<=k;j++){//ops
            for(int l=0;l<=i;l++){//ta_occ
                if(j&&l)dp[i][j][l]=max(dp[i][j][l],dp[i-1][j-1][l-1]);//change to ta
                if(j)dp[i][j][l]=max(dp[i][j][l],dp[i-1][j-1][l]+l);//change to tb
                dp[i][j][l]=max(dp[i][j][l],dp[i-1][j][l-(s[i]==ta)]+(s[i]==tb)*l);//do nothing
            }
        }
    }
    cout<<*max_element(dp[n][k],dp[n][k]+n+1)<<endl;

    return 0;
}