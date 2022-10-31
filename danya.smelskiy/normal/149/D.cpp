#include <bits/stdc++.h>
using namespace std;
const long long md=1e9+7;

bool used[1000][1000];
long long dp[1000][1000][3][3];
string s;
int r[1000];
int n;
int q[1000];
void solve (int l,int rr){
    if (used[l][rr]) return;
    used[l][rr]=true;
    if (l==rr-1) {
        dp[l][rr][0][1]=1;
        dp[l][rr][0][2]=1;
        dp[l][rr][1][0]=1;
        dp[l][rr][2][0]=1;
        return;
    }
    int ll=l+1;
    int dp1[3];
    dp1[0]=1;
    dp1[1]=0;
    dp1[2]=0;
    while (ll<rr) {
        solve(ll,r[ll]);
        long long dp2[3];
        dp2[0]=0,dp2[1]=0,dp2[2]=0;
        for (int i=0;i<3;++i)
            for (int j=0;j<3;++j)
                for (int k=0;k<3;++k)
                    if (j!=k && ((!i && !j) || (i!=j))) dp2[k]=(dp2[k]+dp1[i]*dp[ll][r[ll]][j][k]%md)%md;
        dp1[0]=dp2[0];
        dp1[1]=dp2[1];
        dp1[2]=dp2[2];
        ll=r[ll]+1;
    }
    dp[l][rr][0][1]=(dp1[0]+dp1[2])%md;
    dp[l][rr][0][2]=(dp1[1]+dp1[0])%md;
    /*
    dp1[0]=0;
    dp1[1]=1;
    dp1[2]=0;
    while (ll<rr) {
        long long dp2[3];
        dp2[0]=0,dp2[1]=0,dp2[2]=0;
        for (int i=0;i<3;++i)
            for (int j=0;j<3;++j)
                for (int k=0;k<3;++k)
                    if (j!=k && ((!i && !j) || (i!=j))) dp2[k]=(dp2[k]+dp1[i]*dp[ll][r[ll]][j][k]%md)%md;
        dp1[0]=dp2[0];
        dp1[1]=dp2[1];
        dp1[2]=dp2[2];
        ll=r[ll]+1;
    }
    dp[l][rr][1][0]=(dp1[1]+dp1[2]+dp1[0])%md;
    dp1[0]=0;
    dp1[1]=0;
    dp1[2]=1;
    while (ll<rr) {
        long long dp2[3];
        dp2[0]=0,dp2[1]=0,dp2[2]=0;
        for (int i=0;i<3;++i)
            for (int j=0;j<3;++j)
                for (int k=0;k<3;++k)
                    if (j!=k && ((!i && !j) || (i!=j))) dp2[k]=(dp2[k]+dp1[i]*dp[ll][r[ll]][j][k]%md)%md;
        dp1[0]=dp2[0];
        dp1[1]=dp2[1];
        dp1[2]=dp2[2];
        ll=r[ll]+1;
    }
    dp[l][rr][2][0]=(dp1[1]+dp1[2]+dp1[0])%md;
    */
    dp[l][rr][1][0]=dp[l][rr][0][1];
    dp[l][rr][2][0]=dp[l][rr][0][2];
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    cin>>s;
    n=s.size();
    int sz=0;
    for (int i=1;i<=s.size();++i) {
        if (s[i-1]=='(') q[++sz]=i;
        else r[q[sz--]]=i;
    }
    for (int i=1;i<=n;++i)
        if (s[i-1]=='(') solve(i,r[i]);
    long long dp1[3];
    dp1[0]=0,dp1[1]=0,dp1[2]=0;
    int ll=1;
    dp1[0]=(dp[ll][r[ll]][1][0]+dp[ll][r[ll]][2][0])%md;
    dp1[1]=dp[ll][r[ll]][0][1];
    dp1[2]=dp[ll][r[ll]][0][2];
    ll=r[ll]+1;
    while (ll<=n) {
        long long dp2[3];
        dp2[0]=0,dp2[1]=0,dp2[2]=0;
        for (int i=0;i<=2;++i)
            for (int j=0;j<3;++j)
                for (int k=0;k<3;++k)
                    if (j!=k && ((!i && !j) || (i!=j))) dp2[k]=(dp2[k]+dp1[i]*dp[ll][r[ll]][j][k]%md)%md;
        dp1[0]=dp2[0];
        dp1[1]=dp2[1];
        dp1[2]=dp2[2];
        ll=r[ll]+1;
    }
    cout<<(dp1[0]+dp1[1]+dp1[2])%md;
}