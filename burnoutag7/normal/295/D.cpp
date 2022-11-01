#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod=1e9+7;

int n,m,f[2005][2005],g[2005][2005],pre[2005][2005],pp[2005][2005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i=2;i<=m;i++){
        f[1][i]=1;
        g[1][i]=(g[1][i-1]+1)%mod;
    }
    for(int i=2;i<=n+1;i++){
        int sum=0;
        for(int j=2;j<=m;j++){
            sum=(sum+g[i-1][j])%mod;
            f[i][j]=sum;
            g[i][j]=(g[i][j-1]+sum)%mod;
        }
    }
    for(int j=2;j<=m;j++){
        for(int i=1;i<=n;i++){
            pre[i][j]=(pre[i-1][j]+f[i][j])%mod;
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        int ps=0,sum=0;
        for(int j=2;j<=m;j++){
            ps=(ps+pre[n-i][j])%mod;
            sum=(sum+ps)%mod;
            if(i==n||j==2){
                ans=(ans+(ll)pre[i][j]*(m-j+1))%mod;
            }else{
                ans=(ans+(ll)pre[i][j]*(sum-pre[n-i][j]+1+mod)%mod*(m-j+1))%mod;
            }
        }
    }
    cout<<ans;

    return 0;
}