#include <bits/stdc++.h>
using namespace std;

long long n,m,k,md,dp1[505][505],dp2[505][505],a[505];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>k>>md;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    dp1[0][0]=1;
    // dp [ i ] [ j ] - i ( lastline ) ; j - ( fine )
    for (int i=1;i<=n;++i){
        for (int j=0;j<=m;++j){
            for (int z=0;z<=k;++z){
                dp2[j][z]=dp1[j][z];
                if (z>=a[i] && j) dp2[j][z]=(dp2[j][z]+dp2[j-1][z-a[i]])%md;
            }
        }
        for (int j=0;j<=m;++j){
            for (int z=0;z<=k;++z)
                dp1[j][z]=dp2[j][z];
        }
    }
    long long ans=0;
    for (int i=0;i<=k;++i)
        ans=(ans+dp1[m][i])%md;
    cout<<ans;
}