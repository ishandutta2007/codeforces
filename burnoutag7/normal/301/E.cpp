#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod=1e9+7;

int C[105][105];

int n,m,K,nf[105][105][105],f[105][105][105],ans;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>K;
    n++;

    C[0][0]=1;
    for(int i=1;i<=100;i++){
        C[i][0]=1;
        for(int j=1;j<=i;j++){
            C[i][j]=min(C[i-1][j]+C[i-1][j-1],K+1);
        }
    }

    nf[0][1][1]=1;
    for(int i=0;i<=m;i++){
        swap(f,nf);
        memset(nf,0,sizeof(nf));
        for(int j=0;j<=n;j++)for(int k=1;k<=n;k++)for(int l=1;l<=K;l++){
            int &cur=f[j][k][l];
            for(int p=k;p<=n-j&&l*C[p-1][k-1]<=K;p++){
                int &nxt=nf[j+p][p-k][l*C[p-1][k-1]];
                nxt=(nxt+cur)%mod;
            }
        }
        int cur=0;
        for(int j=2;j<=n;j++){
            for(int l=1;l<=K;l++){
                cur=(cur+f[j][0][l])%mod;
            }
        }
        ans=(ans+(ll)cur*(m-i+1))%mod;
    }
    cout<<ans<<'\n';

    return 0;
}