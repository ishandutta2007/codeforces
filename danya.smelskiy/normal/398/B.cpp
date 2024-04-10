#include <bits/stdc++.h>
using namespace std;
long double n,m;
int x,y;
bool used1[2005];
bool used2[2005];
long double dp[2005][2005];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=m;++i) {
        cin>>x>>y;
        used1[x]=true;
        used2[y]=true;
    }
    int kol1=0,kol2=0;
    for (int i=1;i<=n;++i) {
        if (used1[i]==false) ++kol1;
        if (used2[i]==false) ++kol2;
    }
    for (int i=1;i<=n;++i)
        dp[i][0]=dp[i-1][0]+(long double)n/i;
    for (int i=1;i<=n;++i)
        dp[0][i]=dp[0][i-1]+(long double)n/i;
    for (long double i=1;i<=kol1;++i)
    for (long double j=1;j<=kol2;++j){
        dp[(int)i][(int)j]=(i*j*dp[(int)i-1][(int)j-1]+(n-i)*j*dp[(int)i][(int)j-1]+(n-j)*i*dp[(int)i-1][(int)j])/(n*n);
        dp[(int)i][(int)j]++;
        dp[(int)i][(int)j]/=(long double)1-(n-i)*(n-j)/(n*n);
    }
    cout<<fixed<<setprecision(6)<<dp[kol1][kol2];
}