#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod=998244353;

int n,a[505],f[505][505];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        char op;
        cin>>op;
        if(op=='+')cin>>a[i];
    }
    int ans=0;
    for(int k=1;k<=n;k++){
        memset(f,0,sizeof(f));
        f[0][0]=1;
        for(int i=1;i<k;i++){
            if(!a[i]){
                f[i][0]=(f[i-1][1]+f[i-1][0]*2%mod)%mod;
                for(int j=1;j<=n;j++){
                    f[i][j]=(f[i-1][j+1]+f[i-1][j])%mod;
                }
            }else if(a[i]<=a[k]){
                f[i][0]=f[i-1][0];
                for(int j=1;j<=n;j++){
                    f[i][j]=(f[i-1][j-1]+f[i-1][j])%mod;
                }
            }else{
                for(int j=0;j<=n;j++){
                    f[i][j]=2*f[i-1][j]%mod;
                }
            }
        }
        for(int j=1;j<=n;j++){
            f[k][j]=f[k-1][j-1];
        }
        for(int i=k+1;i<=n;i++){
            if(!a[i]){
                for(int j=1;j<=n;j++){
                    f[i][j]=(f[i-1][j+1]+f[i-1][j])%mod;
                }
            }else if(a[i]<a[k]){
                f[i][1]=f[i-1][1];
                for(int j=2;j<=n;j++){
                    f[i][j]=(f[i-1][j-1]+f[i-1][j])%mod;
                }
            }else{
                for(int j=1;j<=n;j++){
                    f[i][j]=2*f[i-1][j]%mod;
                }
            }
        }
        for(int i=1;i<=n;i++)ans=(ans+(ll)f[n][i]*a[k])%mod;
    }
    cout<<ans;

    return 0;
}