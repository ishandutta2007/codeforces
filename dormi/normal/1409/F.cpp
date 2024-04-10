#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
int dp[201][201][201];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    string s,t;
    cin>>s>>t;
    for(int i=0;i<=200;i++)for(int j=0;j<=200;j++)for(int l=0;l<=200;l++)dp[i][j][l]=INT_MIN;
    dp[0][0][0]=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=min(i,k);j++){
            for(int l=0;l<=i;l++){
                if(l-(s[i-1]==t[0])>=0)dp[i][j][l]=max(dp[i][j][l],dp[i-1][j][l-(s[i-1]==t[0])]+(s[i-1]==t[1]?l-(s[i-1]==t[0]):0));
                if(l-1>=0&j-1>=0)dp[i][j][l]=max(dp[i][j][l],dp[i-1][j-1][l-1]+(t[0]==t[1]?l-1:0));
                if(l-(t[1]==t[0])>=0&&j-1>=0)dp[i][j][l]=max(dp[i][j][l],dp[i-1][j-1][l-(t[1]==t[0])]+(l-(t[1]==t[0])));
            }
        }
    }
    int ans=0;
    for(int j=0;j<=k;j++)for(int l=0;l<=200;l++)ans=max(ans,dp[n][j][l]);
    printf("%d\n",ans);
    return 0;
}