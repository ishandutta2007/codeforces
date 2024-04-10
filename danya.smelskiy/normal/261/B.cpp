#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[55];
long double ans;
long long dp[55][55][55];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    int sum=0;
    for (int i=1;i<=n;++i) { cin>>a[i]; sum+=a[i]; }
    cin>>m;
    if (sum<=m) {
        cout<<n;
        return 0;
    }
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=n;++j)
            for (int k=0;k<=n;++k)
                for (int z=0;z<=m;++z)
                    dp[j][k][z]=0;
        dp[0][0][0]=1;
        for (int j=1;j<=n;++j)
            for (int k=0;k<=n;++k)
                for (int z=0;z<=m;++z) {
                    dp[j][k][z]=dp[j-1][k][z];
                    if (k && j!=i && a[j]<=z) dp[j][k][z]+=dp[j-1][k-1][z-a[j]];
                }
        for (int j=1;j<=n;++j)
            for (int k=0;k<=m;++k){
                if (k+a[i]>m) {
                    long double res=j*dp[n][j][k];
                    int xx=j;
                    int yy=n-j-1;
                    if (xx<yy) swap(xx,yy);
                    for (int kk=xx+1;kk<=n;++kk)
                        res/=(long double)kk;
                    for (int kk=1;kk<=yy;++kk)
                        res=(res*(long double)(kk));
                    ans+=res;
                }
            }
    }
    cout<<fixed<<setprecision(6);
    cout<<ans;
}