#include <bits/stdc++.h>
using namespace std;
int n;
string ss2;
int a[100005];
string s[100005];
long long dp[1000005][3];
string q[100005];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    for (int i=1;i<=n;++i)
        cin>>s[i];
    dp[1][1]=0;
    dp[1][2]=a[1];
    string ss=s[1];
    reverse(ss.begin(),ss.end());
    q[1]=ss;
    for (int i=2;i<=n;++i){
        dp[i][1]=-1;
        dp[i][2]=-1;
        ss2=s[i];
        if (ss2>=s[i-1] && dp[i-1][1]!=-1) dp[i][1]=dp[i-1][1];
        if (ss2>=q[i-1] && dp[i-1][2]!=-1){
            if (dp[i][1]==-1) dp[i][1]=dp[i-1][2];
            else dp[i][1]=min(dp[i][1],dp[i-1][2]);
        }
        reverse(ss2.begin(),ss2.end());
        if (ss2>=s[i-1] && dp[i-1][1]!=-1) dp[i][2]=dp[i-1][1]+a[i];
        if (ss2>=q[i-1] && dp[i-1][2]!=-1){
            if (dp[i][2]==-1) dp[i][2]=dp[i-1][2]+a[i];
            else dp[i][2]=min(dp[i][2],dp[i-1][2]+a[i]);
        }
        if (dp[i][1]==-1 && dp[i][2]==-1){
            cout<<"-1";
            return 0;
        }
        q[i]=ss2;
    }
    if (dp[n][1]==-1) cout<<dp[n][2];
    else if (dp[n][2]==-1) cout<<dp[n][1];
    else cout<<min(dp[n][1],dp[n][2]);
}