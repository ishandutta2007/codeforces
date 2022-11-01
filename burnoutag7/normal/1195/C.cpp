#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
int a[100005][2];
ll dp[100005][2];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i][0];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i][1];
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<2;j++){
            dp[i][j]=max(dp[i-1][j],dp[i-1][j^1]+a[i][j]);
        }
    }
    cout<<max(dp[n][0],dp[n][1])<<endl;

    return 0;
}