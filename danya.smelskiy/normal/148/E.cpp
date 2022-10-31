#include <bits/stdc++.h>
using namespace std;

int n,m;
int sz[101];
int a[101];
int dp[101][101];
int dp2[10005][2];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;++i) {
        cin>>sz[i];
        for (int j=1;j<=sz[i];++j)
            cin>>a[j];
        int sum1=0;
        a[0]=a[sz[i]+1]=0;
        for (int j=0;j<=sz[i];++j){
            sum1+=a[j];
            int sum2=0;
            for (int k=sz[i]+1;k>j;--k) {
                sum2+=a[k];
                dp[i][j+sz[i]-k+1]=max(dp[i][j+sz[i]-k+1],sum1+sum2);
            }
        }
    }
    int x=0,y=1;
    for (int i=1;i<=n;++i) {
        swap(x,y);
        for (int j=0;j<=m;++j)
            dp2[j][x]=dp2[j][y];
        for (int j=1;j<=sz[i];++j)
            for (int k=j;k<=m;++k)
                dp2[k][x]=max(dp2[k][x],dp2[k-j][y]+dp[i][j]);
    }
    cout<<dp2[m][x];
}