#include <bits/stdc++.h>
using namespace std;
const long long md=1e9+7;
int n,k;
long long dp[2][55][55];
long long c[55][55];
int a,b;
int x,y;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    c[0][0]=1;
    for (int i=1;i<=n;++i)
        for (int j=0;j<=n;++j)
            c[i][j]=(c[i-1][j]+(j ? c[i-1][j-1] : 0))%md;
    if (k<50) {
        cout<<"-1"<<'\n'<<0;
        return 0;
    }
    for (int i=1;i<=n;++i) {
        cin>>x;
        if (x==50) ++a; else ++b;
    }
    if (b && k<100) {
        cout<<"-1"<<'\n'<<0;
        return 0;
    }
    x=0,y=1;
    dp[x][a][b]=1;
    for (int i=1;;++i) {
        swap(x,y);
        for (int j=0;j<=a;++j)
            for (int k=0;k<=b;++k)
                dp[x][j][k]=0;
        for (int j=0;j<=a;++j)
            for (int kk=0;kk<=b;++kk) if (dp[y][j][kk]) {
                for (int z=0;z<=j;++z) if (z*50<=k)
                    for (int zz=0;zz<=kk;++zz) if (z+zz && z*50+zz*100<=k) {
                        dp[x][a-j+z][b-kk+zz]=((dp[x][a-j+z][b-kk+zz])+(c[j][z]*c[kk][zz]*dp[y][j][kk])%md)%md;
                    }
            }
        if ((i&1) && dp[x][a][b]) {
            cout<<i<<'\n';
            cout<<dp[x][a][b];
            return 0;
        }
        bool t=false;
        for (int j=0;j<=a && !t;++j)
            for (int k=0;k<=b;++k)
        if (dp[y][j][k]==0 && dp[x][j][k]) {
            t=true;
            break;
        }
        if (i>1000) {
            cout<<"-1"<<'\n'<<0;
            return 0;
        }
    }
}