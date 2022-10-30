#include <bits/stdc++.h>
using namespace std;

int dp[150000],a[150000];
long long n,number,ans=100000000000,m;
int main(){
    cin>>n>>m;
    for (int i=1;i<=n;++i){
        cin>>a[i];
        if (i<=m) dp[i]=a[i]+dp[i-1];
        else dp[i]=a[i]+dp[i-1]-a[i-m];
        if (dp[i]<ans && i>=m) { ans=dp[i]; number=i-m+1;}
    }
    cout<<number;
}