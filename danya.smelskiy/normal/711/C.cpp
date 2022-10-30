#include <bits/stdc++.h>
using namespace std;

int n,m,k;
long long c[105];
long long a[105][105];
long long dp[105][105][105];
bool used[105][105][105];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>k;
    for (int i=1;i<=n;++i)
        cin>>c[i];
    for (int i=1;i<=n;++i)
        for (int j=1;j<=m;++j)
        cin>>a[i][j];
    if (c[1]==0) {
        for (int i=1;i<=m;++i){
            used[1][1][i]=true;
            dp[1][1][i]=a[1][i];
        }
    } else {
        used[1][1][c[1]]=true;
    }
    for (int i=2;i<=n;++i){
        if (c[i]==0){
        for (int j=1;j<=k;++j)
            for (int last=1;last<=m;++last){
                for (int z=1;z<=m;++z) if (z!=last && used[i-1][j-1][z]==true){
                    if (used[i][j][last]==false) {
                        used[i][j][last]=true;
                        dp[i][j][last]=dp[i-1][j-1][z]+a[i][last];
                    } else {
                        dp[i][j][last]=min(dp[i-1][j-1][z]+a[i][last],dp[i][j][last]);
                    }
                }
                if (used[i-1][j][last]) {
                    if (used[i][j][last]) {
                        dp[i][j][last]=min(dp[i][j][last],dp[i-1][j][last]+a[i][last]);
                    } else {
                        used[i][j][last]=true;
                        dp[i][j][last]=dp[i-1][j][last]+a[i][last];
                    }
                }
            }
        } else {
            for (int j=1;j<=k;++j){
                for (int z=1;z<=m;++z) if (z!=c[i] && used[i-1][j-1][z]){
                        if (used[i][j][c[i]]) {
                            dp[i][j][c[i]]=min(dp[i][j][c[i]],dp[i-1][j-1][z]);
                        } else {
                            used[i][j][c[i]]=true;
                            dp[i][j][c[i]]=dp[i-1][j-1][z];
                        }
                }
                if (used[i-1][j][c[i]]) {
                    if (used[i][j][c[i]]) {
                        dp[i][j][c[i]]=min(dp[i][j][c[i]],dp[i-1][j][c[i]]);
                    } else {
                        used[i][j][c[i]]=true;
                        dp[i][j][c[i]]=dp[i-1][j][c[i]];
                    }
                }
            }
        }
    }
    bool t=false;
    int r=-1;
    for (int i=1;i<=m;++i)
    if (used[n][k][i]) {
        if (t==false) {
            t=true;
            r=i;
        } else if (dp[n][k][i]<dp[n][k][r]) r=i;
    }
    if (t==false) cout<<"-1";
    else cout<<dp[n][k][r];
}