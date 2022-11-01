#include<bits/stdc++.h>
using namespace std;

const int mod=1e9+7;

int n,m,f[200005][10];

void mian(){
    cin>>n>>m;
    int ans=0;
    while(n){
        ans=(ans+f[m][n%10])%mod;
        n/=10;
    }
    cout<<ans<<'\n';
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    fill(f[0],f[0]+10,1);
    for(int i=1;i<=200000;i++){
        for(int j=0;j<9;j++){
            f[i][j]=f[i-1][j+1];
        }
        f[i][9]=(f[i-1][1]+f[i-1][0])%mod;
    }
    int T;
    cin>>T;
    while(T--)mian();

    return 0;
}