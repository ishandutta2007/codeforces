#include<bits/stdc++.h>
using namespace std;

int n,m;
int lb[105][105],rb[105][105];
int dp[105][105];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int k,clb,crb;
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>clb>>crb;
            for(int it=clb;it<=crb;it++){
                lb[i][it]=clb;
                rb[i][it]=crb;
            }
        }
    }
    for(int l=m;l>=1;l--){
        for(int r=l;r<=m;r++){
            for(int k=l;k<=r;k++){
                int cur=0;
                for(int i=1;i<=n;i++){
                    cur+=lb[i][k]>=l&&rb[i][k]<=r;
                }
                dp[l][r]=max(dp[l][r],dp[l][k-1]+cur*cur+dp[k+1][r]);
            }
        }
    }
    cout<<dp[1][m]<<endl;

    return 0;
}