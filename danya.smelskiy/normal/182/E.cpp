#include <bits/stdc++.h>
using namespace std;
const long long md=1e9+7;

int n,m;
int x[500],y[500];
long long dp[3005][205];
int rev[205];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;++i) {
        cin>>x[i]>>y[i];
    }
    int nn=n;
    for (int i=1;i<=nn;++i) {
        if (x[i]!=y[i]) {
            ++n;
            x[n]=y[i];
            y[n]=x[i];
            rev[n]=i;
            rev[i]=n;
        }
    }
    for (int i=1;i<=n;++i) {
        if (x[i]<=m) dp[x[i]][i]=1;
    }
    for (int i=1;i<=m;++i) {
        for (int j=1;j<=n;++j) if (x[j]<=i){
            for (int k=1;k<=n;++k)
            if (y[k]==x[j] && k!=j && rev[j]!=k && dp[i-x[j]][k]) {
                dp[i][j]=(dp[i][j]+dp[i-x[j]][k])%md;
            }
        }
    }
    long long ans=0;
    for (int i=1;i<=n;++i)
        ans=(ans+dp[m][i])%md;
    cout<<ans;
}