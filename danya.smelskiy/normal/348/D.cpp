#include <bits/stdc++.h>
using namespace std;
const long long md=1e9+7;
int n,m;
string s[3005];
int dp[3005][3005];
inline long long solve(int x,int y,int xx,int yy){
    if (s[x][y]=='#') return 0;
    for (int i=1;i<=n;++i)
        for (int j=1;j<=m;++j)
            dp[i][j]=0;
    dp[x][y]=1;
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=m;++j) {
            if (i<n && s[i+1][j]=='.') {
                dp[i+1][j]=(dp[i+1][j]+dp[i][j]);
                if (dp[i+1][j]>=md) dp[i+1][j]-=md;
            }
            if (j<m && s[i][j+1]=='.') {
                dp[i][j+1]=(dp[i][j+1]+dp[i][j]);
                if (dp[i][j+1]>=md) dp[i][j+1]-=md;
            }
        }
    }
    return dp[xx][yy];
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;++i) {
        cin>>s[i];
        s[i]="."+s[i];
    }
    long long res;
    res=solve(2,1,n,m-1)*solve(1,2,n-1,m)-solve(2,1,n-1,m)*solve(1,2,n,m-1);
    res=(res%md+md)%md;
    cout<<res;
}