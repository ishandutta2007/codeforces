#include <bits/stdc++.h>
using namespace std;


int n,d,kol[30005];
bool dp[30005][602];
int ans;
int x;
int res[30005][602];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>d;
    for (int i=1;i<=n;++i) {
        cin>>x;
        ++kol[x];
    }
    dp[d][300]=true;
    res[d][300]=kol[d];
    ans=kol[d];
    for (int i=d+1;i<=30000;++i) {
        for (int j=0;j<=600;++j) {
            int k=j+d-300;
            if (k<=0) continue;
            if (k>i) continue;
            if (dp[i-k][j]) {
                dp[i][j]=true;
                res[i][j]=res[i-k][j]+kol[i];
            }
            if (j && dp[i-k][j-1]) {
                dp[i][j]=true;
                res[i][j]=max(res[i][j],res[i-k][j-1]+kol[i]);
            }
            if (j<600 && dp[i-k][j+1]) {
                dp[i][j]=true;
                res[i][j]=max(res[i][j],res[i-k][j+1]+kol[i]);
            }
            if (dp[i][j]) ans=max(ans,res[i][j]);
        }
    }
    cout<<ans;
}