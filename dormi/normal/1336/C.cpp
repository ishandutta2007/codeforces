#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
lli dp[3001][3001];
lli mod=998244353;
string s,t;
lli go(int i, int j){
    if(dp[i][j]!=-1)return dp[i][j];
    dp[i][j]=0;
    if(i>=sz(t)||t[i]==s[j-i]){
        dp[i][j]=(dp[i][j]+go(i+1,j))%mod;
    }
    if(j>=sz(t)||t[j]==s[j-i]){
        dp[i][j]=(dp[i][j]+go(i,j-1))%mod;
    }
    return dp[i][j];
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>s>>t;
    for(int i=0;i<sz(s);i++)for(int j=0;j<sz(s);j++)dp[i][j]=-1;
    for(int i=0;i<sz(s);i++)if(i>=sz(t)||t[i]==s[0])dp[i][i]=2;
    lli ans=0;
    for(lli i=sz(t)-1;i<sz(s);i++)ans=(ans+go(0,i))%mod;
    printf("%lli\n",ans);
    return 0;
}