#include<bits/stdc++.h>
using namespace std;

int n,a[505],f[505][505][505];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    memset(f,-1,sizeof(f));
    f[0][0][0]=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            for(int k=0;k<=n;k++)if(f[i][j][k]!=-1){
                f[i+1][j][k]=max(f[i+1][j][k],f[i][j][k]+a[k]);
                if(k<=i)f[i+1][j+1][i+1]=max(f[i+1][j+1][i+1],f[i][j][k]+a[i+1]);
                else f[i+1][j+1][0]=max(f[i+1][j+1][0],f[i][j][k]);
                for(int l=i+2;l<=n&&l-i-1<=j+1;l++){
                    f[l-1][j+1-(l-i-1)][l]=max(f[l-1][j+1-(l-i-1)][l],f[i][j][k]+(l-i-1)*a[l]);
                }
            }
        }
    }
    int ans=0;
    for(int i=0;i<=n;i++)for(int j=0;j<=n;j++){
        ans=max(ans,f[n][i][j]);
    }
    cout<<ans<<'\n';

    return 0;
}