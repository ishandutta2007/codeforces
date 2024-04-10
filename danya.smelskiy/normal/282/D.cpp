#include <bits/stdc++.h>
using namespace std;

int n;
int a[5];
int dp[305][305];
int dp1[305][305];
int dp2[305][305];
int dp3[305][305];
int dp4[305][305][305];
int dp5[305][305][305];
int x;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=0;i<n;++i)
        cin>>a[i];
    if (n==1) {
        cout<<(a[0] ? "BitLGM" : "BitAryo");
        return 0;
    }
    if (n==2) {
        for (int i=0;i<=a[0];++i)
        for (int j=0;j<=a[1];++j) if (i+j) {
            for (int k=1;k<=i && !dp[i][j];++k)
                dp[i][j]|=1-dp[i-k][j];
            for (int k=1;k<=j && !dp[i][j];++k)
                dp[i][j]|=1-dp[i][j-k];
            for (int k=1;k<=min(i,j);++k)
                dp[i][j]|=1-dp[i-k][j-k];
        }
        cout<<(dp[a[0]][a[1]] ? "BitLGM" : "BitAryo");
        return 0;
    }
    for (int i=0;i<=a[0];++i)
        for (int j=0;j<=a[1];++j)
            for (int k=0;k<=a[2];++k){
                dp1[i][j]=1e9;
                dp2[j][k]=1e9;
                dp3[i][k]=1e9;
                x=min(i,min(j,k));
                dp4[i-x][j-x][k-x]=1e9;
            }
    dp1[0][0]=dp2[0][0]=dp3[0][0]=dp4[0][0][0]=0;
    for (int i=0;i<=a[0];++i)
        for (int j=0;j<=a[1];++j)
    for (int k=0;k<=a[2];++k) if (i+j+k) {
        if (dp1[i][j]<k) dp5[i][j][k]=true;
        if (dp2[j][k]<i) dp5[i][j][k]=true;
        if (dp3[i][k]<j) dp5[i][j][k]=true;
        int x=min(i,min(j,k));
        if (dp4[i-x][j-x][k-x]<x) dp5[i][j][k]=true;
        if (!dp5[i][j][k]) {
            dp4[i-x][j-x][k-x]=min(dp4[i-x][j-x][k-x],x);
            dp1[i][j]=min(dp1[i][j],k);
            dp2[j][k]=min(dp1[j][k],i);
            dp3[i][k]=min(dp1[i][k],j);
        }
    }
    cout<<(dp5[a[0]][a[1]][a[2]] ? "BitLGM" : "BitAryo");
}