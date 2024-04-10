#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,mod,f[4000005],ps;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>mod;
    for(int i=1;i<=n;i++){
        f[i+1]=(f[i+1]+f[i])%mod;
        f[i]=(ps+f[i])%mod;
        if(i==1)f[i]=1;
        for(int j=2;j*i<=n;j++){
            f[i*j]=(f[i*j]+f[i])%mod;
            if(i*j+j<=n)f[(i+1)*j]=(f[(i+1)*j]-f[i]+mod)%mod;
        }
        ps=(ps+f[i])%mod;
    }
    cout<<f[n];

    return 0;
}