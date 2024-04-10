#include<bits/stdc++.h>
using namespace std;

int n,m,k;
int dp[55][20005];
int a[55][20005],prefix_sum[55][20005];
int pre[20005],suf[20005];

inline void precalc(int *d){
    for(int i=1;i<=m-k+1;i++){
        pre[i]=max(pre[i-1],d[i]);
    }
    for(int i=m-k+1;i>=1;i--){
        suf[i]=max(suf[i+1],d[i]);
    }
}

inline int animals(int x1,int y1,int x2,int y2){
    return prefix_sum[x2][y2]+prefix_sum[x1-1][y1-1]-prefix_sum[x2][y1-1]-prefix_sum[x1-1][y2];
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
            prefix_sum[i][j]=prefix_sum[i-1][j]+prefix_sum[i][j-1]-prefix_sum[i-1][j-1]+a[i][j];
        }
    }
    for(int j=1;j<=m;j++){
        prefix_sum[n+1][j]=prefix_sum[n][j]+prefix_sum[n+1][j-1]-prefix_sum[n][j-1];
    }
    for(int i=1;i<=n;i++){
        precalc(dp[i-1]);
        for(int j=1;j+k-1<=m;j++){
            int cov=animals(i,j,i+1,j+k-1);
            dp[i][j]=max(j-k<0?0:pre[j-k],suf[j+k])+cov;
            for(int l=max(1,j-k+1);l<=j+k-1&&l+k-1<=m;l++){
                dp[i][j]=max(dp[i][j],dp[i-1][l]+cov-animals(i,max(j,l),i,min(j,l)+k-1));
            }
        }
    }
    cout<<*max_element(dp[n]+1,dp[n]+1+m-k+1)<<endl;

    return 0;
}