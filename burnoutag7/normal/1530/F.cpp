#include<bits/stdc++.h>
using namespace std;

const int mod=31607;

int n,u,ans=1,a[21][1<<21];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    u=(1<<n)-1;
    for(int i=0;i<n;i++){
        a[i][0]=1;
        for(int j=0,t;j<n;j++){
            cin>>t;
            a[i][1<<j]=t*3973%mod;
        }
        for(int s=1;s<=u;s++){
            a[i][s]=a[i][s&-s]*a[i][s-1&s]%mod;
        }
        for(int s=0;s<=u;s++)a[i][s]=(a[i][s]<a[i][u]?mod:0)+a[i][s]-a[i][u];
    }
    for(int dia=0;dia<4;dia++){
        for(int s=0;s<=u;s++){
            static int cur,i;
            cur=__builtin_parity(dia^s)?1:-1;
            for(i=0;i<n;i++){
                cur=cur*a[i][s|(dia&1)<<i|(dia>>1)<<n-i-1]%mod;
            }
            ans=(ans+cur)%mod;
        }
    }
    cout<<(ans%mod+mod)%mod;

    return 0;
}