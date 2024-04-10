#include <bits/stdc++.h>
using namespace std;

int n,t;
double dp[5005][5005];
long double ans;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>t;
    dp[0][0]=1;
    for (int i=1;i<=n;++i) {
        long double x;
        int y;
        cin>>x>>y;
        x*=0.01;
        long double z=1;
        for (int j=1;j<=y;++j)
            z*=(1.-x);
        long double s=0;
        for (int j=0;j<=t;++j) {
            dp[i][j]=s*x;
            s=(s*(1.-x)+(j<t ? dp[i-1][j] : 0));
            if (j>=y) {
                s-=dp[i-1][j-y]*z;
                dp[i][j]+=dp[i-1][j-y]*z;
            }
        }
        ans+=s*(long double)(i-1);
    }
    for (int i=0;i<=n;++i){
        ans+=dp[i][t]*(long double)i;
    }
    for (int i=0;i<t;++i)
        ans+=dp[n][i]*(long double)n;
    cout<<fixed<<setprecision(6)<<ans;
}