#include <bits/stdc++.h>
using namespace std;


int n,k;
long double f[100],s[100],p[100];
long double dp[100][50005];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    for (int i=1;i<=n;++i) {
        cin>>f[i]>>s[i]>>p[i];
        p[i]/=100.0;
    }
    long double l=0;
    long double r=1e15;
    for (int z=1;z<=120;++z) {
        long double mid=(l+r)/2.0;
        for (int i=0;i<=n+1;++i)
            for (int j=0;j<=k;++j)
                dp[i][j]=0;
        for (int i=n;i>0;--i) {
            for (int j=0;j<=k;++j) {
                dp[i][j]=mid;
                if (j+(int)f[i]>(int)k) continue;
                long double res=0;
                res=(f[i]+dp[i+1][j+(int)f[i]])*p[i];
                if (j+(int)s[i]<=(int)k) res+=(s[i]+dp[i+1][j+(int)s[i]])*(1-p[i]);
                else res+=(s[i]+mid)*(1-p[i]);
                dp[i][j]=min(res,mid);
            }
        }
        if (dp[1][0]<(long double)mid) r=mid;
        else l=mid;
    }
    cout<<fixed<<setprecision(9)<<l;
}