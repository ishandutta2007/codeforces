#include <bits/stdc++.h>
using namespace std;
const long long md=1e9+7;
int t,k;
long long dp[100005][5];
long long p[100005];
int x,y;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>t>>k;
    dp[0][0]=1;
    for (int i=1;i<=1e5;++i){
        dp[i][0]=dp[i-1][0];
        if (i>=k) {
            dp[i][0]+=dp[i-1][1];
            dp[i][1]+=dp[i-k][0];
            dp[i][1]%=md;
            dp[i][1]+=dp[i-k][1];
            dp[i][1]%=md;
        }
        dp[i][0]%=md;
    }
    for (int i=1;i<=1e5;++i){
        p[i]=p[i-1];
        p[i]=(p[i]+(dp[i][0]+dp[i][1])%md)%md;
    }
    for (int i=1;i<=t;++i){
        cin>>x>>y;
        if (p[y]-p[x-1]<0) cout<<p[y]-p[x-1]+md<<'\n';
        else
        cout<<p[y]-p[x-1]<<'\n';
    }
}